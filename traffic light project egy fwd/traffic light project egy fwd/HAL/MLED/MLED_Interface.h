
/*
 * MLED_Interface.h
 *
 * Created: 11/8/2022 
 *  Author: Hisham Elbadry
 */ 

#ifndef HAL_MLED_INTERFACE_H_
#define HAL_MLED_INTERFACE_H_


#include"../../LIB/STD_TYPES.h"



#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MDIO/MDIO_Private.h"

#include"../../MCAL/MTIMER/MTIMER_Interface.h"
#include"../../MCAL/MGIE/MGIE_Interface.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include <stdbool.h>
/*Putting Descriptive names for different objects*/

void Led_ON (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber);

void Led_BLINKING (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber);

void Led_OFF (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber);

#endif











