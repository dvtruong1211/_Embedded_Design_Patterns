/**
 ******************************************************************************
 * @file    cachedQueue.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


#ifndef __CACHEDQUEUE_H
#define __CACHEDQUEUE_H

/* Includes ------------------------------------------------------------------*/
#include "queue.h"

/* Exported types ------------------------------------------------------------*/
#typedef struct{
	Queue *queue;  /* Base class */
	/* New attributes */
	char fileName[80];
	
	uint32_t numberElementsOnDisk;
	/* Aggregation in subclass */
	Queue* outputQueue;
	
	/* inherited vitual functions */
	int32_t (*isFull)(CachedQueue* const me);
	int32_t (*isEmpty)(CachedQueue* const me);
	int32_t (*getSize)(CachedQueue* const me);
	void    (*insert)(CachedQueue* const me, int32_t k);
	int32_t (*remove)(CachedQueue* const me);
	
	/* New virtual functions */
	void (*flush)(CachedQueue* const me); 
	void (*load)(CachedQueue* const me);
	
};

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* Constructor and destructors: */
void CachedQueue_Init(CachedQueue* const me, char *fName,
											int32_t (*isFull)(CachedQueue* const me),
											int32_t (*isEmpty)(CachedQueue* const me),
											int32_t (*getSize)(CachedQueue* const me),
											void 		(*insert)(CachedQueue* const me, int32_t k),
											int32_t (*remove)(CachedQueue* const me),
											void    (*flush)(CachedQueue* const me),
											void    (*load)(CachedQueue* const me));
											
void CachedQueue_Cleanup(CachedQueue* const me);

/* Operations */
int32_t CachedQueue_isFull(CachedQueue* const me);
int32_t CachedQueue_isEmpty(CachedQueue* const me);
int32_t CachedQueue_getSize(CachedQueue* const me);
void CachedQueue_insert(CachedQueue* const me, int32_t k);
int32_t CachedQueue_remove(CachedQueue* const me);
void CachedQueue_flush(CachedQueue* const me);
void CachedQueue_load(CachedQueue* const me);
CachedQueue * CachedQueue_Create(void);
void CachedQueue_Destroy(CachedQueue* const me);

#endif /* __CACHEDQUEUE_H */
