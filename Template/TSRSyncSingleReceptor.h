/**
 ******************************************************************************
 * @file    TSRSyncSingleReceptor.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


#ifndef __TSRSYNCSINGLERECEPTOR_H
#define __TSRSYNCSINGLERECEPTOR_H


/* Includes ------------------------------------------------------------------*/
#include "TokenizeAsyncSinglePkg.h"
#include "stdio.h"

/* Exported macro ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
struct Mutex;

typedef struct{
	char ch;
	double result;
	TSTATETYPE stateID;
	TSUBSTATETYPE subStateID;
	double tensPlace;
	struct Mutex* itMutex;
	
}TokenizerSyncSingleReceptor;

/* Exported constants --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void TSSR_enter_GotNumber(TokenizerSyncSingleReceptor *const me);

void TSSR_enter_NoNumber(TokenizerSyncSingleReceptor* const me);

void TSSR_enter_ProccessingPractionalPart(TokenizerSyncSingleReceptor *const me);

void TSSR_enter_ProccessingWholePart(TokenizerSyncSingleReceptor *const me);

void TSSR_exit_GotNumber(TokenizerSyncSingleReceptor *const me);

void TSSR_exit_NoNumber(TokenizerSyncSingleReceptor* const me);

void TSSR_exit_ProccessingPractionalPart(TokenizerSyncSingleReceptor *const me);

void TSSR_exit_ProccessingWholePart(TokenizerSyncSingleReceptor *const me);

void TSSR_Init(TokenizerSyncSingleReceptor *const me);

void TSSR_CleanUp(TokenizerSyncSingleReceptor* const me);

void TSSR_eventDispatch(TokenizerSyncSingleReceptor* const me, Event e);

struct Mutex* TSSR_getItsMutex(const TokenizerSyncSingleReceptor* const me);

void TSSR_setItsMutex(TokenizerSyncSingleReceptor* const me, struct Mutex* p_Mutex);

TokenizerSyncSingleReceptor *TSSR_Create(void);
 
void TSSR_Destroy(TokenizerSyncSingleReceptor* const me);

#endif /* __TSRSYNCSINGLERECEPTOR_H */
