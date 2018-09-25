/********************************************************************/
/* 16/12/2011	-Fixed 'bitcnt' instruction							*/
/*				-Added some detailed instruction comment			*/
/* 19/12/2011   -Added 'db' (query database) command				*/
/* 20/12/2011	-Added 'vra' (verbose register access) command		*/
/*				 that show info's also in 'go' mode					*/
/*				 (added a status flag into struct cmdState_struct)	*/ 
/*				-fixed some C4996 warnings about float->long and	*/
/*				 long->float. A cast has been enough.				*/
/*				-implemented binary search trough db entries		*/
/*				 and put all registers in a more suitable form		*/
/* 23/12/2011   -check all registers entries order.					*/
/*				-create Defines for 'h2idc.idc' IDA Script		    */
/*				-compiled with static libraries.					*/
/* 26/12/2011	-'g' command can be interrupted hitting the 'g' key */
/*				-added a less detailed description based upon the   */
/*				 STi5518 memory map									*/
/* 31/12/2011	-new year's eve :)									*/
/*				-added 'omr' command (OtherMachineRegisters)		*/
/*				-added 'ver' command (View Enables Register)		*/
/*				-added cpucycles quasi-precise clock				*/
/*				-added these instructions:							*/
/*					'gintenb/gintdis'								*/
/*					'trapenb/trapdis'								*/
/*					'ldclock/clockenb/clockdis'						*/
/*					'timerenb/timerdis'								*/	
/* 04/01/2012	-various bug fixed around the code					*/
/*				-emulation cycle now is better						*/
/*				-HighPriority and LowPriority ClockReg more precise */
/********************************************************************/

#include "stdafx.h"

#include "defines.h"
#include "memory.h"
#include "commands.h"
#include "st20.h"
//my new includes
#include "STi5518_SearchDB.h"	//Internal DB facility
#include "OMR.h"				//Other Machine Registers include file
static OMRSTATE omrState;		//The OMR register itself

static CPUSTATE cpuState;
static WATCH watch;
static long instrCode=0;
static long operand=(long)START_ADDR;
static unsigned char instrBytes[100];
static int instrLength=0;
static long st20ProductId=ST20_PRODUCT_ID;
static long memStartVal=MEM_START_VAL;
static long timerGuess=TIMER_GUESS;
static long startAddr=START_ADDR;
static long wptrEndAddr=WPTR_END_ADDR;

static INSTRENTRY instrEntry[] = {
/*00*/  {"j",				  j_,5},
		  {"ldlp",          ldlp_,1},
		  {"invalidop",     invalidOp_,0},
		  {"ldnl",          ldnl_,2},
		  {"ldc",           ldc_,1},
		  {"ldnlp",         ldnlp_,1},
		  {"invalidop",     invalidOp_,0},
		  {"ldl",           ldl_,1},
		  {"adc",           adc_,1},
		  {"call",          call_,8},
		  {"cj",            cj_,5},
		  {"ajw",           ajw_,2},
		  {"eqc",           eqc_,1},
		  {"stl",           stl_,1},
		  {"stnl",          stnl_,2},
		  {"invalidop",     invalidOp_,0},
/*000*/ {"rev",           rev_,1},
		  {"lb",            lb_,1},
		  {"bsub",          bsub_,1},
		  {"endp",          invalidOp_,0},
		  {"diff",          diff_,1},
		  {"add",           add_,1},
		  {"gcall",         gcall_,6},
		  {"in",            invalidOp_,0},
		  {"prod",          prod_,4},
		  {"gt",            gt_,1},
		  {"wsub",          wsub_,1},
		  {"out",           invalidOp_,0},
		  {"sub",           sub_,1},
		  {"startp",        startp_,5},
		  {"outbyte",       invalidOp_,0},
		  {"outword",       invalidOp_,0},
/*010*/ {"seterr",        invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"resetch",       resetch_,3},
		  {"csub0",         invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"stopp",         stopp_,2},
		  {"ladd",          ladd_,2},
		  {"stlb",          invalidOp_,0},
		  {"sthf",          invalidOp_,0},
		  {"norm",          invalidOp_,0},
		  {"ldiv",          ldiv_,39},	// 5 to 39
		  {"ldpi",          ldpi_,1},
		  {"stlf",          invalidOp_,0},
		  {"xdble",         xdble_,2},
		  {"ldpri",         ldpri_,1},
		  {"rem",           invalidOp_,0},
/*020*/ {"ret",           ret_,3},
		  {"lend",          invalidOp_,0},
		  {"ldtimer",       ldtimer_,1},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"testerr",       invalidOp_,0},
		  {"testpranal",    invalidOp_,0},
		  {"tin",           invalidOp_,0},
		  {"div",           div_,37}, // 5 to 37
		  {"invalidop",     invalidOp_,0},
		  {"dist",          invalidOp_,0},
		  {"disc",          invalidOp_,0},
/*030*/ {"diss",          invalidOp_,0},
		  {"lmul",          lmul_,6}, // 5 to 6
		  {"not",           not_,1},
		  {"xor",           xor_,1},
		  {"bcnt",          bcnt_,1},
		  {"lshr",          lshr_,2},
		  {"lshl",          lshl_,2},
		  {"lsum",          lsum_,2},
		  {"lsub",          lsub_,2},
		  {"runp",          runp_,3},
		  {"xword",         invalidOp_,0},
		  {"sb",            sb_,2},
		  {"gajw",          gajw_,3},
		  {"savel",         invalidOp_,0},
		  {"saveh",         invalidOp_,0},
		  {"wcnt",          wcnt_,1},
/*040*/ {"shr",           shr_,1},
		  {"shl",           shl_,1},
		  {"mint",          mint_,1},
		  {"alt",           invalidOp_,0},
		  {"altwt",         invalidOp_,0},
		  {"altend",        invalidOp_,0},
		  {"and",           and_,1},
		  {"enbt",          invalidOp_,0},
		  {"enbc",      	  invalidOp_,0},
		  {"enbs",          invalidOp_,0},
		  {"move",          move_,1}, //CPUCycles not reported in Datasheet
		  {"or",            or_,1},
		  {"csngl",         invalidOp_,0},
		  {"ccnt1",         invalidOp_,0},
		  {"talt",          invalidOp_,0},
		  {"ldiff",         ldiff_,2},
/*050*/ {"sthb",          invalidOp_,0},
		  {"taltwt",        invalidOp_,0},
		  {"sum",           sum_,1},
		  {"mul",           mul_,4},
		  {"sttimer",       sttimer_,2},
		  {"stoperr",       invalidOp_,0},
		  {"cword",         invalidOp_,0},
		  {"clrhalterr",    invalidOp_,0},
		  {"sethalterr",    invalidOp_,0},
		  {"testhalterr",   invalidOp_,0},
		  {"dup",           dup_,1},
		  {"move2dinit",    invalidOp_,0},
		  {"move2dall",     invalidOp_,0},
		  {"move2dnonzero", invalidOp_,0},
		  {"move2dzero",    invalidOp_,0},
		  {"gtu",           gtu_,1},
/*060*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"unpacksn",      invalidOp_,0},
		  {"slmul",         invalidOp_,0},
		  {"sulmul",        invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"satadd",        invalidOp_,0},
		  {"satsub",        invalidOp_,0},
		  {"satmul",        invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"postnormsn",    invalidOp_,0},
		  {"roundsn",       invalidOp_,0},
		  {"ldtraph",       ldtraph_,12},
		  {"sttraph",       invalidOp_,0},
/*070*/ {"invalidop",     invalidOp_,0},
		  {"ldinf",         invalidOp_,0},
		  {"fmul",          invalidOp_,0},
		  {"cflerr",        invalidOp_,0},
		  {"crcword",       invalidOp_,0},
		  {"crcbyte",       invalidOp_,0},
		  {"bitcnt",        bitcnt_,3},
		  {"bitrevword",    invalidOp_,0},
		  {"bitrevnbits",   invalidOp_,0},
		  {"pop",           pop_,1},
		  {"invalidop",     invalidOp_,0},
		  {"ldprodid",      ldprodid_,1},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"ldmemstartval", ldmemstartval_,1},
		  {"invalidop",     invalidOp_,0},
/*080*/ {"invalidop",     invalidOp_,0},
		  {"wsubdb",        wsubdb_,1},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*090*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"fptesterr",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*0A0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*0B0*/ {"settimeslice",  invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"xbword",        invalidOp_,0},
		  {"lbx",           lbx_,1},
		  {"cb",            invalidOp_,0},
		  {"cbu",           invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*0C0*/ {"invalidop",     invalidOp_,0},
		  {"ssub",          ssub_,1},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"intdis",        invalidOp_,0},
		  {"intenb",        invalidOp_,0},
		  {"ldtrapped",     invalidOp_,0},
		  {"cir",           invalidOp_,0},
		  {"ss",            ss_,2},
		  {"invalidop",     invalidOp_,0},
		  {"ls",            ls_,1},
		  {"sttrapped",     invalidOp_,0},
		  {"ciru",          invalidOp_,0},
		  {"gintdis",       gintdis_,5},
		  {"gintenb",       gintenb_,5},
		  {"invalidop",     invalidOp_,0},
/*0D0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*0E0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*0F0*/ {"devlb",         devlb_,3},
		  {"devsb",         devsb_,3},
		  {"devls",         devls_,3},
		  {"devss",         devss_,3},
		  {"devlw",         devlw_,3},
		  {"devsw",         devsw_,3},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"xsword",        xsword_,3},
		  {"lsx",           invalidOp_,0},
		  {"cs",            invalidOp_,0},
		  {"csu",           invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*100*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*110*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*120*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*130*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*140*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*150*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*160*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*170*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"ldprodid",      ldprodid_,1},
		  {"reboot",        invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*180*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*190*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*1A0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*1B0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"stclock",       stclock_,2},
		  {"ldclock",       ldclock_,2},
		  {"clockdis",      clockdis_,2},
		  {"clockenb",      clockenb_,2},
/*1C0*/ {"nop",           nop_,1},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*1D0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"devmove",       invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"restart",       invalidOp_,0},
		  {"causeerror",    invalidOp_,0},
/*1E0*/ {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"iret",          invalidOp_,0},
/*1F0*/ {"swapqueue",     invalidOp_,0},
		  {"swaptimer",     invalidOp_,0},
		  {"insertqueue",   invalidOp_,0},
		  {"timeslice",     invalidOp_,0},	
		  {"signal",        signal_,12},	// 7 to 12
		  {"wait",          wait_,11},		// 5 to 11
		  {"trapdis",       trapdis_,4},
		  {"trapenb",       trapenb_,4},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"tret",          invalidOp_,0},
		  {"ldshadow",      invalidOp_,0},
		  {"stshadow",      invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
		  {"invalidop",     invalidOp_,0},
/*200*/ {"lddevid",       lddevid_,1}
};


int st20Init (PARMS *userParms, FILE *outFp) {
  int i;
  long value;

  for (i=0; i < userParms->nParms; i++) {
	 if (!stricmp(userParms->parameter[i], ST20_PRODUCT_ID_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  st20ProductId = value;
		}
	 }
	 else if (!stricmp(userParms->parameter[i], MEM_START_VAL_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  memStartVal = value;
		}
	 }
	 else if (!stricmp(userParms->parameter[i], TIMER_GUESS_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  timerGuess = value;
		}
	 }
	 else if (!stricmp(userParms->parameter[i], WPTR_END_ADDR_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  wptrEndAddr = value;
		}
	 }
	 else if (!stricmp(userParms->parameter[i], START_ADDR_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  startAddr = value;
		}
	 }
  }

  fprintf (outFp, "START_ADDR=0x%08x\nMEM_START_VAL=0x%08x\nST20_PRODUCT_ID=0x%08x\n\
TIMER_GUESS=0x%08x\nWPTR_END_ADDR=0x%08x\n",
		 startAddr, memStartVal, st20ProductId, timerGuess, wptrEndAddr);

  initCPUState();
  initWatch();
  // added for timers
  initTimer(outFp);

  return (0);
}


/**************************
 * Initialize the processor
 */
int initCPUState (void) {
  int i;
  int result=0;
  long address;

  /* prepare to start the processing at 0x7FFFFFFE */
  instrCode = 0;
  operand = (long) startAddr;
  instrLength = 0;

  /* initialize the state of the processor */
  cpuState.nWptr = 7;
  cpuState.wptrUsed[0] = TRUE;
  cpuState.wptrUsed[1] = TRUE;
  cpuState.wptrUsed[2] = TRUE;
  cpuState.wptrUsed[3] = TRUE;
  cpuState.wptrUsed[4] = TRUE;
  cpuState.wptrUsed[5] = TRUE;
  cpuState.wptrUsed[6] = TRUE;
  addrWptrWord ((int) 0, &address);
  result = allocBytes (address-4*7, 4*7);
/*  cpuState.wptr[0] = UNDEFINED_WORD;*/

  for (i=7; i < MAX_WPTR; i++) {
	 cpuState.wptrUsed[i] = FALSE;
  }
  cpuState.areg = cpuState.breg = cpuState.creg = UNDEFINED_WORD;
  cpuState.iptr = 0;

  return (result);
}

int initWatch (void) {
  watch.watchAreg  = FALSE;
  watch.watchBreg  = FALSE;
  watch.watchCreg  = FALSE;
  watch.watchIptr  = FALSE;
  watch.watchNWptr = FALSE;

  return (0);
}

int saveCPUState (char *dirName, FILE *outFp) {
  char  cpuFileName[NAME_SIZE];
  int   cpuFileFd=-1;

  if (sprintf (cpuFileName, "%s/cpu.bin", dirName) == EOF) {
	 return (INVALID_CPU_FILENAME);
  }
  if ((cpuFileFd = open(cpuFileName,
								O_BINARY|O_WRONLY|O_CREAT|O_TRUNC,
								S_IREAD|S_IWRITE)) < 0)  {
	 perror ("CPU state save file cannot be opened");
	 return (INVALID_CPU_FILE);
  }

  if (write (cpuFileFd, (void *) &cpuState, sizeof (CPUSTATE)) < 0) {
	 return (INVALID_CPU_WRITE);
  }

  if (write (cpuFileFd, (void *) &wptrEndAddr, 4) < 0) {
	 return (INVALID_CPU_WRITE);
  }
  if (write (cpuFileFd, (void *) &watch, sizeof (WATCH)) < 0) {
	 return (INVALID_CPU_WRITE);
  }


  close (cpuFileFd);

  return (0);
}

long get_iptr (void) {
return(cpuState.iptr);
}

int loadCPUState (char *dirName, FILE *outFp) {
  char  cpuFileName[NAME_SIZE];
  int   cpuFileFd=-1;

  if (sprintf (cpuFileName, "%s/cpu.bin", dirName) == EOF) {
	 return (INVALID_CPU_FILENAME);
  }
  if ((cpuFileFd = open(cpuFileName,
								O_BINARY|O_RDONLY,
								S_IREAD|S_IWRITE)) < 0)  {
	 perror ("CPU state save file cannot be opened");
	 return (INVALID_CPU_FILE);
  }

  if (read (cpuFileFd, &cpuState, sizeof (CPUSTATE)) <= 0) {
	 return (INVALID_CPU_READ);
  }
  if (read (cpuFileFd, &wptrEndAddr, 4) <= 0) {
	 return (INVALID_CPU_READ);
  }

  if (read (cpuFileFd, &watch, sizeof (WATCH)) <= 0) {
	 return (INVALID_CPU_READ);
  }

  close (cpuFileFd);

  return (0);
}


int setWatch (char *reg, char *parm) {
  int  enable;
  long value;

  if (strcmpi (parm, "clear")) {
	 enable = TRUE;
  }
  else {
	 enable = FALSE;
  }
  sscanf (parm, "%x", &value);

  switch (reg[0]) {
  case 'a':
  case 'A':  watch.watchAreg = enable;
				 watch.areg = value;
				 break;

  case 'b':
  case 'B':  watch.watchBreg = enable;
				 watch.breg = value;
				 break;

  case 'c':
  case 'C':  watch.watchCreg = enable;
				 watch.creg = value;
				 break;

  case 'i':
  case 'I':  watch.watchIptr = enable;
				 watch.iptr = value;
				 break;

  case 'w':
  case 'W':  watch.watchNWptr = enable;
				 watch.nWptr = value;
				 break;

  default:   return (BAD_WATCH_CONDITION);
				 break;

  }

  return (0);
}

int anyWatch () {
  return (watch.watchAreg || watch.watchBreg || watch.watchCreg ||
			 watch.watchIptr || watch.watchNWptr);
}

int checkWatch () {
  int result=FALSE;

  result |= (int) (watch.watchAreg  && (cpuState.areg  == watch.areg));
  result |= (int) (watch.watchBreg  && (cpuState.breg  == watch.breg));
  result |= (int) (watch.watchCreg  && (cpuState.creg  == watch.creg));
  result |= (int) (watch.watchIptr  && (cpuState.iptr  == watch.iptr));
  result |= (int) (watch.watchNWptr && (cpuState.nWptr == watch.nWptr));

  return (result);
}

/**************************
 * Print the values in the processor state
 */
int printCPUState (FILE *outFp) {
  int  i;
  int result=0;
  long address;
  long value;

  fprintf (outFp, "A=0x%08x B=0x%08x C=0x%08x  Iptr=0x%08x \n",
			  cpuState.areg, cpuState.breg, cpuState.creg, cpuState.iptr);
  
  for (i=0; i < cpuState.nWptr; i++) {
	 if (i == 0) {
		fprintf (outFp, "Wptr");
	 }

	 addrWptrWord (i, &address);
	 result = readBytes (address, 4, &value);
	 fprintf (outFp, " %2x=0x%08x", i, value);

	 if (i%WPTR_PRINT_COLS == WPTR_PRINT_COLS-1) {
		fprintf (outFp, "\n    ");
	 }
  }

  fprintf (outFp, "\n\n");

  return (result);
}

/**************************
 * Print the values of the OMR
 */
int printOMRState (FILE *outFp) {
	//show the OMR Enables register
	fprintf(outFp, "OTHER MACHINE REGISTERS\n");
	fprintf(outFp, "-----------------------\n");
	fprintf(outFp, "Enables=0x%08x\n",omrState.Enables);
	fprintf(outFp, "ClockRegHP=0x%08x ",omrState.ClockRegHP);
	fprintf(outFp, "ClockRegLP=0x%08x ",omrState.ClockRegLP);
	fprintf(outFp, "ClockEnables=0x%02x \n",omrState.ClockEnables);
	fprintf(outFp, "HP_ErrFlag=0x%02x ",omrState.HP_ErrorFlag);
	fprintf(outFp, "LP_ErrFlag=0x%02x ",omrState.LP_ErrorFlag);
	fprintf(outFp, "HaltOnError=0x%02x\n",omrState.HaltOnErrorFlag);
	return(0);
}
/**************************
 * Print the values in the Enables Register
 */
int printEnablesRegState (FILE *outFp) {

	fprintf(outFp, "Enables Register Value=0x%08x\n",omrState.Enables);
	//fprintf(outFp,"-GLOBAL INTERRUPTS ENABLES VALUES-\n");
	if(omrState.Enables & LP_PROCESS_INT_ENB)
		fprintf(outFp," LP_PROCESS_INT_ENB	is set\n");
	if(omrState.Enables & LP_TIMESLICE_ENB)
		fprintf(outFp," LP_TIMESLICE_ENB	is set\n");
	if(omrState.Enables & LP_EXTERNALEVENT_ENB)
		fprintf(outFp," LP_EXTERNALEVENT_ENB	is set\n");
	if(omrState.Enables & LP_TIMER_ALRM_ENB)
		fprintf(outFp," LP_TIMER_ALRM_ENB	is set\n");
	if(omrState.Enables & HP_PROCESS_INT_ENB)
		fprintf(outFp," HP_PROCESS_INT_ENB	is set\n");
	if(omrState.Enables & HP_TIMESLICE_ENB)
		fprintf(outFp," HP_TIMESLICE_ENB	is set\n");
	if(omrState.Enables & HP_EXTERNALEVENT_ENB)
		fprintf(outFp," HP_EXTERNALEVENT_ENB	is set\n");
	if(omrState.Enables & HP_TIMER_ALRM_ENB)
		fprintf(outFp," HP_TIMER_ALRM_ENB	is set\n");
	//fprintf(outFp,"-TRAP ENABLES VALUES-\n");
	if(omrState.Enables & BREAKPOINT_TRAPENB)
		fprintf(outFp," BREAKPOINT_TRAPENB	is set\n");
	if(omrState.Enables & INTEGER_ERR_TRAPENB)
		fprintf(outFp," INTEGER_ERR_TRAPENB	is set\n");
	if(omrState.Enables & INTEGER_OVF_TRAPENB)
		fprintf(outFp," INTEGER_OVF_TRAPENB	is set\n");
	if(omrState.Enables & ILL_OPCODE_TRAPENB)
		fprintf(outFp," ILL_OPCODE_TRAPENB	is set\n");
	if(omrState.Enables & LOADTRAP_TRAPENB)
		fprintf(outFp," LOADTRAP_TRAPENB	is set\n");
	if(omrState.Enables & STORETRAP_TRAPENB)
		fprintf(outFp," STORETRAP_TRAPENB	is set\n");
	if(omrState.Enables & INTERNALCH_TRAPENB)
		fprintf(outFp," INTERNALCH_TRAPENB	is set\n");
	if(omrState.Enables & EXTERNALCH_TRAPENB)
		fprintf(outFp," EXTERNALCH_TRAPENB	is set\n");
	if(omrState.Enables & TIMER_TRAPENB)
		fprintf(outFp," TIMER_TRAPENB	is set\n");
	if(omrState.Enables & TIMESLICE_TRAPENB)
		fprintf(outFp," TIMESLICE_TRAPENB	is set\n");
	if(omrState.Enables & RUN_TRAPENB)
		fprintf(outFp," RUN_TRAPENB	is set\n");
	if(omrState.Enables & SIGNAL_TRAPENB)
		fprintf(outFp," SIGNAL_TRAPENB	is set\n");
	if(omrState.Enables & PROCESS_TRAPENB)
		fprintf(outFp," PROCESS_TRAPENB	is set\n");
	if(omrState.Enables & QUEUE_EMPTY_TRAPENB)
		fprintf(outFp," QUEUE_EMPTY_TRAPENB	is set\n");

	return (0);
}

/**************************
 * Get the bytes for the next instruction and determine what the instruction
 * code and operand are
 */
int decodeNextInstr(FILE *outFp) {
  int foundInstr=FALSE;
  unsigned long cByte;
  int result;

  instrCode = 0;
  operand = 0;
  instrLength = 0;

  /* keep reading a byte until we've found a non-prefix byte */
  while (!foundInstr) {

	 /* read the next byte of the current instruction */
	 result = readBytes (cpuState.iptr + instrLength, 1, &cByte);
	 if (result) {
		fprintf (outFp, "%s\n", memoryError (result));
		fprintf (outFp, "Error occurred when reading instruction at %8x, offset %2x\n",
					cpuState.iptr, instrLength);
		return (-1);
	 }

	 /* save the bytes that comprise the current instruction */
	 instrBytes[instrLength++] = (char) (cByte & 0xFF);

	 /* extract the data part of the current instruction byte */
	 operand <<= 4;
	 operand += cByte & 0x0F;

	 /* extract the instruction part of the current byte */
	 instrCode = cByte & 0xF0;
	 instrCode >>= 4;

	 /*
	  * The prefix encoded instructions are multi-byte instructions
	  * (either the data or the instruction is composed of multiple bytes).
	  * We have to accumulate all of the bytes in the instruction before
	  * we can determine what the instruction and the operand are.
	  */
	 switch (instrCode) {
	 case 0x02: foundInstr = FALSE;
					break;

	 case 0x06: operand = ~operand;
					foundInstr = FALSE;
					break;

	 /*
	  * All multibyte instruction codes use Fx as the final byte in the
	  * instruction.  These instructions require no operands so the
	  * operand is used as an extended instruction code.
	  * We add 0x10 to the instruction code to avoid conflicts with
	  * the opcodes from the non-extended instructions.
	  * The lddevid code will end up with the same code as ldprodid.
	  *  So we'll map it to 0x200 to avoid the conflict.
	  */
	 case 0x0F: if (operand == 0x17C) {
					  instrCode = LDDEVID;
					}
					else {
					  instrCode = (operand & 0x1FF) + 0x10;
					}

					foundInstr=TRUE;

					break;

	 /* all of the non-Fx single byte instructions are handled here */
	 default:   foundInstr=TRUE;
					break;

	 }
  }

  return (0);
}

/**************************
 * Print out the address, bytes and decoded instruction to be executed next
 */
int printNextInstr (FILE *outFp) {
  int  i;
  char operandCh[100];

  fprintf (outFp, "%08x  ", cpuState.iptr);

  for (i=0; i < instrLength; i++) {
	 fprintf (outFp, "%2x ", instrBytes[i]);
  }

  /*
	* for the jump, conditional jump and call instructions, we need to print
	* the address (i.e. iptr + operand) rather than the operand
	*/
  if (instrCode == 0x00 || instrCode == 0x0A) {
	 sprintf (operandCh, " loc_%08x",
				 (cpuState.iptr + instrLength + operand) & 0xFFFFFFFF);
  }
  else if (instrCode == 0x09) {
	 sprintf (operandCh, " sub_%08x",
				 (cpuState.iptr + instrLength + operand) & 0xFFFFFFFF);
  }
  else if (instrCode > 0x0F) {
	 operandCh[0] = '\0';
  }
  else {
	 sprintf (operandCh, " %-8x", operand & 0xFFFFFFFF);
  }

  fprintf (outFp, " %s%s\n", instrEntry[instrCode].mnemonic, operandCh);

  return (0);
}

//////////////////////////////////////////////////////////////////////////
//					EXEC DECODED INSTRUCTION
//				(Here the we tick the timers too)
//////////////////////////////////////////////////////////////////////////
int execInstr (FILE *outFp, int *breakFlag) {
  int result = 0;

  cpuState.iptr += instrLength; //update iptr

  //I've added this two statements for a cpu cycles more precise timing
  //a big overhead, i know, but in this way the timer is stopped
  //when we are in single instruction mode, without too many efforts.
  
  //*** HP_TIMER ***
  if(omrState.ClockEnables & HPTIMER_MASK) { //if the TIMER is active do:
	  if((hp_timertick-=instrEntry[instrCode].cpucycles)<=0){
		  omrState.ClockRegHP++; // tick every HP_TIMERTICK
		  hp_timertick=HP_TIMER_TICK; //reset
	  }
  }
  //*** LP_TIMER ***
  if(omrState.ClockEnables & LPTIMER_MASK){ //if the TIMER is active do:
	  if((lp_timertick-=instrEntry[instrCode].cpucycles)<=0){
		  omrState.ClockRegLP++; // tick every LP_TIMERTICK
		  lp_timertick=LP_TIMER_TICK; //reset
	  }
  }
  
  result = instrEntry[instrCode].function(outFp, operand);

  *breakFlag = checkWatch();

  return (result);
}

/**************************
 */
int readWptrWord(long index, long *value) {
  int result = 0;
  long address;

  if (index >= cpuState.nWptr) {
	 *value = 0;
	 return (BAD_WPTR);
  }
/*  if (!cpuState.wptrUsed[cpuState.nWptr - index - 1]) {
	 *value = 0;
	 return (WPTR_UNUSED);
  }

  *value = cpuState.wptr[cpuState.nWptr - index - 1];
*/
  addrWptrWord (index, &address);
  result = readBytes (address, 4, value);

  return (result);
}

/**************************
 */
int addrWptrWord (long index, long *address) {
  if (index >= cpuState.nWptr) {
	 *address = 0;
	 return (BAD_WPTR);
  }

  *address = (long) (wptrEndAddr + 1 - (cpuState.nWptr - index)*4) & 0xFFFFFFFF;

  return (0);
}

/**************************
 */
int storeWptrWord(long index, long value) {
  int result=0;
  long address;

  if (index >= cpuState.nWptr) {
	 return (BAD_WPTR);
  }

  value &= 0xFFFFFFFF;

  addrWptrWord (index, &address);
  result = storeBytes (address, 4, value);
/*  cpuState.wptr[cpuState.nWptr - index - 1] = value;*/
  cpuState.wptrUsed[cpuState.nWptr - index - 1] = TRUE;

  return (result);
}

int wptrPopState () {
  int result=0;

  readWptrWord(0, &cpuState.iptr);

  if (result = allocWptr((long)4)) {
	 return (result);
  }

  return (result);
}

int wptrPushState () {
  int result=0;

  if (result = allocWptr((long)-4)) {
	 return (result);
  }

  storeWptrWord(3, cpuState.creg);
  storeWptrWord(2, cpuState.breg);
  storeWptrWord(1, cpuState.areg);
  storeWptrWord(0, cpuState.iptr);

  return (result);
}

int allocWptr (long count) {
  int result=0;
  long address;
  int i;

  /* allocate Wptr words */
  if (count < 0) {
	 count *= -1;
	 if (count + cpuState.nWptr > MAX_WPTR) {
		count = MAX_WPTR - cpuState.nWptr;
		result = WPTR_OVERFLOW;
	 }
	 for (i=0; i < count; i++) {
		cpuState.nWptr++;
		addrWptrWord (0, &address);
		result = allocBytes (address, 4);
/*		cpuState.wptr[cpuState.nWptr++] = UNDEFINED_WORD; */
	 }
  }

  /* deallocate Wptr words */
  else if (count > 0) {
	 if (count > cpuState.nWptr) {
		count  = cpuState.nWptr;
		result = WPTR_UNDERFLOW;
	 }
	 for (i=0; i < count; i++) {
		cpuState.wptrUsed[--cpuState.nWptr] = FALSE;
	 }
  }

  return (result);
}

long pop (void) {
  long holdValue;

  holdValue = cpuState.areg;
  cpuState.areg = cpuState.breg;
  cpuState.breg = cpuState.creg;
  cpuState.creg = UNDEFINED_WORD;

  return (holdValue);
}

int push (long value) {
  cpuState.creg = cpuState.breg;
  cpuState.breg = cpuState.areg;
  cpuState.areg = value & 0xFFFFFFFF;

  return (0);
}

int setAreg (long value) {
  cpuState.areg = value & 0XFFFFFFFF;
  return (0);
}

int setBreg (long value) {
  cpuState.breg = value & 0XFFFFFFFF;
  return (0);
}

int setCreg (long value) {
  cpuState.creg = value & 0XFFFFFFFF;
  return (0);
}

int setIptr (long value) {
  cpuState.iptr = value & 0XFFFFFFFF;
  return (0);
}

char *st20Error (int error) {
  switch (error) {

  case BAD_WPTR:
		 return ("Invalid Wptr word referenced");
		 break;

  case WPTR_UNUSED:
		 return ("An uninitialized Wptr word was accessed");
		 break;

  case WPTR_UNDERFLOW:
		 return ("Too many Wptr words deallocated");
		 break;

  case WPTR_OVERFLOW:
		 return ("Ran out of room for more Wptr words");
		 break;

  case BAD_WATCH_CONDITION:
		 return ("Parameters to the watch condition were invalid");
		 break;

  default:
		 return ("Unknown st20 error");
		 break;
  }

  return (NULL);
}
  /*
	* The instrCode is used as an index to find the instrCode mnemonic and the subroutine
	* that will emulate the instruction.
	*/

int adc_ (FILE *outFp, long operand) {
  /* warning... I'm not checking for overflow */
  push (pop() + operand);

  return (0);
}

int add_ (FILE *outFp, long unused) {
  /* warning... I'm not checking for overflow */
  push (pop() + pop());

  return (0);
}

int ajw_ (FILE *outFp, long value) {
  int result;

  result = allocWptr(value);
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }
  return (0);
}

int and_ (FILE *outFp, long unused) {
  push (pop() & pop());

  return (0);
}

int bcnt_ (FILE *outFp, long unused) {
  push (pop() * 4);

  return (0);
}

/*
BITCNT (count bits set in word)
Code: 27 F6
Description: Count the number of bits set in Areg and add this to the value in Breg.
Definition:
	Areg' <- Breg + number of bits set to 1 in Areg
	Breg' <- Creg
	Creg' <- undefined
Error signals: none
*/
int bitcnt_ (FILE *outFp, long unused) {
  unsigned long  oldAreg=pop();
  unsigned long  oldBreg=pop();
  int   count=0;

  while (oldAreg){
	if(oldAreg & 0x8000) count++;
	oldAreg<<=1;
  }
   
  push (oldBreg + count);

  return (0);
}

int bsub_ (FILE *outFp, long unused) {
  push (pop() + pop());

  return (0);
}

int call_ (FILE *outFp, long offset) {
  int result;
  unsigned long addr;
  addr= cpuState.iptr;
  result = wptrPushState();
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  cpuState.areg = cpuState.iptr;
  cpuState.breg = UNDEFINED_WORD;
  cpuState.creg = UNDEFINED_WORD;
  cpuState.iptr = (cpuState.iptr + offset) & 0xFFFFFFFF;

	 fprintf (outFp, "Call to %8x ,return to %8x\n",cpuState.iptr, addr);
  return (0);
}

int cj_ (FILE *outFp, long offset) {
  if (cpuState.areg) { /* don't jump */
	 pop ();
  }
  else {
	 cpuState.iptr = (cpuState.iptr + offset) & 0xFFFFFFFF;
  }

  return (0);
}

/*
NAME: devlb (device load byte)
Code: 2F F0
Description: Perform a device read from memory, a memory-mapped device or a
peripheral. The byte addressed by Areg is read into Areg as an unsigned value.
*/
int devlb_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;
  unsigned long addr;

  //current address
  addr= get_iptr();

  oldAreg = pop();
  result = readBytes (oldAreg, 1, &newAreg);
  push (newAreg);

  if (needPrompt()||showRegs()) {
	 fprintf (outFp, "NOTE: At 0x%08x Read of device at address %08x, value=0x%08x\n",
				 addr-instrLength, oldAreg, newAreg);
	 fprintf (outFp, "Value of A register is questionable\n");

	 SearchForReg(outFp,oldAreg);
  }

  if (result && result != READ_UNUSED_MEM) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing devlb instruction\n");
	 return (-1);
  }

  return (0);
}

/*
NAME: devls (device load sixteen)
Code: 2F F2
Description: Perform a device read from memory, a memory-mapped device or a
peripheral. The 16-bit object addressed by Areg is read into Areg as an unsigned
value.
*/
int devls_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;
  unsigned long addr;

  //current address
  addr= get_iptr();

  oldAreg = pop();
  result = readBytes (oldAreg, 2, &newAreg);
  push (newAreg);

  if (needPrompt()||showRegs()) {
	  fprintf (outFp, "NOTE: At 0x%08x Read of device at address %08x, value=0x%08x\n",
		  addr-instrLength,oldAreg, newAreg);
	  fprintf (outFp, "Value of A register is questionable\n");

	  if(showRegs())SearchForReg(outFp,oldAreg);
  }

  if (result && result != READ_UNUSED_MEM) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing devls instruction\n");
	 return (-1);
  }

  return (0);
}

/*
NAME: devlw (device load word)
Code: 2F F4
Description: Perform a device read from memory, a memory-mapped device or a
peripheral. The word addressed by Areg is read into Areg.
*/
int devlw_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;
  unsigned long addr;

  //current address
  addr= get_iptr();

  oldAreg = pop();
  result = readBytes (oldAreg, 4, &newAreg);
  push (newAreg);

  if (needPrompt()||showRegs()) {
	 fprintf (outFp, "NOTE: At 0x%08x Read of device at address %08x, value=0x%08x\n",
				 addr-instrLength,oldAreg, newAreg);
	 fprintf (outFp, "Value of A register is questionable\n");

	 if(showRegs())SearchForReg(outFp,oldAreg);
  }

  if (result && result != READ_UNUSED_MEM) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing devlw instruction\n");
	 return (-1);
  }

  return (0);
}

/*
NAME: devsb (device store byte)
Code: 2F F1
Description: Perform a device write from memory, a memory-mapped device or a
peripheral. Store the least significant byte of Breg into the byte addressed by Areg.
*/
int devsb_ (FILE *outFp, long value) {
  int result;
  long value1, value2;
  unsigned long addr;
  
  //current address
  addr= get_iptr();

  value1 = pop();
  value2 = pop();
  result = storeBytes (value1, 1, (unsigned char) (value2 & 0xFF));

  if (needPrompt()||showRegs()) {
	 fprintf (outFp, "NOTE: At 0x%08x Write to device at address %08x, value=0x%08x\n",
				  addr-instrLength, value1, (unsigned char) value2 & 0xFF);
	 if(showRegs()) SearchForReg(outFp,value1);
  }
  
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 fprintf (outFp, "  Error occurred when executing devsb instruction\n");
	 return (-1);
  }

  return (0);
}

/*
NAME: devss (device store sixteen)
Code: 2F F3
Description: Perform a device write from memory, a memory-mapped device or a
peripheral. Store bits 0..5 of Breg into the sixteen bits addressed by Areg. 
*/
int devss_ (FILE *outFp, long value) {
  int result;
  long value1, value2;
  unsigned long addr;
  //current address
  addr= get_iptr();

  value1 = pop();
  value2 = pop();
  result = storeBytes (value1, 2, (unsigned int) (value2 & 0xFFFF));

  if (needPrompt()||showRegs()) {
	  fprintf (outFp, "NOTE: At 0x%08x Write to device at address %08x, value=0x%08x\n",
		  addr-instrLength, value1, (unsigned int) value2 & 0xFFFF);

	  //Search description in register database
	  if(showRegs()) SearchForReg(outFp,value1);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

/*
NAME: devsw (device store word)
Code: 2F F5
Description: Perform a device write from memory, a memory-mapped device or a
peripheral. Store Breg into the word of memory addressed by Areg. 
*/
int devsw_ (FILE *outFp, long value) {
  int result;
  long value1, value2;
  unsigned long addr;

  //current address
  addr= get_iptr();

  value1 = pop();
  value2 = pop();
  result = storeBytes (value1, 4, (unsigned long) (value2 & 0xFFFFFFFF));

  if (needPrompt()||showRegs()) {
	  fprintf (outFp, "NOTE: At 0x%08x Write to device at address %08x, value=0x%08x\n",
		  addr-instrLength, value1, (unsigned int) value2 & 0xFFFF);
	 
	  //Search description in register database
	 if(showRegs()) SearchForReg(outFp,value1);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int diff_ (FILE *outFp, long unused) {
  int value1, value2;

  value1 = pop();
  value2 = pop();

  push (value2 - value1);

  return (0);
}

int div_ (FILE *outFp, long unused) {
  int value1, value2;

  value1 = pop();
  value2 = pop();

  if (value1 == 0 || (value2 == MINIMUM_INTEGER && value1 == MAXIMUM_INTEGER)){
	 /* integer overflow */
	 return (0);
  }
  push (value2 / value1);

  return (0);
}

int dup_ (FILE *outFp, long unused) {
  long value;

  value = pop();
  push (value);
  push (value);

  return (0);
}

int eqc_ (FILE *outFp, long value) {
  long oldAreg;

  oldAreg = pop();
  if (oldAreg == (value & 0xFFFFFFFF)) {
	 push((long) TRUE);
  }
  else {
	 push((long) FALSE);
  }

  return (0);
}

int gajw_ (FILE *outFp, long unused) {
  int result;
  long oldAreg;
  long newAreg;
  int i;
  long address;

  oldAreg = pop();
  if (oldAreg & 0x03) {
	 fprintf (outFp, "WARNING: Value in A register does not point to a word boundary\n");
  }

  result = addrWptrWord(0, &newAreg);
  push(newAreg);
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }
wptrEndAddr = oldAreg+3;
  cpuState.nWptr = 1;
  cpuState.wptrUsed[0] = TRUE;

  addrWptrWord ((int) 0, &address);
  result = allocBytes (address, 4);
/*  cpuState.wptr[0] = UNDEFINED_WORD;*/

  for (i=1; i < MAX_WPTR; i++) {
         cpuState.wptrUsed[i] = FALSE;
  }
/*
  result = storeWptrWord (0, oldAreg);
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }
*/
  return (0);
}

int gcall_ (FILE *outFp, long unused) {
  long oldAreg;

  oldAreg = pop();
  push(cpuState.iptr);
  cpuState.iptr = oldAreg;

  return (0);
}

int gt_ (FILE *outFp, long unused) {
  long value1, value2;

  value1 = pop();
  value2 = pop();

  push (value2 > value1);

  return (0);
}

int gtu_ (FILE *outFp, long unused) {
  long value1, value2;

  value1 = pop();
  value2 = pop();

  push ((unsigned long) value2 > (unsigned long) value1);

  return (0);
}

int invalidOp_ (FILE *outFp, long unused) {
  fprintf (outFp, "This instruction (%s) has not been implemented yet\n",
				 instrEntry[instrCode].mnemonic);
  return (-1);
}

/*	Code: Function 0
	Description: Unconditional relative jump. The destination of the jump is expressed as
	a byte offset from the first byte after the current instruction. j 0 causes a breakpoint.
*/
int j_ (FILE *outFp, long offset) {
  pop();
  pop();
  pop();

  if (offset == 0) {
	 fprintf (outFp, "Breakpoint signalled by jump instruction\n");
  }
  else {
	 cpuState.iptr = (cpuState.iptr + offset) & 0xFFFFFFFF;
  }

  return (0);
}

/*	Code: 21 F6
	Description: Add with carry in and check for overflow. The result of the operation is
	the sum of Areg, Breg and bit 0 of Creg.
*/
int ladd_ (FILE *outFp, long unused) {
  float value1, value2;
  long value3;

	value1 = (float)pop(); //Areg
	value2 = (float)pop(); //Breg
	value3 = pop(); //Creg

	value1 = value2 + value1 + (value3 & 0x01);

	if (value1>0x7fffffff) {    push ((long)(value1-0x100000000));}
		else if(value1<0x80000000){     push ((long)(value1+0x100000000));}
			else {     push ((long)value1);}

	return (0);
}

/*	Code: F1
	Description: Load the unsigned byte addressed by Areg into Areg.
*/
int lb_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;

  oldAreg = pop();
  result = readBytes (oldAreg, 1, &newAreg);
  push (newAreg);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Read of memory address %08x, value=0x%08x\n",
				 oldAreg, newAreg);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing lb instruction\n");
	 return (-1);
  }

  return (0);
}

/*	Code: 2B F9
	Description: Load the byte addressed by Areg into Areg and sign extend to a word.
*/
int lbx_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;

  oldAreg = pop();
  result = readBytes (oldAreg, 1, &newAreg);
  if((newAreg & 0x80)==0x80) {newAreg=newAreg|0xffffff00;}
  push (newAreg);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Read of memory address %08x, value=0x%08x\n",
				 oldAreg, newAreg);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing lbx instruction\n");
	 return (-1);
  }

  return (0);
}

/*	Code: Function 4
	Description: Load constant into Areg.
*/
int ldc_ (FILE *outFp, long operand) {
  push (operand);

  return (0);
}

/*	Code: 21 27 FC
	Description: See ldprodid. This instruction may be removed in future so ldprodid
	should be used instead.
*/
int lddevid_ (FILE *outFp, long unused) {
/*  fprintf (outFp, "Product ID is unknown.  Setting A register to %x\n",
			  st20ProductId); */

  push ((long) st20ProductId);

  return (0);
}

/*	Code: 24 FF
	Description: Subtract unsigned numbers with borrow in. Subtract Areg from Breg
	minus borrow in from Creg, producing difference in Areg and borrow out in Breg,
	without checking for overflow.
*/
int ldiff_ (FILE *outFp, long unused) {
  unsigned long value1, value2, value3;
unsigned long carry,temp;
  value1 = pop();
  value2 = pop();
  value3 = pop();
carry=N_Add(value1, value3 & 0x01,&temp);
value3=value2 - temp;
if ((temp>value2) || (carry==1)){  push (1);  }
else {  push (0);  }
  push (value3);

  return (0);
}

int ldiv_ (FILE *outFp, long operand) {
  unsigned long oldAreg, oldBreg, oldCreg;
  unsigned long bl, bh;
  unsigned long hval, lval, temp;
  unsigned long rem;

  oldAreg = pop();
  oldBreg = pop();
  oldCreg = pop();

  if (oldCreg >= oldAreg) {
	 /* Overflow */
	 return -1;
  }

  bl= oldBreg & MAX_INT;
  bh= oldBreg >> NBITS;

  temp = (oldCreg % oldAreg) * (1 << NBITS) + bh;

  hval = temp / oldAreg;

  temp = (temp % oldAreg) * (1 << NBITS) + bl;

  lval = temp / oldAreg;

  rem = temp % oldAreg;

  push(rem);
  push((hval << NBITS) + lval);

  return 0;
}


int ldl_ (FILE *outFp, long index) {
  int result;
  long value;

  result = readWptrWord(index, &value);
  push (value);

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int ldlp_ (FILE *outFp, long index) {
  int result;
  long value;

  result = addrWptrWord (index, &value);
  push (value);

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int ldmemstartval_ (FILE *outFp, long unused) {
  push ((long) memStartVal);
  return (0);
}

int ldnl_ (FILE *outFp, long offset) {
  int result;
  int oldAreg;
  long cWord;

  oldAreg = pop();
  if (oldAreg & 0x03) {
	 fprintf (outFp, "WARNING: Attempt to access a word that is not on a word boundary\n");
  }

  result = readBytes (oldAreg + offset * 4, 4, &cWord);
  push (cWord);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Read of memory address %08x, value=0x%08x\n",
				 oldAreg + offset*4, cWord);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing ldnl %08x  iptr=%08x\n",oldAreg + offset * 4,get_iptr());
	 return (-1);
  }

  return (0);
}

int ldnlp_ (FILE *outFp, long offset) {
  push (pop()+ offset * 4);
  return (0);
}

int ldpi_ (FILE *outFp, long unused) {
  push (cpuState.iptr + pop());

  return (0);
}

int ldpri_ (FILE *outFp, long unused) {
  fprintf (outFp, "Priority is unknown.  Setting A register to %x\n",
			  LOW_PRIORITY);

  push ((long) LOW_PRIORITY);

  return (0);
}

int ldprodid_ (FILE *outFp, long unused) {
/*  fprintf (outFp, "Product ID is unknown.  Setting A register to %x\n",
			  st20ProductId); */

  push ((long) st20ProductId);

  return (0);
}

/*
LDTIMER (load timer)
Code: 22 F2
Description: Load the value of the current priority timer into Areg.
Definition:
	Areg4 <- ClockReg[Priority]
	Breg4 <- Areg
	Creg4 <- Breg
Error signals: none
*/

//int ldtimer_ (FILE *outFp, long unused) {
//  push(timerGuess);
//  fprintf (outFp, "Read of timer.  Assuming timer value is %x\n", timerGuess);
//
//  return (0);
//}

int ldtraph_ (FILE *outFp, long unused) {
  unsigned long oldAreg, oldBreg, oldCreg;
  unsigned long trapbase=0x80000000;
  unsigned long value;
  int result;
  oldAreg = pop();
  oldBreg = pop();
  oldCreg = pop();

  fprintf (outFp, "ldtraph: Group, &TrapHandler, priority: %x, %x,  %x\n",oldAreg, oldBreg, oldCreg );

  trapbase=trapbase+0x40+0x80*oldCreg+0x20*oldAreg;
 result = readBytes (oldBreg, 4, &value);
 result = storeByteRange(oldBreg, trapbase,  0x10);
  return (0);
}

int lmul_ (FILE *outFp, long operand) {
  unsigned long oldAreg, oldBreg, oldCreg;
  unsigned long bl, bh;
  unsigned long al, ah;
  unsigned long hval, lval, temp1, temp2, temp12;
  unsigned long carry;

  oldAreg = pop();
  oldBreg = pop();
  oldCreg = pop();

  al= oldAreg & 0xffff;
  ah= (oldAreg >> 16)  & 0xffff;

  bl= oldBreg & 0xffff;
  bh= (oldBreg >> 16)  & 0xffff;

  hval = ah * bh;
  lval = al * bl;
  temp1 = ah * bl;
  temp2 = al * bh;

carry =  N_Add(lval,oldCreg,&bl);
  hval=hval+carry;
carry =  N_Add(temp1,temp2,&temp12);
  hval=hval+(carry<<16);
carry =  N_Add((temp12<<16)&0xffff0000,bl,&al);
  hval=hval+carry;
  ah=((temp12>>16)&0xffff)+hval;

  push(ah);
  push(al);

  return 0;
}
//C= A+B with carry set if overflow
unsigned long N_Add(unsigned long A,unsigned long B, unsigned long *C)
{
   int bit0_A, bit0_B;
unsigned long t1,t2,t3,carry;
t1=A; t2=B;
t3=(t1<<31)>>31;
if (t3==0) {bit0_A=0;} else {bit0_A=1;}

t3=(t2<<31)>>31;
if (t3==0) {bit0_B=0;} else {bit0_B=1;}

t3=(t1>>1)+(t2>>1);
if ((bit0_A==1) &&(bit0_B==1)) t3++;
if ((t3>>31)==0) {carry=0;} else {carry=1;}
*C=A+B;
return (carry);

}


int ls_ (FILE *outFp, long unused) {
  int result;
  long oldAreg, newAreg;

  oldAreg = pop();
  result = readBytes (oldAreg, 2, &newAreg);
  push (newAreg);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Read of memory address %08x, value=0x%08x\n",
				 oldAreg, newAreg);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing ls instruction\n");
	 return (-1);
  }

  return (0);
}

int lshl_ (FILE *outFp, long unused) {

	unsigned long oldBreg;
	unsigned long oldCreg;
	//double  value1;
	unsigned short oldAreg;

	oldAreg=(unsigned short)pop();
	oldBreg=pop();
	oldCreg=pop();

	if(oldAreg>=32)
	  {
		  push((oldBreg<<(oldAreg-32)) & 0xffffffff);
		  push(0);
	  }
	else
	  {
		  push(((oldBreg>>(32-oldAreg))|(oldCreg<<oldAreg)) & 0xffffffff);
		  push((oldBreg<<oldAreg) & 0xffffffff);
	  }

  return (0);
}

int lshr_ (FILE *outFp, long unused) {
unsigned long oldBreg;
unsigned long oldCreg;
//double  value1;
unsigned short oldAreg;

oldAreg=(unsigned short)pop();
oldBreg=pop();
oldCreg=pop();
if(oldAreg>=32)
  {push(0);
  push((oldCreg>>(oldAreg-32)) & 0xffffffff);}
else
  {push(oldCreg>>oldAreg);
  push((oldCreg<<(32-oldAreg))|(oldBreg>>oldAreg));}

  return (0);
}

int lsub_ (FILE *outFp, long unused) {
 float value1, value2;
 long value3;

value1 = (float)pop();
value2 = (float)pop();
value3 = pop();

value1=value2 - value1-(value3 & 0x01);
if (value1>0x7fffffff) {  push ((long)(value1-0x100000000));}
	else if(value1<0x80000000){  push ((long)(value1+0x100000000));}
			else {  push ((long)value1);}

  return (0);
}

int lsum_ (FILE *outFp, long unused) {
  unsigned long value1, value2, value3;
  unsigned long carry,temp;

  value1 = pop();
  value2 = pop();
  value3 = pop();
carry=N_Add(value1,(value3&0x01),&temp);
carry=carry+N_Add(value2,temp,&value3);
if (carry>0) {  push(1);   push (value3-0xffffffff-1);}

else { push(0);    push (value3);}


  return (0);
}


int mint_ (FILE *outFp, long unused) {
  push (MINIMUM_INTEGER);

  return (0);
}

int move_ (FILE *outFp, long unused) {
  int result;
  int oldAreg, oldBreg, oldCreg;

  oldAreg = pop();
  oldBreg = pop();
  oldCreg = pop();

  result = storeByteRange(oldCreg, oldBreg, (int) oldAreg);

  fprintf (outFp,
			  "NOTE: Copy of %x bytes from address %08x to address %08x\n",
			  oldAreg, oldCreg, oldBreg);

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", memoryError(result));
	 fprintf (outFp, "  Error occurred when executing move instruction\n");
	 return (-1);
  }

  return (0);
}

int mul_ (FILE *outFp, long unused) {
  /* WARNING: no checking for overflow */
  push (pop() * pop ());

  return (0);
}

int nop_ (FILE *outFp, long unused) {
  return (0);
}

int not_ (FILE *outFp, long unused) {
  push (~pop());

  return (0);
}

int or_ (FILE *outFp, long unused) {
  push (pop() | pop ());

  return (0);
}

int pop_ (FILE *outFp, long unused) {
  pop();

  return (0);
}

int prod_ (FILE *outFp, long unused) {
  push (pop() * pop());

  return (0);
}

int resetch_ (FILE *outFp, long unused) {
  int result=0;
  long oldAreg, newAreg;

  oldAreg = pop();

  if (oldAreg & 0x03) {
	 fprintf (outFp, "WARNING: Attempt to access a word that is not on a word boundary\n");
  }

  result = readBytes (oldAreg, 4, &newAreg);
  push (newAreg);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Read of memory address %08x, value=0x%08x\n",
				 oldAreg, newAreg);
  }

  result = storeBytes (oldAreg, 4, (long) NOT_PROCESS);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Write memory address %08x, value=0x%08x\n",
				 oldAreg, MINIMUM_INTEGER);
  }

  fprintf (outFp, "Channel at address %08x was reset\n", oldAreg);

  return (result);
}

int ret_ (FILE *outFp, long unused) {
  int result;

  result = wptrPopState();
  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int rev_ (FILE *outFp, long unused) {
  int result=0;
  long oldAreg, oldBreg;

  oldAreg = pop();
  oldBreg = pop();

  push (oldAreg);
  push (oldBreg);

  return (result);
}

int runp_ (FILE *outFp, long unused) {
  int result=0;
  long oldAreg;

  oldAreg = pop();
  pop();
  pop();

  fprintf (outFp, "A new process was started.  Process descriptor =0x%08x\n",
	oldAreg);

  return (result);
}

int sb_ (FILE *outFp, long value) {
  int result;
  long value1, value2;

  value1 = pop();
  value2 = pop();
  result = storeBytes (value1, 1, (unsigned char) (value2 & 0xFF));

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Write to memory address %08x, value=0x%08x\n",
				 value1, value2 & 0xFF);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int shl_ (FILE *outFp, long unused) {
  long value;
  long nbits;

  nbits = pop();
  value = pop();
  push (value << nbits);

  return (0);
}

int shr_ (FILE *outFp, long unused) {
  unsigned long value;
  long nbits;

  nbits = pop();
  value = pop();
  push (value >> nbits);

  return (0);
}

int signal_ (FILE *outFp, long unused) {
  int result=0;
  long oldAreg;

  oldAreg = pop();
  pop();
  pop();

  if (needPrompt()) {
	 fprintf (outFp, "A signal was received for address 0x%08x\n", oldAreg);
  }

  return (result);
}

int ss_ (FILE *outFp, long value) {
  int result;
  long value1, value2;

  value1 = pop();
  value2 = pop();
  result = storeBytes (value1, 2, (unsigned) (value2 & 0xFFFF));

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Write to memory address %08x, value=0x%08x\n",
				 value1, value2 & 0xFFFF);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int ssub_ (FILE *outFp, long unused) {
  long oldAreg;
  long oldBreg;

  oldAreg = pop();
  oldBreg = pop();

  push (oldAreg + oldBreg*2);

  return (0);
}

int startp_ (FILE *outFp, long unused) {
  //int result;
  long oldAreg, oldBreg;

  oldAreg = pop();
  oldBreg = pop();
  pop();

  fprintf (outFp, "A new process was started.  Workspace=0x%08x, Iptr=0x%08x\n",
	oldAreg, cpuState.iptr+oldBreg);

  return (0);
}

/*
STCLOCK (store clock register)
Code: 64 FC
Description: Store the contents of Breg into the clock register of priority Areg.
Definition:
	ClockReg[Areg] <- Breg
	Areg' <- Creg
	Breg' <- undefined
	Creg' <- undefined
Error signals: none
*/

int stclock_ (FILE *outFp, long unused) {
  long oldAreg;
  long oldBreg;

  oldAreg = pop();
  oldBreg = pop();

  fprintf (outFp, "0x%08x stored in %s clock\n",
           oldBreg, (oldAreg & 1) ? "low priority" : "high priority");

  if(oldAreg & 1) omrState.ClockRegLP=oldBreg;
	else omrState.ClockRegHP=oldBreg;
  
  //omrState.Enables|=HPTIMER_MASK; // set bit0
  //omrState.Enables|=LPTIMER_MASK; // set bit1

  //AND NOW CLOCKS MUST START TICKING!!! But how can i do it?!
  //check 'Enables' flag....

  return (0);
}

int stl_ (FILE *outFp, long index) {
  int result;

  result = storeWptrWord (index, pop());

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

/*
Code: Function 0x0E
Description: Store the contents of Breg into the non-local variable at the specified
			 word offset from Areg.
*/
int stnl_ (FILE *outFp, long offset) {
  int result;
  int oldAreg, oldBreg;

  oldAreg = pop();
  oldBreg = pop();

  result = storeBytes (oldAreg + offset*4, 4, oldBreg);

  if (needPrompt()) {
	 fprintf (outFp, "NOTE: Write to memory address %08x, value=0x%08x\n",
				  oldAreg + offset*4, oldBreg);
  }

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}

int stopp_ (FILE *outFp, long unused) {
  pop();
  pop();
  pop();

  fprintf (outFp, "This process has been terminated\n");

  return (0);
}

/*
STTIMER (store timer)
Code: 25 F4
Description: Initialize the timers. Set the low and high priority clock registers to the
value in Areg and start them ticking and scheduling ready processes.
Definition:
	Clockreg'[0] <- Areg
	Clockreg'[1] <- Areg
	Start timers

	Areg' <- Breg
	Breg' <- Creg
	Creg' <- undefined
Error signals: none
*/

//int sttimer_ (FILE *outFp, long unused) {
//  fprintf (outFp, "Low and high priority clock registers were set to 0x%08x\n",
//						pop());
//
//  return (0);
//}

int sub_ (FILE *outFp, long unused) {
  long value1;
  long value2;

  value1 = pop();
  value2 = pop();

  /* warning... I'm not checking for overflow */
  push (value2 - value1);

  return (0);
}

int sum_ (FILE *outFp, long unused) {
  push (pop() + pop());

  return (0);
}

int wait_ (FILE *outFp, long unused) {
  long oldAreg;

  oldAreg = pop();
  pop();
  pop();

  if (needPrompt()) {
	 fprintf (outFp, "Wait on semaphore at 0x%08x\n", oldAreg);
  }

  return (0);
}

int wcnt_ (FILE *outFp, long unused) {
  //long value1, value2;
  long value1;

  value1 = pop();
  push (value1 & 0x3);
  push ((value1 & 0xfffffffc) / 4);

  return (0);
}

int wsub_ (FILE *outFp, long unused) {
  long value1, value2;

  value1 = pop();
  value2 = pop();

  push (value1 + value2 * 4);

  return (0);
}


int wsubdb_ (FILE *outFp, long unused) {
  long value1, value2;

  value1 = pop();
  value2 = pop();

  push (value1 + value2 * 8);

  return (0);
}

int xdble_ (FILE *outFp, long unused) {
  long value1;

  value1 = pop();
	if(value1>=0) push(0); else push(-1);

  push (value1);

  return (0);
}

int xor_ (FILE *outFp, long unused) {
  push (pop() ^ pop ());

  return (0);
}

int xsword_ (FILE *outFp, long unused) {
  long value1;

  value1 = pop();
	if((value1 & 0x8000)==0x8000) value1=value1|0xffff0000;

  push (value1);

  return (0);
}

/*
int _ (FILE *outFp, long value) {
  int result;

  if (result) {
	 fprintf (outFp, "ERROR: %s\n", st20Error(result));
	 return (-1);
  }

  return (0);
}
*/

//////////////////////////////////////////////////////////////////////////
//				TIMER RELATED FUNCTIONS
//////////////////////////////////////////////////////////////////////////
 
int initTimer(FILE *outFp){
	//init the timer fields:
	omrState.ClockRegHP=TIMER_GUESS;
	omrState.ClockRegLP=TIMER_GUESS;
	omrState.ClockEnables|=HPTIMER_MASK; //set bit0 
	omrState.ClockEnables|=LPTIMER_MASK; //set bit1 
	omrState.Enables=0xffffc000;	//the initial state, see omr.h
									//bit 14 and 15 are reserved but set to 1
		//'ticking' code is into execInstr() subroutine
	fprintf(outFp,"CPU_CLOCK=%d Hz\n HPTimerTick=%d cpucycles\n LPTimerTick=%d cpucycles\n",
		CPU_CLOCK,
		hp_timertick,
		lp_timertick);

	return (0);
}

/*
LDTIMER (load timer)
Code: 22 F2
Description: Load the value of the current priority timer into Areg.
Definition:
	Areg' <- ClockReg[Priority]
	Breg' <- Areg
	Creg' <- Breg
Error signals: none
*/

int ldtimer_ (FILE *outFp, long unused) {
////Current Priority is obtained reading WDesc flag in the process descriptor
////see #include OMR.h

  if(cpuState.nWptr & 0x01){ //HighPriority
	push(omrState.ClockRegHP);
	fprintf (outFp, "Read of HIGH_PRIORITY timer. Value is 0x%08x\n",omrState.ClockRegHP);
  }
  else{						 //LowPriority
	push(omrState.ClockRegLP);
	fprintf (outFp, "Read of LOW_PRIORITY timer. Value is 0x%08x\n",omrState.ClockRegLP);
  }
  	//'ticking' code is into execInstr() subroutine
  return (0);
}

/*
STTIMER (store timer)
Code: 25 F4
Description: Initialize the timers. Set the low and high priority clock registers to the
value in Areg and start them ticking and scheduling ready processes.
Definition:
	Clockreg'[0] <- Areg
	Clockreg'[1] <- Areg
	Start timers

	Areg' <- Breg
	Breg' <- Creg
	Creg' <- undefined
Error signals: none
*/

int sttimer_ (FILE *outFp, long unused) {
	
	omrState.ClockRegHP = omrState.ClockRegLP = pop();
	fprintf (outFp, "LOW and HIGH priority clock registers were set to 0x%08x\n",
						omrState.ClockRegHP);

	omrState.ClockEnables|=HPTIMER_MASK; // set bit0
	omrState.ClockEnables|=LPTIMER_MASK; // set bit1

	//'ticking' code is into execInstr() subroutine
	
  return (0);
}

/*
CLOCKDIS (clock disable)
Code: 64 FE
Description: Stops the clocks specified in bits 0 and 1 of Areg where bit 0
indicates the high priority clock and bit 1 the low priority clock. The 
original values of these two clock enable bits are returned in Areg.
Definition:
	Areg' 1..0 <- ClockEnables
	Areg' 31..2 <- 0
	ClockEnables' <- ClockEnables ^ ~Areg
Error signals: none
*/

int clockdis_ (FILE *outFp, long unused) {
	
	long oldAreg=pop();
	long oldClockEnables=omrState.ClockEnables;

	if(oldAreg & HPTIMER_MASK) omrState.ClockEnables&=~HPTIMER_MASK; //clear bit0
	if(oldAreg & LPTIMER_MASK) omrState.ClockEnables&=~LPTIMER_MASK; //clear bit1

	push(oldClockEnables &= 0x03); //bit 0.1 leaved unchanged. others are zero'ed
		//'ticking' code is into execInstr() subroutine
	return (0);
}



/*
CLOCKENB (clock enable)
Code: 64 FF
Description: Starts or restarts the clocks specified in bits 0 and 1 of Areg, 
where bit 0 indicates the high priority clock and bit 1 indicates the low 
priority clock. The original values of these two clock enable bits are 
returned in Areg.
Definition:
	Areg' 1..0 <- ClockEnables
	Areg' 31..2 <- 0
	ClockEnables' <- ClockEnables ! Areg
Error signals: none
*/

int clockenb_ (FILE *outFp, long unused) {

	long oldAreg=pop();
	long oldClockEnables=omrState.ClockEnables;

	if(oldAreg & HPTIMER_MASK) omrState.ClockEnables|=HPTIMER_MASK; //set bit0 
	if(oldAreg & LPTIMER_MASK) omrState.ClockEnables|=LPTIMER_MASK; //set bit1 

	push(oldClockEnables &= 0x03);//bit 0.1 leaved unchanged. others are zero'ed
		//'ticking' code is into execInstr() subroutine
	return (0);
}

/*
LDCLOCK (load clock)
Code: 64 FD
Description: Load into Areg the current value of ClockReg, of the priority selected
by Areg, where 0 indicates high priority and 1 indicates low priority.
Definition:
	Areg' <- ClockReg[Areg]
Error signals: none
 */
int ldclock_ (FILE *outFp, long unused) {
	long oldAreg;

	oldAreg = pop();

	fprintf (outFp, "Areg loaded with %s clock\n",
			 (oldAreg & 1) ? "LOW_PRIORITY" : "HIGH_PRIORITY");

	if(oldAreg & 1) push(omrState.ClockRegLP);
	else push(omrState.ClockRegHP);

	//'ticking' code is into execInstr() subroutine

	return (0);
}

//////////////////////////////////////////////////////////////////////////
//				TRAP RELATED FUNCTIONS
//////////////////////////////////////////////////////////////////////////
/*
TRAPDIS (trap disable)
Code: 60 F6
Description: Disable those traps selected by the mask in Areg at the priority
			 selected by Breg, where 0 indicates high priority and 1 indicates low priority. 
			 The original value of TrapEnables is returned in Areg.
Definition:
	TrapEnables'[Breg] <- TrapEnables[Breg] ^ ~Areg
	Areg'13..0 <- TrapEnables[Breg]
	Areg'31..14 <- 0
	Breg' <- undefined
	Creg' <- undefined
Error signals: none
*/
int trapdis_ (FILE *outFp, long unused) {
	long Areg = pop();	//traps mask
	long Breg = pop();	//priority
	long oldEnables=omrState.Enables; //old Enables Status

	Areg&=0x3fff; //consider only bit 0..13
	omrState.Enables &= ~Areg;
	push(oldEnables & 0x3fff); //return old status in Areg

	return (0);
}

/*
TRAPENB (trap enable)
Code: 60 F7
Description: Enable those traps selected by the mask in Areg at the priority selected
			 by Breg, where 0 indicates high priority and 1 indicates low priority. 
			 The original value	of TrapEnables is returned in Areg.
Definition:
	TrapEnables'[Breg] <- TrapEnables[Breg] ! Areg
	Areg'13..0 <- TrapEnables[Breg]
	Areg'31..14 <- 0
	Breg' <- undefined
	Creg' <- undefined
Error signals: none
*/
int trapenb_ (FILE *outFp, long unused) {
	long Areg = pop();	//traps mask
	long Breg = pop();	//priority
	long oldEnables=omrState.Enables; //old Enables Status

	Areg&=0x3fff; //consider only bit 0..13
	omrState.Enables |= Areg;
	
	push(oldEnables & 0x3fff); //return old status in Areg

	return (0);
}

/*
GINTDIS (global interrupt disable)
Code: 2C FD
Description: Disable the global interrupt events specified in the bit mask in Areg.
This allows parts of the built-in scheduler, such as response to external events,
timeslicing etc., to be disabled by software. The original value of the global interrupt
enable register is returned in Areg.
Definition:
	GlobalInterruptEnables' <- GlobalInterruptEnables ^ ~Areg7..0
	Areg'7..0 <- GlobalInterruptEnables
	Areg'31..8 <- 0
Error signals: none
*/
int gintdis_ (FILE *outFp, long unused) {
	long Areg = pop();	//global intr events mask
	long oldEnables=omrState.Enables; //old Enables Status
	
	Areg &=0xff; //CONSIDER ONLY BIT 7..0
	omrState.Enables &= ~Areg;

	oldEnables&=0x3fc000; //consider only bit 16..23
	push(oldEnables<<16); //return old status in Areg

	return (0);
}

/*
GINTENB (global interrupt enable)
Code: 2C FE
Description: Enable the global interrupt events specified in the bit mask in Areg.
Definition:
	GlobalInterruptEnables' <- GlobalInterruptEnables ! Areg7..0
	Areg'7..0 <- GlobalInterruptEnables
	Areg'8..31 <- 0
Error signals: none
*/
int gintenb_ (FILE *outFp, long unused) {
	long Areg = pop();	//global intr events mask
	long oldEnables=omrState.Enables; //old Enables Status

	Areg &=0xff; //CONSIDER ONLY BIT 7..0
	omrState.Enables |= Areg;

	oldEnables&=0x3fc000; //consider only bit 16..23
	push(oldEnables<<16); //return old status in Areg

	return (0);
}