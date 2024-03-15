/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		NVIC
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Private file for NVIC.
 *	@fun		functions: Registers address and some private macros.
 *	@create		17 Jan 2024		11:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Create the private file @ 17 Jan 2024	11:30
 *===========================================================================================
 */

#ifndef MNVIC_PRV_H_
#define MNVIC_PRV_H_

#define NVIC_BASE_ADDRESS 0xE000E100
#define AIRCR  *((volatile uint32*) (0xE000ED0C))
#define VECTKEY  0x05FA0000

typedef struct
{
	uint32 ISER[8];
	uint32 RESERVED0[24];
	uint32 ICER[8];
	uint32 RESERVED1[24];
	uint32 ISPR[8];
	uint32 RESERVED2[24];
	uint32 ICPR[8];
	uint32 RESERVED3[24];
	uint32 IAPR[8];
	uint32 RESERVED4[56];
	uint8 IPR[240];
	uint32 RESERVED5[580];
	uint32 STIR;

}NVIC_t;

#define NVIC  ((volatile NVIC_t*) (NVIC_BASE_ADDRESS))

#endif /* MNVIC_PRV_H_ */
