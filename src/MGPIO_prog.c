/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		GPIO
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Program file for GPIO.
 *	@fun		functions: Set mode,Set output mode,Set input mode,Read,Write,and SetReset pin.
 *	@create		16 Jan 2024		11:40
 *	@author		Ahmed Esmail
 *	@last		Last change: Write the body of the Set/Reset function @ 16 Jan 2024	13:18
 *===========================================================================================
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "MGPIO_int.h"
#include "MGPIO_conf.h"
#include "MGPIO_prv.h"

void MGPIO_voidSetMode(PORT_t PORT, PIN_t PIN, MODE_t MODE)
{
	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch (PORT) {
		case PORTA:
			GPIOA->MODER &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOA->MODER |=(MODE << (PIN*2));
			break;
		case PORTB:
			GPIOB->MODER &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOB->MODER |=(MODE << (PIN*2));
			break;
		case PORTC:
			GPIOC->MODER &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOC->MODER |=(MODE << (PIN*2));
			break;
		}
	}
}
void MGPIO_voidSetOutputMode(PORT_t PORT, PIN_t PIN, OUT_MODE_t OUTPUT_MODE, SPEED_t SPEED)
{
	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch (PORT) {
		case PORTA:
			GPIOA->OTYPER &=~ (1 << (PIN));
			GPIOA->OTYPER |=(OUTPUT_MODE << (PIN));
			GPIOA->OSPEEDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOA->OSPEEDR |=(SPEED << (PIN*2));
			break;
		case PORTB:
			GPIOB->OTYPER &=~ (1 << (PIN));
			GPIOB->OTYPER |=(OUTPUT_MODE << (PIN));
			GPIOB->OSPEEDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOB->OSPEEDR |=(SPEED << (PIN*2));
			break;
		case PORTC:
			GPIOC->OTYPER &=~ (1 << (PIN));
			GPIOC->OTYPER |=(OUTPUT_MODE << (PIN));
			GPIOC->OSPEEDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOC->OSPEEDR |=(SPEED << (PIN*2));
			break;
		}
	}

}
void MGPIO_voidSetInputMode(PORT_t PORT, PIN_t PIN, IN_MODE_t INPUT_MODE)
{
	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch (PORT) {
		case PORTA:
			GPIOA->PUPDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOA->PUPDR |=(INPUT_MODE << (PIN*2));
			break;
		case PORTB:
			GPIOB->PUPDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOB->PUPDR |=(INPUT_MODE << (PIN*2));
			break;
		case PORTC:
			GPIOC->PUPDR &=~ (TWO_BIT_MASK << (PIN*2));
			GPIOC->PUPDR |=(INPUT_MODE << (PIN*2));
			break;
		}
	}
}
uint8 MGPIO_voidReadPin(PORT_t PORT, PIN_t PIN)
{
	uint8 Local_Reading =0;
	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch (PORT) {
		case PORTA:
			Local_Reading=GET_BIT(GPIOA->IDR,PIN);
			break;
		case PORTB:
			Local_Reading=GET_BIT(GPIOB->IDR,PIN);
			break;
		case PORTC:
			Local_Reading=GET_BIT(GPIOC->IDR,PIN);
			break;
		}

	}
	return Local_Reading;
}
void MGPIO_voidWritePin(PORT_t PORT, PIN_t PIN, VAL_t VALUE)
{

	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch (PORT) {
		case PORTA:
			if(VALUE == HIGH_VAL)
			{
				GPIOA->ODR |=(VALUE << PIN);
			}
			else
			{
				CLR_BIT(GPIOA->ODR,PIN);
			}
			break;
		case PORTB:
			if(VALUE == HIGH_VAL)
			{
				GPIOB->ODR |=(VALUE << PIN);
			}
			else
			{
				CLR_BIT(GPIOB->ODR,PIN);
			}
			break;
		case PORTC:
			if(VALUE == HIGH_VAL)
			{
				GPIOC->ODR |=(VALUE << PIN);
			}
			else
			{
				CLR_BIT(GPIOC->ODR,PIN);
			}
			break;
		}

	}
}

void MGPIO_voidSetResetPin(PORT_t PORT, PIN_t PIN, SET_RESET_t OPTION)
{
	if(((PORT == PORTA) && ((PIN == 13) || (PIN == 14) || (PIN == 15))) || ((PORT == PORTB) && ((PIN == 2) || (PIN == 3) || (PIN == 4))))
	{
		//Do Nothing
	}
	else
	{
		switch(PORT)
		{
		case PORTA:
			switch(OPTION)
			{
			case SET_VAL:
				GPIOA->BSRR |= (1 << PIN);
				break;
			case RESET_VAL:
				GPIOA->BSRR |= (1 << (PIN+SET_RESET_OFFSET));
				break;
			}
			break;
			case PORTB:
				switch(OPTION)
				{
				case SET_VAL:
					GPIOB->BSRR |= (1 << PIN);
					break;
				case RESET_VAL:
					GPIOB->BSRR |= (1 << (PIN+SET_RESET_OFFSET));
					break;
				}
				break;
				case PORTC:
					switch(OPTION)
					{
					case SET_VAL:
						GPIOC->BSRR |= (1 << PIN);
						break;
					case RESET_VAL:
						GPIOC->BSRR |= (1 << (PIN+SET_RESET_OFFSET));
						break;
					}
					break;
		}
	}
}
