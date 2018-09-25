#define TRUE						1
#define FALSE						0

#define INI_FILE					"ST20EMU.INI"
#define COMMENT						'#'

#define MAX_UNPROMPTED_INSTR  		1000000
#define MAX_UNPROMPTED_INSTR_CH 	"MAX_UNPROMPTED_INSTR"
#define WARN_UNPROMPTED_INSTR		100000
#define WARN_UNPROMPTED_INSTR_CH	"WARN_UNPROMPTED_INSTR"

/* value to set undefined words to */
#define UNDEFINED_WORD  		0xCCCCCCCC
#define UNDEFINED_WORD_CH		"UNDEFINED_WORD"

#define NAME_SIZE						100
#define PARM_SIZE						30
#define MAX_PARMS						50

typedef struct parm_struct {
  int  nParms;
  char parameter[PARM_SIZE][MAX_PARMS];
  char value[PARM_SIZE][MAX_PARMS];
} PARMS;

int readParms (PARMS *);
int st20emuInit (PARMS *, FILE *);
int printError (int, FILE *);
extern long undefinedWord;
