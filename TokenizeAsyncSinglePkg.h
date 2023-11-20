/**
 ******************************************************************************
 * @file    TokenizeAsyncSinglePkg.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


#ifndef __TOKENIZEASYNCSINGLEPKG_H
#define __TOKENIZEASYNCSINGLEPKG_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported types ------------------------------------------------------------*/

#define QSIZE 100

typedef enum{
	EV_DIGIT,
	EV_DOT,
	EV_WHITESPACE,
	EV_ENDOFSTRING
}EventType;

typedef struct{
	EventType eType;
	union eventData{
		char c;
	}eData;
}Event;

typedef enum{
	NULL_STATE,
	NONUMBER_STATE,
	GOTNUMBER_STATE,
}TSTATETYPE;

typedef enum{
	NULL_STATE,
	PROCESSINGWHOLEPART_SSTATE,
	PROCESSINGPRACTIONPART_SSTATE
}TSUBSTATETYPE;

/* helper function returns the digit */
/* held by a char */
int digit(char c)
{
	return c -'0';
}

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/* helper function returns the digit */
/* held by a char */
int digit(char c)
{
	return c -'0';
}

/*
OS signal and wait functions for
task synchronization
*/
void postSignal(void);
void waitOnSignal(void);



#endif /* __TOKENIZEASYNCSINGLEPKG_H */
