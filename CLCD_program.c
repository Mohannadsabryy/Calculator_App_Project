/*
 * CLCD_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <avr/delay.h>
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

void CLCD_voidSendData(u8 Copy_u8Data){
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_RS_PIN,DIO_u8HIGH);
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_RW_PIN,DIO_u8LOW);
	DIO_voidSetPortValue(CLCD_DATAPORT,Copy_u8Data);
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_E_PIN,DIO_u8LOW);
}
void CLCD_voidSendCommand(u8 Copy_u8Command){

	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_RS_PIN,DIO_u8LOW);
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_RW_PIN,DIO_u8LOW);
	DIO_voidSetPortValue(CLCD_DATAPORT,Copy_u8Command);

	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_E_PIN,DIO_u8HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_CTRLPORT,CLCD_E_PIN,DIO_u8LOW);
}

void CLCD_voidInit(void){
	_delay_ms(35);

	CLCD_voidSendCommand(0b00111000);

	CLCD_voidSendCommand(0b00001100);

	CLCD_voidSendCommand(0b00000001);

}


void CLCD_voidSendString(u8 *Copy_pu8String){
	u8 i=0;
	while(Copy_pu8String[i]!='\0'){
		CLCD_voidSendData(Copy_pu8String[i]);
		i++;
	}
}


void CLCD_voidSetXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition){
	u8 Local_u8Address;
	if(Copy_u8YPosition==0){
		Local_u8Address=Copy_u8XPosition;
	}
	else{
		Local_u8Address=Copy_u8XPosition+0x40;
	}

	SET_BIT(Local_u8Address,7);

	CLCD_voidSendCommand(Local_u8Address);
}
void CLCD_voidPrintCustomData(u8 *Copy_u8Data,u8 Copy_u8PatternNum,u8 Copy_u8XPosition,u8 Copy_u8YPosition){
	u8 local_address;
	local_address=Copy_u8PatternNum*8;
	SET_BIT(local_address,6);
	CLCD_voidSendCommand(local_address);
	for(u8 i=0;i<8;i++){
		CLCD_voidSendData(Copy_u8Data[i]);
	}
	CLCD_voidSetXYPosition(Copy_u8XPosition,Copy_u8YPosition);
	CLCD_voidSendData(Copy_u8PatternNum);


}
void CLCD_voidSendCompleteNum(u8 Copy_u8Num){
		u8 len=0;
		u8 n=Copy_u8Num;
		u8 rem;
		while(n!=0){
			len++;
			n=n/10;
		}
		u8 str[len];
		for(u8 i=0;i<len;i++){
			rem=Copy_u8Num%10;
			Copy_u8Num=Copy_u8Num/10;
			str[len -(i+1)]=rem+'0';
		}
		str[len]='\0';
		u8 i=0;
		while(str[i]!='\0'){
			CLCD_voidSendData(str[i]);
			i++;
		}
}

