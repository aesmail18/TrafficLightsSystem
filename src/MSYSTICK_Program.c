/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		SYSTICK
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Private file for SYSTICK.
 *	@fun		functions: Driver functions.
 *	@create		21 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Write body of SysTick_Handler function @ 21 Jan 2024	11:55
 *===========================================================================================
 */

#include "Std_types.h"
#include "BIT_Math.h"
#include "MSYSTICK_Config.h"
#include "MSYSTICK_Interface.h"
#include "MSYSTICK_Private.h"

static void(*MSYSTICK_PF)(void) = NULL_PTR;

void MSYSTICK_InitClkSource(void){
	// CLK Source Selection
	if(CLK_SOURCE == MSYSTICK_AHB){
		SET_BIT(SYSTICK->STK_CTRL,MSYSTICK_CLKSRCBIT);
	}else if(CLK_SOURCE == MSYSTICK_AHB8){
		CLR_BIT(SYSTICK->STK_CTRL,MSYSTICK_CLKSRCBIT);
	}

}

void MSYSTICK_Start(uint32 Copy_u8Ticks){
	/**** Clear counting and load registers*/
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
	/* Enable ISR */
	CLR_BIT(SYSTICK -> STK_CTRL , 1);
	SYSTICK->STK_LOAD = Copy_u8Ticks;
	SET_BIT(SYSTICK->STK_CTRL,MSYSTICK_ENBIT);
}


void MSYSTICK_DelayMs(uint32 Copy_u32Delay)
{

	MSYSTICK_InitClkSource();
	/**** Clear counting and load registers*/
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
	/* Disable ISR */
	CLR_BIT(SYSTICK -> STK_CTRL , 1);
	MSYSTICK_Start( Copy_u32Delay * 1000 );
	SET_BIT(SYSTICK->STK_CTRL,MSYSTICK_ENBIT);
	/* Wiat Flag Polling */
	while( MSYSTICK_ReadFlag() == 0 );
	CLR_BIT(SYSTICK->STK_CTRL,MSYSTICK_ENBIT);
}

uint32 MSYSTICK_GetElapsedTime(void){
	uint32 ELapsed_Time = 1000*(SYSTICK->STK_LOAD - (SYSTICK -> STK_VAL));
	return ELapsed_Time;
}
uint32 MSYSTICK_GetRemaningTime(void){
	uint32 RemaningTime = 1000*(SYSTICK -> STK_VAL);
	return RemaningTime;
}

uint8 MSYSTICK_ReadFlag( void ){
	return ( GET_BIT( SYSTICK->STK_CTRL , MSYSTICK_COUNTFLAG ) );
}

void MSYSTICK_SetCallBack( void (*ptr)(void) ){

	MSYSTICK_PF = ptr;
}
void MSYSTICK_Handler(void){
	if(MSYSTICK_PF != NULL_PTR){
		MSYSTICK_PF();
	}
	CLR_BIT(SYSTICK->STK_CTRL,MSYSTICK_ENBIT);
}

void MSYSTICK_Stop(void){
	CLR_BIT(SYSTICK->STK_CTRL,MSYSTICK_ENBIT);
}
