/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		RCC
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Configuration file for RCC.
 *	@fun		functions: Pre-build configuration.
 *	@create		15 Jan 2024		11:40
 *	@author		Ahmed Esmail
 *	@last		Last change: Define macros to choose the clock source  @ 15 Jan 2024	11:40
 *===========================================================================================
 */

#ifndef MRCC_CONF_H_
#define MRCC_CONF_H_

/*
 *you can choose: 1- HSE
 *				  2- HSI
 * */

#define CLOCK  RCC_HSI


#endif
