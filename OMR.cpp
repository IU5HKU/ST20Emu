/* OMR stand for 'Other Machine Registers' */
//There are several other registers which the programmer should know about,
//but which are not part of the process state. See #include file
// -------------------------------------------

#include "stdafx.h"
#include "defines.h"
#include "st20.h"
#include "OMR.h"

CPUSTATE cpuState;
extern "C" long pop (void);
extern "C" int push (long value);
OMRSTATE omrState;

int initTimer(void){
	//init the fields with the current system time:
	_ftime(&omrState.ClockRegHP);
	_ftime(&omrState.ClockRegLP);
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
//Current Priority is obtained reading WDesc flag in the process descriptor
//see #include OMR.h

  if(cpuState.nWptr && 0x01){ //HighPriority
	push(omrState.ClockRegHP.time);
	fprintf (outFp, "Read of HIGH_PRIORITY timer. Value is 0x%08x\n",omrState.ClockRegHP.time);
  }
  else{						 //LowPriority
	push(omrState.ClockRegLP.time);
	fprintf (outFp, "Read of LOW_PRIORITY timer. Value is 0x%08x\n",omrState.ClockRegLP.time);
  }
  
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
	
	omrState.ClockRegHP.time = omrState.ClockRegLP.time = pop();
	fprintf (outFp, "Low and high priority clock registers were set to 0x%08x\n",
						omrState.ClockRegHP.time);

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
	
	return (0);
}

/*
clockenb clock enable
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

	return (0);
}