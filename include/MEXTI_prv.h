/*
 *===========================================================================================
 *	@project	Traffic lights system
 *	@platform	ARM
 *	@module		STM32F401ccub
 *	@driver		EXTI
 *	@version	1.0.0
 *  @layer      MCAL
 *	@brief		Private file for EXTI.
 *	@fun		functions: Registers address and some private macros.
 *	@create		18 Jan 2024		12:15
 *	@author		Ahmed Esmail
 *	@last		Last change: Create the private file @ 18 Jan 2024	12:30
 *===========================================================================================
 */

#ifndef MEXTI_PRV_H_
#define MEXTI_PRV_H_

#define EXTI_BASE_ADDRESS  0x40013C00
#define SYSCFG_BASE_ADDRESS  0x40013800

typedef struct
{
	uint32 IMR;
	uint32 EMR;
	uint32 RTSR;
	uint32 FTSR;
	uint32 SWIER;
	uint32 PR;
}EXTI_t;

typedef struct
{
	uint32 MEMRMP;
	uint32 PMC;
	uint32 EXTICR[4];
	uint32 RESERVED[2];
	uint32 CMPCR;
}SYSCFG_t;

#define EXTI ((volatile EXTI_t*) (EXTI_BASE_ADDRESS))
#define SYSCFG ((volatile SYSCFG_t*) (SYSCFG_BASE_ADDRESS))

#endif /* MEXTI_PRV_H_ */
