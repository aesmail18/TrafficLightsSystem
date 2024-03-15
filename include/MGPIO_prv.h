/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		GPIO
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Interface file for GPIO.
 *	@fun		functions: Public functions.
 *	@create		16 Jan 2024		11:40
 *	@author		Ahmed Esmail
 *	@last		Last change: Define Set/Reset function prototype @ 16 Jan 2024	11:55
 *===========================================================================================
 */

#ifndef MGPIO_PRV_H_
#define MGPIO_PRV_H_

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_t;

#define GPIOA ((volatile GPIO_t*) (GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile GPIO_t*) (GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile GPIO_t*) (GPIOC_BASE_ADDRESS))



#define INPUT 0
#define OUTPUT 1
#define ALTER_FUNC 2
#define ANALOG 3

#define TWO_BIT_MASK   3
#define SET_RESET_OFFSET 16


#endif /* MGPIO_PRV_H_ */
