/*
 * KPD_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: user
 */

#ifndef KPD_PROGRAM_C_
#define KPD_PROGRAM_C_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void){
	u8 arr[4][4]=
	{
	  {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
	};

	u8 Local_u8Key=255;
	u8 flag=0;
	for(u8 col=0;col<4;col++){
		DIO_voidSetPinValue(KPD_Port,col,DIO_u8LOW);

		for(u8 row=0;row<4;row++){

			if(DIO_u8GetPinValue(KPD_Port,row+4)==0){
				Local_u8Key=arr[row][col];
				flag=1;
				_delay_ms(2);
				while(DIO_u8GetPinValue(KPD_Port,row+4)==0){

				}

			}
		}
		DIO_voidSetPinValue(KPD_Port,col,DIO_u8HIGH);
		if (flag==1){
			return Local_u8Key;
		}
	}
	return Local_u8Key;
}


#endif /* KPD_PROGRAM_C_ */
