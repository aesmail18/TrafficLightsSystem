/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver
 *	@version	1.0.0
 *  @layer      APPLICATION
 *	@brief		Main file.
 *	@fun		functions:
 *	@create		12 Mar 2024		13:30
 *	@author		Ahmed Esmail
 *	@last		Last change: Finish the main and write some handy comments @ 15 Mar 2024	11:21
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"

#include "MRCC_int.h"
#include "MSYSTICK_Interface.h"
#include "MNVIC_int.h"
#include "MGPIO_int.h"
#include "MEXTI_int.h"
//include "SPI_interface.h"

#include "HSSEG_interface.h"
//include "TTL_interface.h"


//extern uint16 numbers[];

void NormalState(void);
void PendingState(void);

void main(void)
{
	//RCC Configuration
	MRCC_voidInit();

	//SysTick Configuration
	MSYSTICK_InitClkSource();

	//Clock Configuration
	MRCC_voidEnable(RCC_AHB1,AHB1_GPIOA);
	MRCC_voidEnable(RCC_AHB1,AHB1_GPIOB);
	MRCC_voidEnable(RCC_APB2,APB2_SYSCFG);

	//NVIC Configuration
	MNVIC_VoidSetInterruptGroupMode(Group16Sub0);//16 priority group,each group has no sub-groups
	MNVIC_VoidSetInterruptPriority(6,0,0);//EXTI0 has group number zero and sub-group number zero
	MNVIC_VoidSetInterruptPriority(7,1,0);//EXTI1 has group number one and sub-group number zero
	NVIC_voidInterruptEnable(6);//EXTI Line0 interrupt
	NVIC_voidInterruptEnable(7);//EXTI Line1 interrupt

	//SPI Configuration

	//GPIO Configuration

	//Input pins Configuration --> Button
	MGPIO_voidSetMode(PORTA,PIN0,INPUT);
	MGPIO_voidSetInputMode(PORTA,PIN0,INPUT_PULLUP);

	MGPIO_voidSetMode(PORTA,PIN1,INPUT);
	MGPIO_voidSetInputMode(PORTA,PIN1,INPUT_PULLUP);

	//Output pins Configuration
	//1- LEDs
	//Red
	MGPIO_voidSetMode(PORTA,PIN5,OUTPUT);
	MGPIO_voidSetOutputMode(PORTA,PIN5,OUTPUT_PUSH_PULL,LOW);

	//Yellow
	MGPIO_voidSetMode(PORTA,PIN6,OUTPUT);
	MGPIO_voidSetOutputMode(PORTA,PIN6,OUTPUT_PUSH_PULL,LOW);

	//Green
	MGPIO_voidSetMode(PORTA,PIN7,OUTPUT);
	MGPIO_voidSetOutputMode(PORTA,PIN7,OUTPUT_PUSH_PULL,LOW);

	//Walk Green
	MGPIO_voidSetMode(PORTB,PIN8,OUTPUT);
	MGPIO_voidSetOutputMode(PORTB,PIN8,OUTPUT_PUSH_PULL,LOW);

	//Walk Red
	MGPIO_voidSetMode(PORTB,PIN9,OUTPUT);
	MGPIO_voidSetOutputMode(PORTB,PIN9,OUTPUT_PUSH_PULL,LOW);

	//Seven Segments
	HSSEG_Init();

	//TFT Configuration
	/*Could not add it due to the protues don`t support our kind*/

	//EXTI Configuration

	MEXTI_voidInterruptTrigger(EXTI_LineZero,EXTI_Falling);//Line 0 interrupt is triggered on falling edge
	MEXTI_voidInterruptTrigger(EXTI_LineOne,EXTI_Falling);//Line 1 interrupt is triggered on falling edge
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero,EXTI_Enable);//PIE for line 0
	MEXTI_voidInterruptEnableDisable(EXTI_LineOne,EXTI_Enable);//PIE for line 1
	MEXTI_voidInerruptSetPort(EXTI_LineZero,EXTI_PortA);//Configure PIN A0 as EXTI pin
	MEXTI_voidInerruptSetPort(EXTI_LineOne,EXTI_PortA);//Configure PIN A1 as EXTI pin
	MEXTI0_voidCallBack(PendingState);//EXTI0 is used to turn LEDs off
	MEXTI1_voidCallBack(NormalState);//EXTI1 is used to turn LEDs on


	while(1)
	{
		NormalState();
	}
}

void NormalState(void)
{
	// 1 sec = 1000000
	//Red
	MGPIO_voidWritePin(PORTA, PIN5, HIGH_VAL);
	MGPIO_voidWritePin(PORTB, PIN9, LOW_VAL);//crosswalk red off
	MGPIO_voidWritePin(PORTB, PIN8, HIGH_VAL);//crosswalk green on
	//TFT Display image 1
	HSSEG_DisplayDesCount(60);
	//TFT Display image 2
	MGPIO_voidWritePin(PORTA, PIN5, LOW_VAL);
	MGPIO_voidWritePin(PORTB, PIN9, HIGH_VAL);//crosswalk red on
	MGPIO_voidWritePin(PORTB, PIN8, LOW_VAL);//crosswalk green off

	//Green
	MGPIO_voidWritePin(PORTA, PIN7, HIGH_VAL);
	HSSEG_DisplayDesCount(90);
	MGPIO_voidWritePin(PORTA, PIN7, LOW_VAL);

	//Yellow
	MGPIO_voidWritePin(PORTA, PIN6, HIGH_VAL);
	HSSEG_DisplayDesCount(15);
	MGPIO_voidWritePin(PORTA, PIN6, LOW_VAL);

}

void PendingState(void)
{
	MGPIO_voidWritePin(PORTA, PIN5, LOW_VAL);
	MGPIO_voidWritePin(PORTA, PIN6, LOW_VAL);
	MGPIO_voidWritePin(PORTA, PIN7, LOW_VAL);

	//Red
	MGPIO_voidWritePin(PORTA, PIN5, HIGH_VAL);
	MGPIO_voidWritePin(PORTB, PIN9, LOW_VAL);//crosswalk red off
	MGPIO_voidWritePin(PORTB, PIN8, HIGH_VAL);//crosswalk green on
	//TFT Display image 1
	HSSEG_DisplayDesCount(60);
	//TFT Display image 2
	MGPIO_voidWritePin(PORTA, PIN5, LOW_VAL);
	MGPIO_voidWritePin(PORTB, PIN9, HIGH_VAL);//crosswalk red on
	MGPIO_voidWritePin(PORTB, PIN8, LOW_VAL);//crosswalk green off

}

