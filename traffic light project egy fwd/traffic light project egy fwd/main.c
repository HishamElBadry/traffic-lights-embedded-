/*
 * traffic light project egy fwd.c
 *
 * Created: 11/2/2022 10:23:35 PM
 * Author : Hisham Elbadry
 */ 
#include "App/App.h"




int main()
{
	
	/*
	MDIO_SetPortDirection(MDIO_PORTA,PORT_OUTPUT);
	
	//initialize timer and interrupt 
	MTIMER0_Init();
	MGIE_Enable();
	MEXTI0_Init();

	//Setting OC0 of CTC
	MTIMER0_SetCTC(125);
		
	MTIMER0_CTC_CALLBACK(Test_drivers);
	*/
	app_init();
	app_start();
	
	while(1)
	{
		
	
		
	}
	return 0;

}


