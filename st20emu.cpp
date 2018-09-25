// st20emu.cpp : Defines the entry point for the console application.
// 16/12/11
// General fixup of the project, now can be compiled trough VC++
// Fixup of bitcnt routine (see st20.c)
// Various comments added
// Internal DB & Search Facilities added
// Now the 'g' command can be interrupted during execution, pressing the 'g' key
// Written ldclock/ldtimer/sttimer/clockenb/clockdis/gintdis/gintenb functions
// HP & LPCLockReg now are ticking at quasi-proper value
// CPU CLOCK set to 60.75Mhz

#include "stdafx.h"

#include "defines.h"
/***************************************************/
//#include "st20.h"
#define ST20_ERROR_START		-2000
#define ST20_ERROR_END			-2999

extern "C" int printNextInstr (FILE *);
extern "C" int printCPUState (FILE *);
extern "C" int decodeNextInstr(FILE *);
extern "C" long get_iptr (void);
extern "C" int execInstr (FILE *, int *);
extern "C" int st20Init (PARMS *, FILE *);
extern "C" char *st20Error (int);
/***************************************************/
//#include "memory.h"
#define MEMORY_ERROR_START		-1000
#define MEMORY_ERROR_END		-1999

extern "C" int memoryInit(PARMS *, FILE *);
extern "C" char *memoryError (int);
/***************************************************/
//#include "commands.h"
/* Error codes from commands.c */
#define COMMAND_ERROR_START	-3000
#define COMMAND_ERROR_END	-3999

extern "C" int commandsInit (PARMS *, FILE *);
extern "C" int quitRequested (void);
extern "C" int setQuit (int);
extern "C" int needCmd (void);
extern "C" int setNeedCmd (int);
extern "C" int needPrompt (void);
extern "C" int setNeedPrompt (int);
extern "C" int initCmdState (void);
extern "C" int getCommand (FILE *, FILE *);
extern "C" int execCommand (FILE *, FILE *);
extern "C" char *commandError (int);
/***************************************************/

//GLOBALS ***
long maxInstr=MAX_UNPROMPTED_INSTR;
long warnInstr=WARN_UNPROMPTED_INSTR;
long undefinedWord=UNDEFINED_WORD;
//***********
int main (int argc, char *argv[]) {
  int result=0;
  FILE *inFp, *outFp;
  int watchTripped = FALSE;
  int instrCount = 0;
  PARMS userParms;

  outFp = stdout;
  inFp = stdin;

  /* read the settings from the INI file */
  readParms(&userParms);

  st20emuInit(&userParms, outFp);
  st20Init(&userParms, outFp);
  memoryInit(&userParms, outFp);
  commandsInit(&userParms, outFp);

  fprintf (outFp, "\n");
//////////////////////////////////////////////////////////////////////////
//						EMULATOR MAIN CYCLE
// Changed do{..}while() in favour of for(;;){ if() break;}
//////////////////////////////////////////////////////////////////////////
  for(;;) {
	 /* execute the saved instruction */
	 execInstr (outFp, &watchTripped);

	 /*
	  * if the program is running without prompts, exit this state if
	  * we have executed lots of instructions and haven't encountered
	  * a watch condition or if a key has been pressed.
	  */
	 if (!needPrompt()) {
		if (++instrCount >= maxInstr) {
		  fprintf (outFp, "We've run %d instr without encountering a watch  curr iptr:%08x\n",
					  instrCount,get_iptr ());
		  setNeedPrompt (TRUE);
		}
		else if (instrCount % warnInstr == 0){
		  fprintf (outFp, "Executed %d of %d instr before next prompt  curr iptr: %08x\n",
					  instrCount,maxInstr,get_iptr() );
		}
		
		//This for interrupt the 'g' command
		//lot of cpu time spent here!!!
		if(kbhit()){if(getch()=='g') setNeedPrompt (TRUE);}
	 }

	 /* if we encountered a watch condition, enable the prompt */
	 if (watchTripped) {
		fprintf (outFp, "Watch condition encountered\n");
		setNeedPrompt (TRUE);
		watchTripped = FALSE;
	 }

	 /*
	  * print the state of the processor
	  * after executing the instruction
	  */
	 if (needPrompt()) {
		printCPUState(outFp);
	 }

	 /* get the next instruction */
	 decodeNextInstr(outFp);

	 /* print the instruction that was just read */
	 if (needPrompt()) {
		printNextInstr(outFp);

		setNeedCmd(TRUE);
		while(needCmd() && needPrompt()) {

		  /* get a command from the user and execute it */
		  if (result = getCommand(inFp, outFp)) {
			 printError (result, outFp);
		  }

		  if (result = execCommand(inFp, outFp)) {
			 printError (result, outFp);
		  }

		  /*
			* if a person wants the program to run without prompting, start
			* a counter to make sure control eventually returns to the user
			*/
		  if (!needPrompt()) {
			 instrCount = 0;
		  }
		}

		/* get the next instruction */
		decodeNextInstr(outFp);
	 }
	if(quitRequested()) break;
  }
  printf ("Finished\n\n");
  return (0);
}


int readParms (PARMS *userParms) {
  FILE *parmFp;
  char recBuf[PARM_SIZE*2];
  char firstChar[2];

  userParms->nParms = 0;

  if ((parmFp = fopen (INI_FILE, "r")) == NULL) {
	 fprintf (stderr, "Cannot open INI file %s\nUsing program defaults\n",
				 INI_FILE);
	 return (0);
  }

  while (fgets(recBuf, PARM_SIZE*2, parmFp) != NULL) {
	 /* ignore any comments */
	 if (sscanf (recBuf, "%1s", firstChar) == 1 && firstChar[0] == COMMENT)
		  continue;

	 /* ignore the line if we can't get a parameter and a value from it */
	 if (sscanf(recBuf, "%s = %s",
					userParms->parameter[userParms->nParms],
					userParms->value[userParms->nParms]) != 2){
		continue;
	 }

	 userParms->nParms++;
  }

/*
  if (1) {
	 int i=0;
	 for (i=0; i < userParms->nParms; i++) {
		fprintf (stderr, "%s=%s\n", userParms->parameter[i], userParms->value[i]);
	 }
  }
*/

  return (userParms->nParms);
}

int st20emuInit (PARMS *userParms, FILE *outFp) {
  int i;
  long value;

  for (i=0; i < userParms->nParms; i++) {

	 if (!_stricmp(userParms->parameter[i], MAX_UNPROMPTED_INSTR_CH)) {
		if (sscanf (userParms->value[i], "%ld", &value) == 1) {
		  maxInstr = value;
		}
	 }
	 else if (!_stricmp(userParms->parameter[i], WARN_UNPROMPTED_INSTR_CH)) {
		if (sscanf (userParms->value[i], "%ld", &value) == 1) {
		  warnInstr = value;
		}
	 }
	 else if (!_stricmp(userParms->parameter[i], UNDEFINED_WORD_CH)) {
		if (sscanf (userParms->value[i], "%x", &value) == 1) {
		  undefinedWord = value;
		}
	 }
  }

  fprintf (outFp, "MAX_UNPROMPTED_INSTR=%ld\nWARN_UNPROMPTED_INSTR=%ld\nUNDEFINED_WORD=0x%08x\n",
			  maxInstr, warnInstr, undefinedWord);
  return (0);
}

int printError (int error, FILE *outFp) {
  if (error <= ST20_ERROR_START && error >= ST20_ERROR_END) {
	 fprintf (outFp, "ERROR (%d) %s\n", error, st20Error (error));
  }
  else if (error <= MEMORY_ERROR_START && error >= MEMORY_ERROR_END) {
	 fprintf (outFp, "ERROR (%d) %s\n", error, memoryError (error));
  }
  else if (error <= COMMAND_ERROR_START && error >= COMMAND_ERROR_END) {
	 fprintf (outFp, "ERROR (%d) %s\n", error, commandError (error));
  }
  else {
	 fprintf (outFp, "Unknown error (%d)\n", error);
  }
  return (0);
}
