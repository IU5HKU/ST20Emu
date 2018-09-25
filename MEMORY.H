#define BLKSIZE					8*1024
#define ADDR_IN_BLK_MASK		((long) (BLKSIZE-1))
#define ADDR_OF_BLK_MASK		((long) (0xFFFFFFFF - ADDR_IN_BLK_MASK))

/* Error codes from memory.c */
#define MEMORY_ERROR_START		-1000
#define MEMORY_ERROR_END		-1999

#define INVALID_BYTE_FILENAME	-1000
#define INVALID_BYTE_FILE		-1001
#define INVALID_DIR				-1002
#define INVALID_OUT_FILE		-1003
#define WRITE_FAILURE			-1004
#define FAILED_MALLOC			-1010
#define READ_TOO_LARGE			-1011
#define READ_UNUSED_MEM			-1012

/* Operations to perform on the used bit */
#define SET_BIT					1
#define CLEAR_BIT					2
#define DONT_ALTER_BIT			3

/* routines used to update the state of the memory */
int memoryInit(PARMS *, FILE *);
int readBytes(long, int, long *);
int readInvBytes(long, int, long *);
int storeBytes(long, int, long);
int allocBytes(long, int);
int storeByteRange (long, long, int);
int bulkLoadBytes(long, char *, char *, long *);
/*int readBlockByte (MEMBLK *, int, unsigned char *);  NOT NEEDED */
int saveMemory (char *, FILE *);
int loadMemory (char *, FILE *);
char *memoryError (int);
