/*#include <sys/file.h>*/
#pragma warning(disable : 4996)

#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <io.h>
//#include <mem.h>
#include <direct.h>
#include "defines.h"
#include "memory.h"
#include "st20.h"

/* this structure hold the state of the memory */
typedef struct memblk_struct {
  long startAddr;
  unsigned char	data[BLKSIZE];
  unsigned char used[BLKSIZE/8];
  struct memblk_struct *next;
} MEMBLK;

/* this will hold the state of the memory */
static  MEMBLK	*memoryMap=NULL;

MEMBLK *getMemBlk (long, int);
int byteUsedBit (MEMBLK *, int, int);

int memoryInit (PARMS *userParms, FILE *outFp) {

  /* the emulator will get into an infinite loop if this initialization isn't done */
  storeBytes((long)0x3004, 4, 0);
//below for sti5518 ASC1 20005000 base
  storeBytes((long)0x20005014, 4, 0x00000000);
//below for sti5517
//  storeBytes((long)0x200130f8, 4, 0x00000001);

  return (0);
}


/**************************
 * There is one bit to flag whether a byte in the data array
 * is used or not.  used[byte 0, bit 0] indicates whether data[0]
 * is used, used[byte 1, bit 0] indicates whether data[8] is used.
 *
 * returns true if the Used bit was set for the specified byte in
 * the specified memory block before this function was called
 */
int byteUsedBit (MEMBLK *block, int offset, int usedOperation) {
  int usedByteAddr=0;
  int usedBitAddr=0;
  int usedByte=0;
  int usedBit=0;

  /* get the address of the byte's used bit */
  usedByteAddr = (offset & ADDR_IN_BLK_MASK) >> 3;
  usedBitAddr  = (offset & 7);

  /* get the state of the requested bit */
  usedByte = block->used[usedByteAddr];
  usedBit  = usedByte & (1 << usedBitAddr);

  if (usedOperation == SET_BIT) {
	 /* mark the bit as used */
	 block->used[usedByteAddr] |= (1 << usedBitAddr);
  }
  else if (usedOperation == CLEAR_BIT) {
	 /* clear the used bit */
	 block->used[usedByteAddr] &= 0xFF - (1 << usedBitAddr);
  }

  /* return 1 if the used bit was originally set */
  return (usedBit != 0);
}


/* THIS ROUTINE ISN'T NEEDED */
/**************************
 * returns true if the requested byte was defined for the
 * specified block.  *Value is the value of the requested byte.
 */
/*int readBlockByte (MEMBLK *block, int offset, unsigned char *value) {

  *value = (unsigned char) block->data[offset];
*/
  /* if the byte was stored, return true */
/*
  return (byteUsedBit(block, offset, (int) DONT_ALTER_BIT));
}
*/
/**************************
 * This function reads from one to four bytes from the proper memory block.
 *
 * Returns TRUE if the bytes were read properly.
 */

int readBytes (long address, int nBytes, long *value) {
  int i;
  MEMBLK *cBlk;
  unsigned char cByte;
  unsigned long cWord=0;
  int offset=0;

  *value = UNDEFINED_WORD;

  /* this routine won't work with anything longer than a double word */
  if (nBytes > 4) {
	 return (READ_TOO_LARGE);
  }

  /* read each of the requested bytes */
  for (i=0; i<nBytes; i++) {

	 /* get the block that the current byte is in */
	 if ((cBlk = getMemBlk (address+i, (int) FALSE)) == NULL) {
		return (READ_UNUSED_MEM);
	 }

	 /* get the offset of the byte in the block */
	 offset = (address+i) & ADDR_IN_BLK_MASK;

	 /* if the byte isn't defined, return error */
    if (!byteUsedBit(cBlk, offset, (int) DONT_ALTER_BIT)) {
		return (READ_UNUSED_MEM);
	 }

	 /* get the data byte */
	 cByte = cBlk->data[offset] & 0xFF;

	 /* build the return value from its component bytes */
	 cWord += cByte << (8*i);
  }

  *value = cWord;

  return (0);
}

int readInvBytes (long address, int nBytes, long *value) {
  int i;
  MEMBLK *cBlk;
  unsigned char cByte;
  unsigned long cWord=0;
  int offset=0;

  *value = UNDEFINED_WORD;

  /* this routine won't work with anything longer than a double word */
  if (nBytes > 4) {
	 return (READ_TOO_LARGE);
  }

  /* read each of the requested bytes */
  for (i=0; i<nBytes; i++) {

	 /* get the block that the current byte is in */
	 if ((cBlk = getMemBlk (address+i, (int) FALSE)) == NULL) {
		return (READ_UNUSED_MEM);
	 }

	 /* get the offset of the byte in the block */
	 offset = (address+i) & ADDR_IN_BLK_MASK;

	 /* if the byte isn't defined, return error */
    if (!byteUsedBit(cBlk, offset, (int) DONT_ALTER_BIT)) {
		return (READ_UNUSED_MEM);
	 }

	 /* get the data byte */
	 cByte = cBlk->data[offset] & 0xFF;

	 /* build the return value from its component bytes */
	 cWord += cByte << (8*(3-i));
  }

  *value = cWord;

  return (0);
}

/**************************
 * This function stores from one to four bytes in the proper memory block.
 *
 * Returns TRUE if the bytes were stored properly.
 */
int storeBytes (long address, int nBytes, long value) {
  int i;
  MEMBLK *cBlk;
  unsigned char cByte;
  unsigned long cWord=0;
  int offset;

  /* this routine won't work with anything longer than a double word */
  if (nBytes > 4) {
	 return (FALSE);
  }

  cWord = value;

  for (i=0; i<nBytes; i++) {

	 /* get the block that the current byte is in */
	 /* if the memory block can't be created, return an error */
	 if ((cBlk = getMemBlk (address+i, (int) TRUE)) == NULL) {
		return (READ_UNUSED_MEM);
	 }

	 /* get each of the requested bytes */
	 cByte = cWord & 0xFF;
	 cWord >>= 8;

	 /* get the offset of the byte in the block */
	 offset = (address+i) & ADDR_IN_BLK_MASK;

	 /* save the byte in the memory block */
	 cBlk->data[offset] = cByte;

	 /* mark the byte as used */
	 byteUsedBit (cBlk, offset, (int) SET_BIT);
  }

  return (0);
}

/**************************
 * This function stores from one to four bytes in the proper memory block.
 *
 * Returns TRUE if the bytes were stored properly.
 */
int storeByteRange (long srcAddr, long destAddr, int nBytes) {
  int i;
  int result=0;
  unsigned long cWord=0;

  for (i=0; i<nBytes; i++) {

	 /* get the block that the current byte is in */
	 /* if the memory block can't be created, return an error */
	 if (result = readBytes (srcAddr+i, 1, &cWord)) {
		return (result);
	 }

	 cWord &= 0xFF;

	 if (result = storeBytes (destAddr+i, 1, cWord)) {
		return (result);
	 }
  }

  return (0);
}

int allocBytes (long address, int nBytes) {
  return (storeBytes (address, nBytes, UNDEFINED_WORD));
}

/**************************
 * returns the address of the memory block containing the
 * byte with the specified address.  A new memory block is
 * created if there is no memory block with the address.
 */
MEMBLK *getMemBlk (long address, int create_flag) {
  MEMBLK	*blk=NULL;
  MEMBLK	**lastBlk=NULL;

  /* check if the necessary block already exists */
  for (lastBlk=&memoryMap; *lastBlk != NULL; lastBlk=&(*lastBlk)->next) {
	 if ((*lastBlk)->startAddr == (address & ADDR_OF_BLK_MASK)) {
		return (*lastBlk);
	 }
	 else if ((*lastBlk)->startAddr > (address & ADDR_OF_BLK_MASK)) {
		break;
	 }
  }

  /* The requested block wasn't found.
	* Return NULL if we aren't supposed to create new blocks
	*/
  if (!create_flag) {
	 return (NULL);
  }

  /* allocate memory for a new memory block */
  blk = malloc(sizeof(MEMBLK));
  memset (blk, 0, sizeof(MEMBLK));
  if (blk == NULL) {
	 return (NULL);
  }

  /* save this block in the list of blocks */
  blk->next = *lastBlk;
  *lastBlk = blk;

  /* store the starting address for this block of memory */
  blk->startAddr = address & ADDR_OF_BLK_MASK;

  /* mark the memory block as unused */
  memset (blk->used, 0, BLKSIZE/8);

  return (blk);
}

/**************************
 * stores a large number of bytes in memory blocks
 */
int bulkLoadBytes(long address, char *byteFile, char *usedFile, long *totalBytes) {
  int   i=0;
  int	  nBytesRead=0;
  int   byteFd=-1;
  int   usedFd=-1;
  long  nextAddress=address;
  char  data[BLKSIZE];
  MEMBLK	*cBlk;

  *totalBytes = 0;

  /* check the name of the byte file */
  if (byteFile == NULL || *byteFile == '\0') {
	 fprintf (stderr, "No byte filename specified\n");
	 return (INVALID_BYTE_FILENAME);
  }

  /* check if the byte file can be opened properly */
  if ((byteFd = open(byteFile, O_BINARY|O_RDONLY)) < 0)  {
	 perror ("Memory file cannot be opened");
	 return (INVALID_BYTE_FILE);
  }

  /* check the name of the used file */
  if (usedFile == NULL || *usedFile == '\0') {
	 usedFd = -1;
  }
  /* check if the used file can be opened properly */
  else if ((usedFd = open(usedFile, O_BINARY|O_RDONLY)) < 0)  {
	 perror ("Used memory file cannot be opened");
	 return (INVALID_BYTE_FILE);
  }

  /* read one block of data at a time from the input file */
  do {

	 /*
	  * since the memory blocks are allocated on BLKSIZE boundaries, we
	  * have to fill the block starting at the proper byte address within
	  * the block
	  */
	 nBytesRead = read (byteFd, &data, BLKSIZE);

	 /* if we haven't reach the end of the file's data */
	 if (nBytesRead > 0) {
		/* get the memory block to store the next block of bytes in */
		cBlk = getMemBlk (nextAddress, (int) TRUE);

		if (cBlk == NULL) {
		  fprintf (stderr, "Cannot allocate memory for byte file\n");
		  return (FAILED_MALLOC);
		}

		/* copy the data into the memory block */
		memcpy(&(cBlk->data[nextAddress & ADDR_IN_BLK_MASK]),
					 &data, (size_t) BLKSIZE - (nextAddress & ADDR_IN_BLK_MASK));

		/* if there is no used byte file, set all of the bytes to used */
		if (usedFd < 0) {
		  /* set the bits in the used array to show which bytes have been stored */
		  for (i=0; i < nBytesRead; i++) {

			 /* set the used bit for the bytes that were read */
			 byteUsedBit (cBlk, (nextAddress & ADDR_IN_BLK_MASK) + i,
											 (int) SET_BIT);
		  }
		}

		/* if there is a used byte file, load it */
		else {
		  if (read (usedFd, &(cBlk->used[(nextAddress & ADDR_IN_BLK_MASK)/8]),
						(size_t) (BLKSIZE - (nextAddress & ADDR_IN_BLK_MASK))/8) <= 0) {
			 return (INVALID_OUT_FILE);
		  }
		}
	 } /* end of if nBytesRead > 0 */

	 *totalBytes += nBytesRead;
	 nextAddress += nBytesRead;

  } while (nBytesRead > 0);

  close (byteFd);
  if (usedFd >= 0) {
	 close (usedFd);
  }

  return (0);
}

int saveMemory (char *dirName, FILE *outFp) {
  char  dataFileName[NAME_SIZE];
  int   dataFileFd=0;
  char  usedFileName[NAME_SIZE];
  int   usedFileFd=0;
  unsigned long  nextAddress=0xFFFFFFFF;
  MEMBLK	*cBlk;
  int   result=0;

  /* check the directory name */
  if (dirName == NULL || *dirName == '\0') {
	 fprintf (stderr, "No output filename specified\n");
	 return (INVALID_BYTE_FILENAME);
  }

  /* create the directory */
  if (mkdir (dirName)) {
	 return (INVALID_DIR);
  }

  for (cBlk=memoryMap; cBlk != NULL; cBlk=cBlk->next) {

	 /* omit the ROM code addresses */
/*	 if (cBlk->startAddr >= 0x7FF80000 && cBlk->startAddr <= 0x7FFFFFFF) {
		continue;
	 }
*/
	 /* omit the Wptr addresses */
/*	 if (cBlk->startAddr >= WPTR_START_ADDR && cBlk->startAddr <= WPTR_END_ADDR) {
		continue;
	 }
*/

	 /*
	  * If this memory block is contiguous with the last, append it to
	  * the last file rather than creating a new file.
	  * If not, create a new file.
	  */
	 if (cBlk->startAddr != nextAddress) {
		/* close the file if it is already open */
		if (dataFileFd) {
		  close (dataFileFd);
		}
		if (usedFileFd) {
		  close (usedFileFd);
		}

		/* create the file names */
		if (sprintf (dataFileName, "%s/%08x.bin", dirName, cBlk->startAddr) == EOF) {
		  return (INVALID_OUT_FILE);
		}
		if (sprintf (usedFileName, "%s/%08x.use", dirName, cBlk->startAddr) == EOF) {
		  return (INVALID_OUT_FILE);
		}

		/* check if the files can be opened properly */
		if ((dataFileFd = open(dataFileName,
								O_BINARY|O_WRONLY|O_CREAT|O_TRUNC,
								S_IREAD|S_IWRITE)) < 0)  {
		  perror ("Output memory file cannot be opened");
		  return (INVALID_OUT_FILE);
		}
		if ((usedFileFd = open(usedFileName,
								O_BINARY|O_WRONLY|O_CREAT|O_TRUNC,
								S_IREAD|S_IWRITE)) < 0)  {
		  perror ("Output used memory file cannot be opened");
		  return (INVALID_OUT_FILE);
		}

		nextAddress = cBlk->startAddr;
	 }

	 if (write (dataFileFd, cBlk->data, BLKSIZE) < 0) {
		return (WRITE_FAILURE);
	 }
	 if (write (usedFileFd, cBlk->used, BLKSIZE/8) < 0) {
		return (WRITE_FAILURE);
	 }
	 nextAddress += BLKSIZE;

  }
  if (dataFileFd) {
	 close (dataFileFd);
  }
  if (usedFileFd) {
	 close (usedFileFd);
  }

  return (0);
}

int loadMemory (char *dirName, FILE *outFp) {
  struct _finddata_t dirBlk;
  int    doneDir;
  char  fileMask[NAME_SIZE];
  char  byteFileName[NAME_SIZE];
  char  usedFileName[NAME_SIZE];
  char  *dotLoc;
  char  addressCh[NAME_SIZE];
  long  address;
  long  dataLength=0;
  int   result=0;

  if (sprintf (fileMask, "%s/???????0.bin", dirName) == EOF) {
	 return (INVALID_OUT_FILE);
  }

  doneDir = _findfirst(fileMask, &dirBlk);
  if (doneDir==-1) {
	 return (INVALID_OUT_FILE);
  }
  do { /* for each file */

	 /* the name contains the address to load the file at */
	 strcpy (addressCh, dirBlk.name);
	 if (sscanf (addressCh, "%8x.bin", &address) != 1) {
		return (INVALID_OUT_FILE);
	 }
//fprintf (stderr, "%s   \n",dirBlk.name);
	 /* add the directory name to the file name */
	 strcpy (byteFileName, dirName);
	 strcat (byteFileName, "/");
	 strcat (byteFileName, dirBlk.name);

	 /* build the used byte filename from the data file name */
	 strcpy (usedFileName, byteFileName);
	 dotLoc = strrchr (usedFileName, '.');
	 if (dotLoc == NULL) {
		return (INVALID_OUT_FILE);
	 }
	 /* put a null at the location of the period in the filename */
	 *dotLoc = '\0';

	 /* add the suffix for the used filename */
	 strcat (usedFileName, ".use");
fprintf (stderr, "%s   %s\n",byteFileName, usedFileName);
	 result = bulkLoadBytes (address, byteFileName, usedFileName, &dataLength);
	 if (result) {
		 _findclose(doneDir);
		return (result);
	 }



  }  while(_findnext (doneDir,&dirBlk)==0);             /* end of for each data file */
_findclose(doneDir);
  return (0);
}


char *memoryError (int error) {
  switch (error) {

  case INVALID_BYTE_FILENAME:
		 return ("The byte filename is invalid");
		 break;

  case INVALID_BYTE_FILE:
		 return ("Cannot open byte file");
		 break;

  case FAILED_MALLOC:
		 return ("Ran out of room allocating memory for byte file");
		 break;

  case READ_TOO_LARGE:
		 return ("Cannot read more than four bytes at one time");
		 break;

  case READ_UNUSED_MEM:
		 return ("An uninit memory byte was accessed ");
		 break;

  default:
		 return ("Unknown memory error");
		 break;
  }

  return (NULL);
}

