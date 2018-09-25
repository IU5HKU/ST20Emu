//////////////////////////////////////////////////////////////////////////
// 16/12/2011 MrCODE
// Method for a more descriptive system added to "st20emu2.exe"
//////////////////////////////////////////////////////////////////////////

#include <stdlib.h> //this for bsearch()
#include "STi5518_RegisterDB.h"
#include "STi5518_Region0.h"

//////////////////////////////////////////////////////////////////////////
typedef int (*fptr)(const void*, const void*);
//////////////////////////////////////////////////////////////////////////
int compareRegs (const unsigned long *reg, const REGDESCR *regdescr) {
	return(*reg-regdescr->addr);
}
//////////////////////////////////////////////////////////////////////////
int SearchForReg(FILE* outFp, unsigned long reg){
	char found=FALSE,recogn=FALSE;
	int i;
	REGDESCR* regdescr;

	/*FIRST THING FIRST. Check in what memory range we are*/
	if(reg<=0xc0800000 && reg>=0xc0000000) //Shared SDRAM
		fprintf(outFp,"DESCR: Address is into Shared SDRAM (Region 1)\n");
	if(reg<=0x80001800 && reg>=0x80001000) //2Kb SRAM
		fprintf(outFp,"DESCR: Internal SRAM if data cache is not enabled.User-code, data and stack (Region 0)\n");
	if(reg<=0x80000fff && reg>=0x80000000) {//4Kb SRAM
	
		for(i=0;i<=(sizeof(REG0_Entry)/sizeof(REG0DESCR));i++){
			if(reg>=REG0_Entry[i].lbaddr && reg<=REG0_Entry[i].hbaddr){
				fprintf(outFp,"DESCR: %s\n",REG0_Entry[i].description);
				recogn=TRUE;break;
			}
		}

		if(!recogn) fprintf(outFp,"DESCR: Address is into 4Kbyte SRAM (Region 0)\n");
	
	};
	if(reg<=0x7fffffff && reg>=0x70000000) //EMI Bank 3
		fprintf(outFp,"DESCR: Address is into EMI BANK 3 (Region 3)\n");
	if(reg<=0x6fffffff && reg>=0x60000000) //EMI Bank 2
		fprintf(outFp,"DESCR: Address is into EMI BANK 2 (Region 3)\n");
	if(reg<=0x5fffffff && reg>=0x50000000) //EMI Bank 1
		fprintf(outFp,"DESCR: Address is into EMI BANK 1 (Region 3)\n");
	if(reg<=0x4fffffff && reg>=0x40000000) //EMI Bank 0
		fprintf(outFp,"DESCR: Address is into EMI BANK 0 (Region 3)\n");
	if(reg<=0x3fffffff && reg>=0x20040000) //Reserved
		fprintf(outFp,"DESCR: Address is into Reserved Memory Area(Region 2)\n");
	
	if(reg<=0x2003ffff) //Peripheral configuration registers (Region 2)
	{
		/* find the description in the register database */
		regdescr = (REGDESCR *) bsearch ( (void *) &reg, (void *) DBREGS_Entry,
			(size_t) sizeof(DBREGS_Entry) / sizeof (REGDESCR),
			(size_t) sizeof (REGDESCR), (fptr) compareRegs );

		if (regdescr == NULL ) {
			fprintf(outFp,"Sorry, no match for 0x%08x in Registers DB\n",reg);
			found = FALSE;
		}
		else
		{
			//printout of info's
			fprintf (outFp, "REGN: %s bits:%d access:%s\nDESC: %s\n",
				regdescr->regname,
				regdescr->bits,
				regdescr->access,
				regdescr->description
				);
			found=TRUE;
		}
	}

	return found;
}
//////////////////////////////////////////////////////////////////////////