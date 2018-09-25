#include "stdafx.h"
#include "defines.h"
#include "st20.h"
#include "memory.h"
#include "commands.h"
//my includes
#include "OMR.h"

extern int SearchForReg(FILE*, unsigned long); //defined in STi5518_SearchDB.h

typedef int (*fptr)(const void*, const void*);

typedef struct cmdState_struct {
  int	quit;
  int	needCmd;
  int	needPrompt;
  int   showVerboseRegs;	// for the 'vra' command
  char 	command[100];
  char 	parm1[100];
  char	parm2[100];
} CMDSTATE;

typedef struct cmdEntry_struct {
  char *command;
  int (*function)(FILE *, FILE *);
} CMDENTRY;

int u_next (FILE *, FILE *);
int u_setAreg (FILE *, FILE *);
int u_setBreg (FILE *, FILE *);
int u_setCreg (FILE *, FILE *);
int u_doError (FILE *, FILE *);
int u_setIptr (FILE *, FILE *);
int u_go (FILE *, FILE *);
int u_load (FILE *, FILE *);
int u_loadData (FILE *, FILE *);
int u_quit (FILE *, FILE *);
int u_save (FILE *, FILE *);
int u_stop (FILE *, FILE *);
int u_storeWptr (FILE *, FILE *);
int u_view(FILE *, FILE *);
int u_view_a(FILE *, FILE *);
int u_view_w(FILE *, FILE *);
int u_view_aa(FILE *, FILE *);
//////////////////////////////////////////////////////////////////////////
int u_query_db(FILE *, FILE *);	// query for register name by value
int u_showregs(FILE *, FILE *);	// show registers access when in "GO" mode
int u_showenbreg(FILE *, FILE *); //show detailed info on 'Enables' register
int u_omr(FILE *, FILE *); //show contents of OMR

static CMDSTATE cmdState;

// WARNING !!
// This array of commands MUST BE in alphabetical order
// as required by the "bsearch" function.
// so if you want to insert a new command, look carefully :)
static CMDENTRY uCommands[] = {
  {"",        u_next},
  {"a",		  u_setAreg},
  {"b",		  u_setBreg},
  {"c",		  u_setCreg},
  {"db",	  u_query_db}, //query registers database
  {"doerror", u_doError},
  {"g",		  u_go},
  {"i",		  u_setIptr},
  {"l",		  u_loadData},
  {"load",    u_load},
  {"omr",	  u_omr},			//show 'Other Machine Registers' values
  {"q",		  u_quit},
  {"s",       u_stop},
  {"save",    u_save},
  {"v",       u_view},
  {"va",      u_view_a},
  {"vaa",     u_view_aa},
  {"ver",	  u_showenbreg},	//show 'Enables' register in detail (Trap & Interrupt)
  {"vra",	  u_showregs},		//show verbose regs access (during "go" command too)
  {"vw",      u_view_w},
  {"w",		  u_storeWptr}
};

int commandsInit(PARMS *userParm, FILE *outFp) {
  initCmdState ();

  return (0);
}

int initCmdState (void) {
  cmdState.quit = FALSE;
  cmdState.needCmd = TRUE;
  cmdState.needPrompt = TRUE;
  cmdState.showVerboseRegs = FALSE;
  cmdState.command[0] = '\0';
  cmdState.parm1[0] = '\0';
  cmdState.parm2[0] = '\0';

  return (0);
}

int quitRequested (void) {
  return(cmdState.quit);
}

int setQuit (int flag) {
  cmdState.quit = flag ? TRUE : FALSE;
  return (0);
}

int needCmd (void) {
  return (cmdState.needCmd);
}

int setNeedCmd (int flag) {
  cmdState.needCmd = flag ? TRUE : FALSE;
  return (0);
}

int needPrompt (void) {
	 return (cmdState.needPrompt);
}

int showRegs(void) {
	return (cmdState.showVerboseRegs);
}

int setNeedPrompt (int flag) {
  cmdState.needPrompt = flag ? TRUE : FALSE;

  /* don't let a person run without a prompt unless a watch has been set */
  if (!cmdState.needPrompt) {
	 if (!anyWatch()) {
		cmdState.needPrompt = TRUE;
		return (NO_WATCHES_SET);
	 }
  }

  return (0);
}

int getCommand (FILE *inFp, FILE *outFp) {
  char commandLine[COMMAND_LEN];
  int  i;

  /* by default, we'll execute the doerror command */
  strcpy(cmdState.command, "doerror");
  cmdState.parm1[0] = '\0';
  cmdState.parm2[0] = '\0';

  /* print a prompt */
  fprintf (outFp, "> ");
  fflush (outFp);

  if (fgets(commandLine, COMMAND_LEN, inFp) == NULL) {
	 return (GET_COMMAND_ERROR);
  }

  if (sscanf (commandLine, "%s %s %s",
			 cmdState.command, cmdState.parm1, cmdState.parm2) < 1) {
	 cmdState.command[0] = '\0';
  }

  for (i = strlen(cmdState.command)-1; i >= 0; i--) {
	 cmdState.command[i] = tolower (cmdState.command[i]);
  }

  return (0);
}

int compareCommands (const char *cmdString, const CMDENTRY *cmdEntry) {
  return (strcmp (cmdString, cmdEntry->command));
}

int execCommand (FILE *inFp, FILE *outFp) {
  CMDENTRY *userCmd;

  /* find the user's command in the list of valid commands */
  userCmd = (CMDENTRY *) bsearch ( (void *) cmdState.command, (void *) uCommands,
									(size_t) sizeof(uCommands) / sizeof (CMDENTRY),
									(size_t) sizeof (CMDENTRY), (fptr) compareCommands );

  if (userCmd == NULL ) {
	 return (UNKNOWN_COMMAND);
  }

  return (userCmd->function(inFp, outFp));
}


int u_doError (FILE *inFp, FILE *outFp) {
  return (INPUT_ERROR);
}

/* GO */
int u_go (FILE *inFp, FILE *outFp) {
  return (setNeedPrompt(needPrompt () ? FALSE : TRUE));
}

/* LOAD */
int u_load (FILE *inFp, FILE *outFp) {
  char dirName[NAME_SIZE];
  int  result=0;

  if (sscanf (cmdState.parm1, "%s", &dirName) == 1) {
	 result = loadMemory(dirName, outFp);
  }
  else {
	 result = BAD_PARAMETER;
  }

  if (!result) {
	 result = loadCPUState(dirName, outFp);
  }
printCPUState(outFp);
  return (result);
}

/* LOAD DATA */
int u_loadData (FILE *inFp, FILE *outFp) {
  long startAddr;
  long dataLength;
  int result=0;

  /* convert the first parameter into the address to load the file to */
  if (sscanf (cmdState.parm1, "%x", &startAddr) == 1) {
	 startAddr &= 0xFFFFFFFF;
	 result = bulkLoadBytes (startAddr, cmdState.parm2, (char *) NULL, &dataLength);
	 fprintf (outFp, "Read %d bytes from %s\n", dataLength, cmdState.parm2);
  }
  else {
	 return (BAD_PARAMETER);
  }

  return (result);
}

/* NEXT */
int u_next (FILE *inFp, FILE *outFp) {
  setNeedCmd(FALSE);
  return (0);
}

/* QUIT */
int u_quit (FILE *inFp, FILE *outFp) {
  setQuit(TRUE);
  setNeedCmd(FALSE);
  return (0);
}

/* SAVE */
int u_save (FILE *inFp, FILE *outFp) {
  char dirName[NAME_SIZE];
  int  result=0;

  if (sscanf (cmdState.parm1, "%s", &dirName) == 1) {
	 result = saveMemory(dirName, outFp);
  }
  else {
	 result = BAD_PARAMETER;
  }

  if (!result) {
	 result = saveCPUState(dirName, outFp);
  }

  return (result);
}

/* setAreg */
int u_setAreg (FILE *inFp, FILE *outFp) {
  long value;

  if (sscanf (cmdState.parm1, "%x", &value) == 1) {
	 return (setAreg(value));
  }
  else {
	 return (BAD_PARAMETER);
  }
}

/* setBreg */
int u_setBreg (FILE *inFp, FILE *outFp) {
  long value;

  if (sscanf (cmdState.parm1, "%x", &value) == 1) {
	 return (setBreg(value));
  }
  else {
	 return (BAD_PARAMETER);
  }
}

/* setCreg */
int u_setCreg (FILE *inFp, FILE *outFp) {
  long value;

  if (sscanf (cmdState.parm1, "%x", &value) == 1) {
	 return (setCreg(value));
  }
  else {
	 return (BAD_PARAMETER);
  }
}

/* setIptr */
int u_setIptr (FILE *inFp, FILE *outFp) {
  long value;

  if (sscanf (cmdState.parm1, "%x", &value) == 1) {
	 return (setIptr(value));
  }
  else {
	 return (BAD_PARAMETER);
  }
}

/* stop */
int u_stop (FILE *inFp, FILE *outFp) {
  return (setWatch(cmdState.parm1, cmdState.parm2));
}


int u_storeWptr (FILE *inFp, FILE *outFp) {
  long index, value;

  if (sscanf (cmdState.parm1, "%x", &index) != 1) {
	 return (BAD_PARAMETER);
  }
  if (sscanf (cmdState.parm2, "%x", &value) != 1) {
	 return (BAD_PARAMETER);
  }
  return (storeWptrWord(index, value));
}

/* view */
int u_view (FILE *inFp, FILE *outFp) {
  int result=0;
  long address;
  long value;

  if (sscanf (cmdState.parm1, "%x", &address) != 1) {
	 return (BAD_PARAMETER);
  }

  result = readBytes (address, 4, &value);
  fprintf (outFp, "Value at 0x%08x is 0x%08x\n", address, value);

  return (result);
}

int u_view_a (FILE *inFp, FILE *outFp) {
  int result=0;
  long address;
  long value;

  if (sscanf (cmdState.parm1, "%x", &address) != 1) {
	 return (BAD_PARAMETER);
  }
  if (sscanf (cmdState.parm2, "%x", &value) != 1) {
	 return (BAD_PARAMETER);
  }
  result = storeBytes (address, 4, value);
  fprintf (outFp, "Value at 0x%08x is 0x%08x\n", address, value);

  return (result);
}

int u_view_aa (FILE *inFp, FILE *outFp) {
  int result=0;
  long address;
  long value;
  long range;
  long i;

  if (sscanf (cmdState.parm1, "%x", &address) != 1) {
	 return (BAD_PARAMETER);
  }
  if (sscanf (cmdState.parm2, "%x", &range) != 1) {
	 return (BAD_PARAMETER);
  }

for (i=address;i<(address+range);i=i+4)
	{
  result = readInvBytes (i, 4, &value);
if(!(i & 0x0f))  {fprintf (outFp, "\n\r0x%08x : %08x", i, value);}
else {fprintf (outFp, " 0x%08x",  value);}

}
fprintf (outFp, "\n\r");
  return (result);
}

int u_view_w (FILE *inFp, FILE *outFp) {
  int result=0;
  long n=0;
  long value;

  if (sscanf (cmdState.parm1, "%x", &n) != 1) {
	 return (BAD_PARAMETER);
  }
  result =  addrWptrWord(n, &value);
  fprintf (outFp, "Wptr_n is at 0x%08x\n", value);

  return (result);
}

//////////////////////////////////////////////////////////////////////////
/* QUERY REGISTER NAME BY VALUE */

int u_query_db(FILE *inFp, FILE *outFp){
	int result = 0;
	unsigned long n=0;

	if (sscanf (cmdState.parm1, "%x", &n) != 1) {
		return (BAD_PARAMETER);
	}
	
	SearchForReg(outFp,n);

	return (result);
}

//////////////////////////////////////////////////////////////////////////
/* SET THE "SHOW REGISTER ACCESS" FLAG */
//show verbose regs access (even during "go" command)
// 
int u_showregs(FILE *inFp, FILE *outFp){
	int result = 0;
	// no params required

	//flag flip-floppi'n & show status
	cmdState.showVerboseRegs =~ cmdState.showVerboseRegs;
	fprintf(outFp,"Verbose Register Access %s\n",cmdState.showVerboseRegs ? "ON" : "OFF");

	return result;
};

//////////////////////////////////////////////////////////////////////////
/* SHOW THE ENABLES REGISTER CONTENTS, BIT by BIT */
//////////////////////////////////////////////////////////////////////////
int u_showenbreg(FILE *inFp, FILE *outFp){
	int result = 0;
	// no params required
	printEnablesRegState (outFp);

	return result;
};

//////////////////////////////////////////////////////////////////////////
/* SHOW THE 'OTHER MACHINE REGISTER' CONTENTS */
//////////////////////////////////////////////////////////////////////////
int u_omr(FILE *inFp, FILE *outFp){
	int result = 0;
	// no params required
	printOMRState (outFp);

	return result;
};
char *commandError (int error) {
  switch (error) {

  case GET_COMMAND_ERROR:
		 return ("Can't read command line");
		 break;

  case INPUT_ERROR:
		 return ("Invalid input command or error reading command");
		 break;

  case BAD_PARAMETER:
		 return ("Command parameter was missing or invalid");
		 break;

  case NO_COMMAND_FILE:
		 return ("Can't read input command file");
		 break;

  case UNKNOWN_COMMAND:
		 return ("Unknown command");
		 break;

  case NO_WATCHES_SET:
		 return ("Prompting must be enabled if no watch conditions are set");
		 break;

  default:
		 return ("Unknown command error");
		 break;
  }

  return (NULL);
}
