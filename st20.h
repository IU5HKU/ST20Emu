/* this is the starting address for CPU execution */
#define START_ADDR				0x7FFFFFFE
#define START_ADDR_CH			"START_ADDR"

#define ST20_PRODUCT_ID			0x2D4C9041
#define ST20_PRODUCT_ID_CH		"ST20_PRODUCT_ID"

#define MEM_START_VAL 			0x80000140
#define MEM_START_VAL_CH		"MEM_START_VAL"

#define MINIMUM_INTEGER 		0x80000000
#define MAXIMUM_INTEGER 		0x7FFFFFFF

#define TIMER_GUESS				0x00000000
#define TIMER_GUESS_CH			"TIMER_GUESS"

#define LOW_PRIORITY			1
#define HIGH_PRIORITY			0
#define NOT_PROCESS				MINIMUM_INTEGER

/* defines for 16 bit calculations */
#define NBITS						16
#define MAX_INT						((1<<NBITS) - 1)

/*
 * I have no idea where they store the Wptr words.
 * I'll pretend that they're at WPTR_END_ADDR
 * and that they work downwards in memory
 */
#define WPTR_END_ADDR			0x1FFFFFFF
#define WPTR_END_ADDR_CH		"WPTR_END_ADDR"
#define MAX_WPTR				0x2000
#define WPTR_PRINT_COLS			4

/* we map the lddevid opcode to a special code
 * to avoid conflicts with the ldprodid code
 */
#define LDDEVID					0x200

/* Error codes from st20.c */
#define ST20_ERROR_START		-2000
#define ST20_ERROR_END			-2999

#define BAD_WPTR				-2000
#define WPTR_UNUSED				-2001
#define WPTR_UNDERFLOW			-2002
#define WPTR_OVERFLOW			-2003
#define BAD_WATCH_CONDITION 	-2004
#define INVALID_CPU_FILENAME	-2010
#define INVALID_CPU_FILE		-2011
#define INVALID_CPU_WRITE		-2012
#define INVALID_CPU_READ		-2013

typedef struct cpuState_struct {
	long areg;
	long breg;
	long creg;
	long iptr;
	long status;
	int	 nWptr;
	/*  long wptr[MAX_WPTR];*/
	char wptrUsed[MAX_WPTR];
} CPUSTATE;

typedef struct watch_struct {
	char watchAreg;
	long areg;
	char watchBreg;
	long breg;
	char watchCreg;
	long creg;
	char watchIptr;
	long iptr;
	char watchNWptr;
	int nWptr;
} WATCH;

typedef struct instrEntry_struct {
	char  *mnemonic;
	int   (*function)(FILE *, long);
	char  cpucycles;		// instruction cpu cycles 
} INSTRENTRY;

int st20Init (PARMS *, FILE *);
int initCPUState (void);
int loadCPUState (char *, FILE *);
int saveCPUState (char *, FILE *);
int printCPUState (FILE *);
int printEnablesRegState (FILE *);
int printOMRState (FILE *);
int decodeNextInstr(FILE *);
int printNextInstr (FILE *);
int execInstr (FILE *, int *);
int setAreg (long);
int setBreg (long);
int setCreg (long);
int setIptr (long);
int storeWptrWord (long, long);
int initWatch (void);
int setWatch (char *, char *);
int anyWatch(void);
int checkWatch (void);
char *st20Error (int);


int addrWptrWord (long, long *);
int wptrPopState (void);
int wptrPushState (void);
int allocWptr(long);
unsigned long N_Add(unsigned long A, unsigned long B, unsigned long *C);
long get_iptr (void);

int adc_(FILE *, long);
int add_(FILE *, long);
int ajw_(FILE *, long);
int and_(FILE *, long);
int bcnt_(FILE *, long);
int bitcnt_(FILE *, long);
int bsub_(FILE *, long);
int call_(FILE *, long);
int cj_(FILE *, long);
int devlb_(FILE *, long);
int devls_(FILE *, long);
int devlw_(FILE *, long);
int devsb_(FILE *, long);
int devss_(FILE *, long);
int devsw_(FILE *, long);
int diff_(FILE *, long);
int div_(FILE *, long);
int dup_(FILE *, long);
int eqc_(FILE *, long);
int gajw_(FILE *, long);
int gcall_(FILE *, long);
int gt_(FILE *, long);
int gtu_(FILE *, long);
int invalidOp_(FILE *, long);
int j_(FILE *, long);
int ladd_(FILE *, long);
int lb_(FILE *, long);
int lbx_(FILE *, long);
int ldc_(FILE *, long);
int lddevid_(FILE *, long);
int ldiff_(FILE *, long);
int ldiv_(FILE *, long);
int ldl_(FILE *, long);
int ldlp_(FILE *, long);
int ldmemstartval_(FILE *, long);
int ldnl_(FILE *, long);
int ldnlp_(FILE *, long);
int ldpi_(FILE *, long);
int ldpri_(FILE *, long);
int ldprodid_(FILE *, long);
int ldtimer_(FILE *, long);
int ldtraph_(FILE *, long);
int lmul_(FILE *, long);
int ls_(FILE *, long);
int lshl_(FILE *, long);
int lshr_(FILE *, long);
int lsub_(FILE *, long);
int lsum_(FILE *, long);
int mint_(FILE *, long);
int move_(FILE *, long);
int mul_(FILE *, long);
int nop_(FILE *, long);
int not_(FILE *, long);
int or_(FILE *, long);
/*********************/
int outword_(FILE *, long);
/*********************/
int pop_(FILE *, long);
int prod_(FILE *, long);
int resetch_(FILE *, long);
int ret_(FILE *, long);
int rev_(FILE *, long);
int runp_(FILE *, long);
int sb_(FILE *, long);
int shl_(FILE *, long);
int shr_(FILE *, long);
int signal_(FILE *, long);
int ss_(FILE *, long);
int ssub_(FILE *, long);
int startp_(FILE *, long);
int stclock_(FILE *, long);
int stl_(FILE *, long);
int stnl_(FILE *, long);
int stopp_(FILE *, long);
int sttimer_(FILE *, long);
int sub_(FILE *, long);
int sum_(FILE *, long);
int wait_(FILE *, long);
int wcnt_(FILE *, long);
int wsub_(FILE *, long);
int wsubdb_(FILE *, long);
int xdble_(FILE *, long);
int xor_(FILE *, long);
int xsword_(FILE *, long);

int _(FILE *, long);