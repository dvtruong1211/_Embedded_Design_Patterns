/**
 ******************************************************************************
 * @file    cachedQueue.c
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


/*******************************************************************************
 * Include
 ******************************************************************************/
#include "cachedQueue.h"
#include "stdlib.h"
#include "string.h"



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
void CachedQueue_Init(CachedQueue* const me, char *fName,
											int32_t (*isFull)(CachedQueue* const me),
											int32_t (*isEmpty)(CachedQueue* const me),
											int32_t (*getSize)(CachedQueue* const me),
											void 		(*insert)(CachedQueue* const me, int32_t k),
											int32_t (*remove)(CachedQueue* const me),
											void    (*flush)(CachedQueue* const me),
											void    (*load)(CachedQueue* const me))
{
	/* initialize base class */
	me->queue = Queue_Create();
	
	/* initialize subclass attributes */
	me->numberElementsOnDisk = 0;
	strcpy(me->fileName, fName);
	
	/* initialize aggregates */
	me->OutputQueue = Queue_Create();
	
	/* initialize subclass virtual operations ptrs */
	me->isFull = isFullfunction;
	me->isEmpty = isEmptyfunction;
	me->getSize = getSizefunction;
	me->insert = insertfunction;
	me->remove = removefunction;
	me->flush = flushfunction;
	me->load = loadfunction;
}
											
void CachedQueue_Cleanup(CachedQueue* const me)
{
	Queue_Cleanup(me->queue);
}

/* Operations */
int32_t CachedQueue_isFull(CachedQueue* const me)
{
	return	me->queue->isFull(me->queue) && me->outputQueue->isFull(me->outputQueue);
}


int32_t CachedQueue_isEmpty(CachedQueue* const me)
{
	return	me->queue->isEmpty(me->queue) && me->outputQueue->isEmpty(me->outputQueue) &&(me->numberElementsOnDisk == 0);
}

int32_t CachedQueue_getSize(CachedQueue* const me)
{
	return me->queue->getSize(me->queue) + me->outputQueue->getSize(me->outputQueue) + me->numberElementsOnDisk;
}

void CachedQueue_insert(CachedQueue* const me, int32_t k)
{
	if (me->queue->isFull(me->queue)) 
		me->flush(me);
	me->queue->insert(me->queue, k);
}

int32_t CachedQueue_remove(CachedQueue* const me)
{
	if (!me->outputQueue->isEmpty(me->outputQueue))
		return me->outputQueue->remove(me->outputQueue);
	else if (me->numberElementsOnDisk>0) 
	{
		me->load(me);
		return me->queue->remove(me->queue);
	}
	else
		return me->queue->remove(me->queue);
}

void CachedQueue_flush(CachedQueue* const me)
{
	// write file I/O statements here . . .
}

void CachedQueue_load(CachedQueue* const me)
{
	// write file I/O statements here . . .
}
CachedQueue * CachedQueue_Create(void)
{
	CachedQueue* me = (CachedQueue *)
	malloc(sizeof(CachedQueue));
	if(me!=NULL)
	{
		CachedQueue_Init(me, "C:\\queuebuffer.dat", CachedQueue_isFull, CachedQueue_isEmpty, CachedQueue_getSize, CachedQueue_insert, CachedQueue_remove, CachedQueue_flush, CachedQueue_load);
	}
	return me;
}
void CachedQueue_Destroy(CachedQueue* const me)
{
	if(me!=NULL)
	{
		CachedQueue_Cleanup(me);
	}
	free(me);
}




/*******************************************************************************/

