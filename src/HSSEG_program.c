/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver     HSSEG
 *	@version	1.0.0
 *  @layer      HAL
 *	@brief		7 Segment numbers
 *	@fun		functions: Init, Display, and Count
 *	@create		14 Mar 2024		13:30
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the body of counting function @ 14 Mar 2024	23:21
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"

#include "MGPIO_int.h"
#include "MSYSTICK_Interface.h"

#include "HSSEG_interface.h"

extern uint16 numbers[];

void HSSEG_Init(void){
	//Segment 1 --> port a
	MGPIO_voidSetMode(PORTA,PIN2,OUTPUT);//a
	MGPIO_voidSetOutputMode(PORTA,PIN2,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTA,PIN3,OUTPUT);//b
	MGPIO_voidSetOutputMode(PORTA,PIN3,OUTPUT_PUSH_PULL,LOW);


	MGPIO_voidSetMode(PORTA,PIN4,OUTPUT);//c
	MGPIO_voidSetOutputMode(PORTA,PIN4,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTA,PIN8,OUTPUT);//d
	MGPIO_voidSetOutputMode(PORTA,PIN8,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTA,PIN9,OUTPUT);//e
	MGPIO_voidSetOutputMode(PORTA,PIN9,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTA,PIN10,OUTPUT);//f
	MGPIO_voidSetOutputMode(PORTA,PIN10,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTA,PIN11,OUTPUT);//g
	MGPIO_voidSetOutputMode(PORTA,PIN11,OUTPUT_PUSH_PULL,LOW);

	//Segment 2 --> port b
	MGPIO_voidSetMode(PORTB,PIN5,OUTPUT);//a
	MGPIO_voidSetOutputMode(PORTB,PIN5,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTB,PIN6,OUTPUT);//b
	MGPIO_voidSetOutputMode(PORTB,PIN6,OUTPUT_PUSH_PULL,LOW);


	MGPIO_voidSetMode(PORTB,PIN7,OUTPUT);//c
	MGPIO_voidSetOutputMode(PORTB,PIN7,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTB,PIN12,OUTPUT);//d
	MGPIO_voidSetOutputMode(PORTB,PIN12,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTB,PIN13,OUTPUT);//e
	MGPIO_voidSetOutputMode(PORTB,PIN13,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTB,PIN14,OUTPUT);//f
	MGPIO_voidSetOutputMode(PORTB,PIN14,OUTPUT_PUSH_PULL,LOW);

	MGPIO_voidSetMode(PORTB,PIN15,OUTPUT);//g
	MGPIO_voidSetOutputMode(PORTB,PIN15,OUTPUT_PUSH_PULL,LOW);

}

void HSSEG_DisplayNumSeg1(uint8 copy_u16Num){
	MGPIO_voidWritePin(PORTA, PIN2, (GET_BIT(copy_u16Num,0)));
	MGPIO_voidWritePin(PORTA, PIN3, (GET_BIT(copy_u16Num,1)));
	MGPIO_voidWritePin(PORTA, PIN4, (GET_BIT(copy_u16Num,2)));
	MGPIO_voidWritePin(PORTA, PIN8, (GET_BIT(copy_u16Num,3)));
	MGPIO_voidWritePin(PORTA, PIN9, (GET_BIT(copy_u16Num,4)));
	MGPIO_voidWritePin(PORTA, PIN10, (GET_BIT(copy_u16Num,5)));
	MGPIO_voidWritePin(PORTA, PIN11, (GET_BIT(copy_u16Num,6)));
}

void HSSEG_DisplayNumSeg2(uint8 copy_u16Num){
	MGPIO_voidWritePin(PORTB, PIN5, (GET_BIT(copy_u16Num,0)));
	MGPIO_voidWritePin(PORTB, PIN6, (GET_BIT(copy_u16Num,1)));
	MGPIO_voidWritePin(PORTB, PIN7, (GET_BIT(copy_u16Num,2)));
	MGPIO_voidWritePin(PORTB, PIN12, (GET_BIT(copy_u16Num,3)));
	MGPIO_voidWritePin(PORTB, PIN13, (GET_BIT(copy_u16Num,4)));
	MGPIO_voidWritePin(PORTB, PIN14, (GET_BIT(copy_u16Num,5)));
	MGPIO_voidWritePin(PORTB, PIN15, (GET_BIT(copy_u16Num,6)));
}

void HSSEG_DisplayDesCount(uint8 copy_u16StartNum){
	int Seg2Val = copy_u16StartNum / 10;
	for(int i = Seg2Val; i >= 0; i--)
	{
		for(int j = 9; j >= 0; j--)
		{
			HSSEG_DisplayNumSeg2(numbers[i]);
			HSSEG_DisplayNumSeg1(numbers[j]);
			//Simulation don`t work properly with systick delay so I used no operation assembly instruction but my driver work fine
			for (uint32 j = 0; j < 1500000; j++)
			{
				__asm("NOP");
			}
		}
	}
}


