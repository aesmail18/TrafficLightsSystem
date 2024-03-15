/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		EXTI
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Program file for EXTI.
 *	@fun		functions: Driver functions.
 *	@create		18 Jan 2024		12:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Write body of EXTI1_IRQHandler function @ 18 Jan 2024	13:15
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "MEXTI_prv.h"
#include "MEXTI_int.h"
#include "MEXTI_conf.h"


static void (*GlobalPTR[16])(void)= {NULL_PTR};//Array of pointers to function

void MEXTI_voidInerruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port)
{
	SYSCFG->EXTICR[Copy_u8Line%4] &=~(0b1111 << (4*(Copy_u8Line%4)));//Clearing the 4-bits sub register before writing to it
	SYSCFG->EXTICR[Copy_u8Line%4] |= (Copy_u8Port << (4*(Copy_u8Line%4)));//Set the port to be activated on the line
}
void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis)
{
	switch (Copy_u8ENDis) {
		case EXTI_Enable:
			EXTI->IMR |=(1 << Copy_u8IntLine);//set
			break;
		case EXTI_Disable:
			EXTI->IMR &=~(1 << Copy_u8IntLine);//clr
			break;
	}
}
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig)
{
	switch (Copy_u8Trig) {
		case EXTI_Rising:
			EXTI->RTSR |=(1 << Copy_u8IntLine);
			EXTI->FTSR &=~(1 << Copy_u8IntLine);
			break;
		case EXTI_Falling:
			EXTI->FTSR |=(1 << Copy_u8IntLine);
			EXTI->RTSR &=~(1 << Copy_u8IntLine);
			break;
		case EXTI_OnChange:
			EXTI->RTSR |=(1 << Copy_u8IntLine);
			EXTI->FTSR |=(1 << Copy_u8IntLine);
			break;
	}
}
void MEXTI0_voidCallBack(void (*ptr)(void))
{
	GlobalPTR[0] =ptr;
}
void MEXTI1_voidCallBack(void (*ptr)(void))
{
	GlobalPTR[1] =ptr;
}

void EXTI0_IRQHandler (void)
{
	GlobalPTR[0]();
	EXTI->PR |= 1;
}

void EXTI1_IRQHandler (void)
{
	GlobalPTR[1]();
	EXTI->PR |= (1 << 1);
}

