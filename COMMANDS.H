/* Error codes from commands.c */
#define COMMAND_ERROR_START		-3000
#define COMMAND_ERROR_END		-3999

#define GET_COMMAND_ERROR		-3000
#define INPUT_ERROR				-3001
#define BAD_PARAMETER 			-3002
#define NO_COMMAND_FILE			-3010
#define UNKNOWN_COMMAND			-3011
#define NO_WATCHES_SET			-3012

/*#define NUM_COMMANDS				100  */
#define COMMAND_LEN				256

int commandsInit (PARMS *, FILE *);
int quitRequested (void);
int setQuit (int);
int needCmd (void);
int setNeedCmd (int);
int needPrompt (void);
int showRegs(void);
int setNeedPrompt (int);
int initCmdState (void);
int getCommand (FILE *, FILE *);
int execCommand (FILE *, FILE *);
char *commandError (int);

