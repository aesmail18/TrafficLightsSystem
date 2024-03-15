/*
 * MGPIO_int.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Kimo Store
 */

#ifndef MGPIO_INT_H_
#define MGPIO_INT_H_

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC
}PORT_t;

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;

typedef enum
{
	INPUT=0,
	OUTPUT,
	ALTER_FUNC,
	ANALOG
}MODE_t;

typedef enum
{
	OUTPUT_PUSH_PULL=0,
	OUTPUT_OPEN_DRAIN
}OUT_MODE_t;

typedef enum
{
	LOW=0,
	MEDIUM,
	HIGH,
	VERY_HIGH
}SPEED_t;

typedef enum
{
	INPUT_NO_PULLUP_PULLDOWN=0,
	INPUT_PULLUP,
	INPUT_PULLDOWN
}IN_MODE_t;

typedef enum
{
LOW_VAL=0,
HIGH_VAL
}VAL_t;

typedef enum
{
	SET_VAL=0,
	RESET_VAL
}SET_RESET_t;

void MGPIO_voidSetMode(PORT_t PORT, PIN_t PIN, MODE_t MODE);
void MGPIO_voidSetOutputMode(PORT_t PORT, PIN_t PIN, OUT_MODE_t OUTPUT_MODE, SPEED_t SPEED);
void MGPIO_voidSetInputMode(PORT_t PORT, PIN_t PIN, IN_MODE_t INPUT_MODE);
uint8 MGPIO_voidReadPin(PORT_t PORT, PIN_t PIN);
void MGPIO_voidWritePin(PORT_t PORT, PIN_t PIN, VAL_t VALUE);
void MGPIO_voidSetResetPin(PORT_t PORT, PIN_t PIN, SET_RESET_t OPTION);

#endif /* MGPIO_INT_H_ */
