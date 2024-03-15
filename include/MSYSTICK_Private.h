/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		SYSTICK
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Private file for SYSTICK.
 *	@fun		functions: Registers address and some private macros.
 *	@create		21 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Create the private file @ 21 Jan 2024	11:30
 *===========================================================================================
 */

#ifndef MCAL_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_PRIVATE_H_

#define SYSTICK_BaseAdd 0xE000E010

typedef struct {
	uint32 STK_CTRL;
	uint32 STK_LOAD;
	uint32 STK_VAL;
	uint32 STK_CALIB;
}SYSTICK_MemMap_t;

#define SYSTICK ((volatile SYSTICK_MemMap_t*)(SYSTICK_BaseAdd))

/*(STK_CTRL)*/
#define MSYSTICK_Flag	16


#endif /* MCAL_MSYSTICK_PRIVATE_H_ */
