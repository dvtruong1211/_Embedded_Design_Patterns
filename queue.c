/**
 ******************************************************************************
 * @file    queue.c
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/
 
 /*******************************************************************************
 * Include
 ******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "queue.h"

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

void Queue_Init(Queue *const me, int32_t (*isFullFunction)(Queue *const me), 
								int32_t (*isEmptyFunction)(Queue *const me),
								int32_t (*getSizeFunction)(Queue *const me),
								void	  (*insertFunction)(Queue *const me, int32_t k),
								int32_t (*removeFunction)(Queue *const me))
{
	/* Initialize attributes */
	me->head = 0;
	me->size = 0;
	me->tail = 0;
	/* Initialize member function pointer */
	me->isFull = isFullFunction;
	me->getSize = getSizeFunction;
	me->insert = insertFunction;
	me->remove = removeFunction;
}

/* Opertaion Cleanup() */
void Queue_Cleanup(Queue *const me)
{
		/* Do somethings... */
}

/* Opertaion isFull() */
int32_t Queue_isFull(Queue *const me)
{
	return ((me->head + 1)% QUEUE_SIZE == me->tail);
}

/* Opertaion isEmpty() */
int32_t Queue_isEmpty(Queue *const me)
{
	return (me->head == me->tail);
}

/* Opertaion getSize() */
int32_t Queue_getSize(Queue *const me)
{
	return me->size;
}

/* Opertaion insert() */
void Queue_insert(Queue *const me, int32_t k)
{
	if(!me->isFull(me))
	{
		me->buffer[me->head] = k;
		m->head = (me->head + 1) % QUEUE_SIZE;
		++me->size;
	}
}

/* Opertaion remove() */
int32_t Queue_remove(Queue *const me)
{
	if(!me->isEmpty(me))
	{
		value = me->buffer[me->tail];
		me->tail = (me->tail+1) % QUEUE_SIZE;
		--me->size;
	}
	return value;
}


Queue * Queue_Create(void) 
{
	Queue* me = (Queue *) malloc(sizeof(Queue));
	if(me!=NULL)
	{
		Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, Queue_insert, Queue_remove);
	}
	return me;
}


void Queue_Destroy(Queue* const me) {
	if(me!=NULL)
	{
		Queue_Cleanup(me);
	}
	free(me);
}


/*******************************************************************************/
