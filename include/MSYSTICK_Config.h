/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		SYSTICK
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Configuration file for SYSTICK.
 *	@fun		functions: Pre-build configuration.
 *	@create		21 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Define macros to choose the interrupt source @ 21 Jan 2024	11:45
 *===========================================================================================
 */

#ifndef MCAL_MSYSTICK_CONFIG_H_
#define MCAL_MSYSTICK_CONFIG_H_

#define CLK_SOURCE MSYSTICK_AHB8
#define MSYSTICK_AHB 1
#define MSYSTICK_AHB8 0

#define MSYSTICK_ISR_Init 0 /* 	0 -> disable
 	 	 	 	 	 	 	 	1 -> ENABLE    */


#endif /* MCAL_MSYSTICK_CONFIG_H_ */
