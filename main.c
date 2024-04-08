/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "QUEUE_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "Calculator.h"
u8 flag=0;
int main(void){
	u8 key_pressed;
	DIO_voidSetPortDirection(DIO_u8PORTD,0b00001111);
	DIO_voidSetPortValue(DIO_u8PORTD,0b11111111);
	DIO_voidSetPortDirection(DIO_u8PORTA,0b11111111);
	DIO_voidSetPortDirection(DIO_u8PORTC,0b00000111);
	CLCD_voidInit();
	Queue queue;
	Queue *QueuePtr=&queue;
	init(QueuePtr);
	/*
		for + op click 10 on keypad
		for - op click 11 on keypad
		for * op click 12 on keypad
		for / op click 13 on keypad
		for = click 14 on keypad
		for clr click 15 on keypad
	*/
	while(1){
		key_pressed=KPD_u8GetPressedKey();
		switch(key_pressed){
			case 1:Enqueue(1,QueuePtr);
				   CLCD_voidSendData('1');
				   break;
			case 2:Enqueue(2,QueuePtr);
				   CLCD_voidSendData('2');
				   break;
			case 3:Enqueue(3,QueuePtr);
				   CLCD_voidSendData('3');
				   break;
			case 4:Enqueue(4,QueuePtr);
				   CLCD_voidSendData('4');
				   break;
			case 5:Enqueue(5,QueuePtr);
			       CLCD_voidSendData('5');
			       break;
			case 6:Enqueue(6,QueuePtr);
				   CLCD_voidSendData('6');
				   break;
			case 7:Enqueue(7,QueuePtr);
				   CLCD_voidSendData('7');
				   break;
			case 8:Enqueue(8,QueuePtr);
				   CLCD_voidSendData('8');
				   break;
			case 9:Enqueue(9,QueuePtr);
			       CLCD_voidSendData('9');
				   break;
			case 10:Enqueue(plus_op,QueuePtr);
					CLCD_voidSendData('+');
					break;
			case 11:Enqueue(minus_op,QueuePtr);
					CLCD_voidSendData('-');
					break;
			case 12:Enqueue(mult_op,QueuePtr);
					CLCD_voidSendData('*');
					break;
			case 13:Enqueue(div_op,QueuePtr);
					CLCD_voidSendData('/');
					break;
			case 14:Enqueue(equal,QueuePtr);
					CLCD_voidSendData('=');
					CLCD_voidSendCommand(0b00000001);
					CLCD_voidSendString("result=");
					Calculator(QueuePtr);
					break;
			/*clr screen*/
			case 15:CLCD_voidSendCommand(0b00000001);
					flag=1;
					clear_Queue(QueuePtr);
					break;
			case 16:Enqueue(0,QueuePtr);
					CLCD_voidSendData('0');
					break;
			case 255:break;
		}
	}
}
