/**
 ******************************************************************************
 * @file    SecuritySupervisor.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/
 
 /*******************************************************************************
 * Include
 ******************************************************************************/
##include "stdint.h"
##include "queue.h"
 
 
 
 /*******************************************************************************
 * Code 
 ******************************************************************************/
static eventStatus dispatchEvent(uint16_t id)
{
	eventStatus res = eventNotConSumed; 
	switch (activeState)
		{
		/* Are we in the Idle state */
		case SecuritySupervisor_Idle:
		{
			if(id == NULL_ID) /* Null triggered even? */
			{
				if(retries >= 3)
				{
					activeState - SecuritySupervisor_ErrorState;
					displayMsg("ERROR: Max retries Exceeded");
					res = eventConsumed;
				}
				else
				{
					++ retries;
					activeState = SecuritySupervisor_Accepting;
					res = eventConsumed;
				}
			}
			break;
		}
		case SecuritySupervisor_Accepting:
		{
			if(id == keypress_SecuritySupervisor_Event_id)
			{
				/* params struct has the data in the attribute ’key’ */
				/* transition 1 */
			}
		}
			
	}
 