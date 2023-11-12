/**
 ******************************************************************************
 * @file    queue.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/
#ifndef __QUEUE_H
#define __QUEUE_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"


/* Exported macro ------------------------------------------------------------*/
#define QUEUE_SIZE  10

/* Exported types ------------------------------------------------------------*/
/* Class Queue */
typedef struct{
	 int32_t buffer[QUEUE_SIZE]; /*  where the data things are */
	 int32_t head;
	 uint32_t size;
	 int32_t tail;
	 int32_t (*isFull)(Queue * const me);
	 int32_t (*isEmpty)(Queue * const me);
	 int32_t (*getSize)(Queue * const me);
	 void (*insert)(Queue * const me, int32_t k);
	 int (*remove)(Queue * const me);
	 
}Queue;



/* Exported functions ------------------------------------------------------- */
/* Constructors and destructors  */
void Queue_Init(Queue *const me, int32_t (*isFullFunction)(Queue *const me), 
								int32_t (*isEmptyFunction)(Queue *const me),
								int32_t (*getSizeFunction)(Queue *const me),
								void	  (*insertFunction)(Queue *const me, int32_t k),
								int32_t (*removeFunction)(Queue *const me));


void Queue_Cleanup(Queue *const me);

/* Operations */
int32_t Queue_isFull(Queue *const me);
int32_t Queue_isEmpty(Queue *const me);
int32_t Queue_getSize(Queue *const me);
void 		Queue_insert(Queue *const me, int32_t k);
int32_t Queue_remove(Queue *const me);

Queue *Queue_Create(void);

void Queue_Destroy(Queue* const me);




#endif /* __QUEUE_H__ */