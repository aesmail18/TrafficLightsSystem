/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		RCC
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Program file for RCC.
 *	@fun		functions: Init, Clock Enable and Disable
 *	@create		15 Jan 2024		11:30
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the body of the clock disable function @ 15 Jan 2024	11:50
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "MRCC_prv.h"
#include "MRCC_int.h"
#include "MRCC_conf.h"


void MRCC_voidInit(void)
{

#if CLOCK==RCC_HSE
	//bypass -> crystal oscillator (2pins) / RC (1 pin)
	RCC->CR &=~(1 << RCC_BYP);//clear bit
	RCC->CR |= (1 << RCC_HSEON);//ON HSE

	while(!GET_BIT(RCC->CR,RCC_HSERDY));//wait till HSE is on

	RCC->CFGR &= SWITCH_MASK;// Masking the first 2 LSB
	RCC->CFGR |= RCC_HSE;// Select HSE to be the system clock

#elif CLOCK==RCC_HSI
	// RCC->CR |= (1 << RCC_BYP); //SET BIT (RC with 1 pin)
	RCC->CR |= (1 << RCC_HSION);//ON HSI

	while(!GET_BIT(RCC->CR,RCC_HSIRDY));//wait till HSI is on

	RCC->CFGR &=SWITCH_MASK;// Masking the first 2 LSB
	RCC->CFGR |=RCC_HSI;// Select HSI to be the system clock
#endif
}

void MRCC_voidEnable(BUS Copy_BUS, uint16 Copy_uint16Peripherals)
{
	switch(Copy_BUS)
	{
	case RCC_AHB1:
		RCC->AHB1ENR |= (1<<Copy_uint16Peripherals);
		break;
	case RCC_AHB2:
		RCC->AHB2ENR|= (1<<Copy_uint16Peripherals);
		break;
	case RCC_APB1:
		RCC->APB1ENR |=(1<<Copy_uint16Peripherals);
		break;
	case RCC_APB2:
		RCC->APB2ENR |= (1<<Copy_uint16Peripherals);
		break;
	}
}

void MRCC_voidDisable(BUS Copy_BUS, uint16 Copy_uint16Peripherals)
{
	switch(Copy_BUS)
	{
	case RCC_AHB1:
		RCC->AHB1ENR &=~ (1<<Copy_uint16Peripherals);
		break;
	case RCC_AHB2:
		RCC->AHB2ENR &=~ (1<<Copy_uint16Peripherals);
		break;
	case RCC_APB1:
		RCC->APB1ENR &=~ (1<<Copy_uint16Peripherals);
		break;
	case RCC_APB2:
		RCC->APB2ENR &=~ (1<<Copy_uint16Peripherals);
		break;
	}
}
