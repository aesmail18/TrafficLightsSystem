/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		SYSTICK
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Private file for SYSTICK.
 *	@fun		functions: Public functions.
 *	@create		21 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Create the interface file @ 21 Jan 2024	11:45
 *===========================================================================================
 */

#ifndef MCAL_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTICK_INTERFACE_H_

#define MSYSTICK_CLKSRCBIT (0x00000002)
#define MSYSTICK_ENBIT 0
#define MSYSTICK_COUNTFLAG 16
#define MSYSTICK_INTEN 1

void MSYSTICK_InitClkSource(void);
void MSYSTICK_Start(uint32 Copy_u8Ticks);
void MSYSTICK_DelayMs(uint32 Copy_u32Delay);
uint32 MSYSTICK_GetElapsedTime(void);
uint32 MSYSTICK_GetRemaningTime(void);
uint8 MSYSTICK_ReadFlag( void );

void MSYSTICK_SetCallBack( void (*ptr)(void) );
void MSYSTICK_Handler(void);
void MSYSTICK_Stop(void);

#define NO_ERROR 0
#define ERROR 1


#endif /* MCAL_MSYSTICK_INTERFACE_H_ */
