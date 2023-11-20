/**
 ******************************************************************************
 * @file    ButtonDriver.h
 * @author  truongdv
 * @version 1.0
 * @date    
 * @brief   
 * @history
 ******************************************************************************/


#ifndef __BUTTON_DRIVER_H
#define __BUTTON_DRIVER_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Exported types ------------------------------------------------------------*/
struct Button;
struct MicrowareEmitter;
struct Timer;

typedef struct{
	uint8_t oldState;
	uint8_t toggleOn;	
	struct MicrowareEmitter_t *itsMicrowaveEmitter;
	struct Button	* itsButton;
	struct Timer* itsTimer;
	
}ButtonDriver;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void ButtonDriver_Init(ButtonDriver *const me);
void ButtonDriver_Cleanup(ButtonDriver *const me);

/* Operation */
void ButtonDriver_eventRecieve(ButtonDriver* const me);

ButtonDriver* ButtonDriver_getItsButton(const ButtonDriver* const me);
void ButtonDriver_setItsButton(ButtonDriver *const me, struct Button *p_Button));

struct MicrowaveEmitter* ButtonDriver_getItsMicrowaveEmitter(const ButtonDriver* const me);
void ButtonDriver_setItsMicrowaveEmitter(ButtonDriver* const me, struct MicrowaveEmitter* p_MicrowaveEmitter);

struct Timer* ButtonDriver_getItsTimer(const ButtonDriver* const me);
void ButtonDriver_setItsTimer(ButtonDriver* const me, struct Timer* p_Timer);

ButtonDriver * ButtonDriver_Create(void);
void ButtonDriver_Destroy(ButtonDriver* const me);

void ButtonDriver___setItsButton(ButtonDriver* const me, struct Button* p_Button);
void ButtonDriver__setItsButton(ButtonDriver* const me, struct Button* p_Button);
void ButtonDriver__clearItsButton(ButtonDriver* const me);



#endif /* __BUTTON_DRIVER_H */
