/* OMR include file, contains #defines and structs */
#define HIGH_PRIORITY	0
#define LOW_PRIORITY	1
#define HPTIMER_MASK	1
#define LPTIMER_MASK	2
#define ENABLE_CLOCKREG_MASK	0x00000003	//0000000....11 (first twobits)
#define DISABLE_CLOCKREG_MASK	0xFFFFFFFC	//1111111....00 (first twobits)

//Clock & Timer Related Constants
#define BASE_CLOCK			27000000	//x 9 by internal PLL = 243 MHz
#define CPU_CLOCK			60750000	//Programmable between 60 and 81 Mhz (60,75Mhz)
#define ST20SIM_CPU_CLOCK	40000000	//The default CPU Clock used by st20sim.exe by SGSThomson
#define SDRAM_CLOCK			121500000	//Programmable between 100 and 125 Mhz
#define LPM_CLOCK			212000		//212 Khz
#define LP_TIMER_TICK		(CPU_CLOCK/15625)		//15625 ticks per sec (15,625Khz), complete a cycle in 76hour
#define HP_TIMER_TICK		(CPU_CLOCK/(15625*64))  //1000000 ticks per sec (1Mhz=15625*64), complete a cycle in 60'

static long hp_timertick=HP_TIMER_TICK; //(~61 cpu cycles = 1 tick)
static long lp_timertick=LP_TIMER_TICK; //(3888 cpu cycles = 1 tick)
//static long lpm_timertick=CPU_CLOCK/LPM_CLOCK; //Low Power Module Clock (64bit!!)

typedef struct omrState{
	//unsigned long ProcQueueFPtr[0]; //high priority front pointer register
	//unsigned long ProcQueueFPtr[1]; //low priority front pointer register
	//unsigned long ProcQueueBPtr[0]; //high priority back pointer register
	//unsigned long ProcQueueBPtr[1]; //low priority back pointer register
	unsigned long ClockRegHP;		//high priority clock register (32bit 1Mhz 1hour)
	unsigned long ClockRegLP;		//low priority clock register (32bit 15,625Khz 76hours)
	//unsigned long TptrReg[0];		//high priority timer list pointer register
	//unsigned long TptrReg[1];		//low priority timer list pointer register
	//unsigned long TnextReg[0];	//high priority alarm register
	//unsigned long TnextReg[1];	//low priority alarm register
	unsigned long Enables;			//trap and global interrupt enables register
	unsigned char ClockEnables;		//start & stop the two clock register (bit 0..1)
	unsigned char HP_ErrorFlag;		//High Priority Untrapped arithmetic error flags
									//set by the processor if an integer error
									//or integer overflow error occurs and the corresponding 
									//trap is not enabled (seterr/testerr/stoperr)
	unsigned char LP_ErrorFlag;		//Low Priority Untrapped arithmetic error flags
									//set by the processor if an integer error
									//or integer overflow error occurs and the corresponding 
									//trap is not enabled (seterr/testerr/stoperr)
	unsigned char HaltOnErrorFlag;	//Halt the processor if the ErrorFlag is set
									//(sethalterr/clrhalterr/testhalterr)
} OMRSTATE;

//Function Prototypes
int ldtimer_ (FILE *, long);
int sttimer_ (FILE *, long);
int clockdis_ (FILE *, long);
int clockenb_ (FILE *, long);
int ldclock_ (FILE *, long);
int initTimer(FILE *);
/*
 - ENABLES REGISTER -
The Enables register contains:
• TrapEnables bits (0..15) which can be used to control the taking of traps;
• GlobalInterruptEnables bits (16..31) which are used to control timeslicing and
interruptibility. These are normally set to 1. (0xffffc000)
The timer will tick if the ClockEnables bit is set to1. ClockEnables can be 
set using the *clockenb* instruction and cleared using *clockdis*.

bit number full name / description
0 breakpoint trap enable bit
1 integer error trap enable bit
2 integer overflow trap enable bit
3 illegal opcode trap enable bit
4 load trap trap enable bit
5 store trap trap enable bit
6 internal channel trap enable bit
7 external channel trap enable bit
8 timer trap enable bit
9 timeslice trap enable bit
10 run trap enable bit
11 signal trap enable bit
12 process interrupt trap enable bit
13 queue empty trap enable bit							TRAPENABLES
14-15 reserved------------------------------------------ (set to 1)
16 low priority process interrupt enable bit			GLOBALINTENABLES
17 low priority timeslice enable bit
18 low priority external event enable bit
19 low priority timer alarm enable bit
20 high priority process interrupt enable bit
21 high priority timeslice enable bit
22 high priority external event enable bit
23 high priority timer alarm enable bit
31-24 reserved

* PRIORITY * (The Processor State)
The Wptr register is used for the address of the workspace of the current process.
This address is word aligned and therefore has the two least significant bits set to
zero. Wdesc is used for the ‘process descriptor’— the value that is held in memory as
an identifier of the process when the process is not being executed. This value is
composed of the top 31 bits of the Wptr plus the process priority stored in bit 0 of the
word. Bit 0 is set to 0 for high priority processes and 1 for low priority processes. Bit 1
of the process descriptor is always 0.

** The process descriptor and its associated register fields **
In order to identify a process completely it is necessary to know: its workspace
address (in which the byte selector is always 0), and its priority (high or low). This
information is contained in the process descriptor. The workspace address of the
currently executing process is held in the workspace pointer register (Wptr) and the
priority is held in the flag Priority.
Wptr points to the current process workspace, which is always word-aligned. Priority
is the priority of the currently executing process where the value 1 indicates low
priority and 0 indicates high priority.
The process descriptor is formed from a pointer to the process workspace or-ed with
the priority flag at bit 0. Bit 1 is always set to 0.
Wdesc is defined so that the following invariants are obeyed:
	Wptr = Wdesc ^ WordSelectMask
	Priority = Wdesc ^ 1
Figure
			Workspace Address			  0 Pr
	bit 31..............................2 1 0
*/

//////////////////////////////////////////////////////////////////////////
//DEFINES FOR ENABLES REGISTER
//////////////////////////////////////////////////////////////////////////
#define BREAKPOINT_TRAPENB		0x01	//bit 0
#define INTEGER_ERR_TRAPENB		0x02	//bit 1
#define INTEGER_OVF_TRAPENB		0x04	//bit 2
#define ILL_OPCODE_TRAPENB		0x08	//bit 3
#define LOADTRAP_TRAPENB		0x10	//bit 4
#define STORETRAP_TRAPENB		0x20	//bit 5
#define INTERNALCH_TRAPENB		0x40	//bit 6
#define EXTERNALCH_TRAPENB		0x80	//bit 7
#define TIMER_TRAPENB			0x100	//bit 8
#define TIMESLICE_TRAPENB		0x200	//bit 9
#define RUN_TRAPENB				0x400	//bit 10
#define SIGNAL_TRAPENB			0x800	//bit 11
#define PROCESS_TRAPENB			0x1000	//bit 12
#define QUEUE_EMPTY_TRAPENB		0x2000	//bit 13
//bits14-15 are reserved 0x3000 0x4000
#define LP_PROCESS_INT_ENB		0x8000	//bit 16
#define LP_TIMESLICE_ENB		0x10000	//bit 17
#define LP_EXTERNALEVENT_ENB	0x20000	//bit 18
#define LP_TIMER_ALRM_ENB		0x40000	//bit 19
#define HP_PROCESS_INT_ENB		0x80000	//bit 20
#define HP_TIMESLICE_ENB		0x100000//bit 21
#define HP_EXTERNALEVENT_ENB	0x200000//bit 22
#define HP_TIMER_ALRM_ENB		0x400000//bit 23
//bits24-31 are reserved

//Function Prototypes
int trapdis_(FILE *,long);
int trapenb_(FILE *,long);
int gintdis_(FILE *,long);
int gintenb_(FILE *,long);