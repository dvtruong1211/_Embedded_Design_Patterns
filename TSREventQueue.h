/**
 ******************************************************************************
 * @file    TSREventQueue.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


#ifndef __TSREVENTQUEUE_H
#define __TSREVENTQUEUE_H

/* Includes ------------------------------------------------------------------*/
#include "TokenizeAsyncSinglePkg.h"

/* Exported macro ------------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/
typedef struct{
	Event q[100];
	int size;
	int head;
	int tail;
	struct Mutex* itsMutex;
	
}TSREventQueue;

/* Exported constants --------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */

/* Constructors and destructors:*/
void TSREventQueue_Init(TSREventQueue *const me);
void TSREventQueue_Cleanup(TSREventQueue *const me);

/* Operations */
int TSREventQueue_isEmpty(TSREventQueue* const me);
int TSREventQueue_isFull(TSREventQueue* const me);
/* puts the passed event in */
/* the event queue and then */
/* calls the event receptor of */
/* the state machine. Note */
/* if the queue overflows an */
/* error code (1) is returned. */
Event TSREventQueue_pull(TSREventQueue *const me);

struct Mutex* TSREventQueue_getItsMutex(const TSREvent* const me);

void TSREventQueue_setItsMutex(TSREventQueue *const me, struct Mutex* p_Mutex);

TSREventQueue* TSREventQueue_Create(void);

void TSREventQueue_Destroy(TSREventQueue *const me);

#endif /* __TSREVENTQUEUE_H */
