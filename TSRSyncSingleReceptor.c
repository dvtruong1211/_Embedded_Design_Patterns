/**
 ******************************************************************************
 * @file    TSRSyncSingleReceptor.c
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


/*******************************************************************************
 * Include
 ******************************************************************************/
#include "TSRSyncSingleReceptor.h"
#include "Mutex.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


 /*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/

void TSSR_eventDispatch(TokenizerSyncSingleReceptor*const me, Event e) 
{
	Mutex_lock(me->itsMutex);
	switch (e.eType) 
	{
		case EVDIGIT:
		{
			switch (me->stateID) 
			{
				case NONUMBER_STATE:
				/* transition to GotNumber state, default substate */
					TokenizerSyncSingleReceptor_exit_NoNumber(me);
					me->ch = e.ed.c;
					TokenizerSyncSingleReceptor_enter_GotNumber(me);
					me->stateID = GOTNUMBER_STATE;
					TokenizerSyncSingleReceptor_enter_ProcessingWholePart(me);
					me->subStateID = PROCESSINGWHOLEPART_SSTATE;
					printf("Current value of result: %g\n", me->result);
					break;
				case GOTNUMBER_STATE:
				switch (me->subStateID) 
				{
					case PROCESSINGWHOLEPART_SSTATE:
						TokenizerSyncSingleReceptor_exit_ProcessingWholePart(me);
						me->ch = e.ed.c;
						TokenizerSyncSingleReceptor_enter_ProcessingWholePart(me);
						printf("Current value of result: %g\n", me->result);
						break;
					case PROCESSINGFRACTIONALPART_SSTATE:
						TokenizerSyncSingleReceptor_exit_ProcessingFractionalPart(me);
						me->ch = e.ed.c;
						me->result += digit(me->ch) / me->tensPlace;
						me->tensPlace *= 10.0;
						TokenizerSyncSingleReceptor_enter_ProcessingFractionalPart(me);
						printf("Current value of result: %g\n", me->result);
						break;
				};
			};
		break;
		}
		case EVDOT:
		{
			me->ch = ’.’;
			286 Chapter 5
			switch (me->stateID) 
			{
				case NONUMBER_STATE:
					/* transition to GotNumber state, default substate */
					TokenizerSyncSingleReceptor_exit_NoNumber(me);
					TokenizerSyncSingleReceptor_enter_GotNumber(me);
					me->stateID = GOTNUMBER_STATE;
					TokenizerSyncSingleReceptor_enter_ProcessingFractionalPart(me);
					me->subStateID = PROCESSINGFRACTIONALPART_SSTATE;
					break;
				case GOTNUMBER_STATE:
					switch (me->subStateID) 
					{
					case PROCESSINGWHOLEPART_SSTATE:
						TokenizerSyncSingleReceptor_exit_ProcessingWholePart(me);
						TokenizerSyncSingleReceptor_enter_ProcessingFractionalPart(me);
						me->subStateID = PROCESSINGFRACTIONALPART_SSTATE;
						break;
					};
			};
			break;
		}
		case EVWHITESPACE:
		{
			/* Do something... */
		}
		case EVENDOFSTRING:
		{
			switch (me->stateID) 
			{
				case GOTNUMBER_STATE:
					switch (me->subStateID) 
					{
						case PROCESSINGWHOLEPART_SSTATE:
							TokenizerSyncSingleReceptor_exit_ProcessingWholePart(me);
						break;
					
						case PROCESSINGFRACTIONALPART_SSTATE:
							TokenizerSyncSingleReceptor_exit_ProcessingFractionalPart(me);
						break;
					};
				TokenizerSyncSingleReceptor_exit_GotNumber(me);
				printf("Number: %g\n", me->result);
				TokenizerSyncSingleReceptor_enter_NoNumber(me);
				me->stateID = NONUMBER_STATE;
			break;
			};
		break;
		}
	}; // end switch e.eType
	Mutex_release(me->itsMutex);
}



/*******************************************************************************/

