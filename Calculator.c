/*
 * Calculator.c
 *
 *  Created on: Aug 28, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "Math.h"
#include "QUEUE_interface.h"
#include "CLCD_interface.h"
#include "Calculator.h"
void Calculator(Queue *ptr){
	s8 local_var1,local_var2;
	u8 local_op;
	static s8 Slocal_result=0;
	extern u8 flag;
	if(flag==1){
		Slocal_result=0;
	}
	flag=0;
	u8 i=Dequeue(ptr);
	i=Dequeue(ptr);
	while(i!=plus_op && i!=minus_op && i!=mult_op && i!=div_op){
		Slocal_result*=10;
		Slocal_result=Slocal_result+i;
		i=Dequeue(ptr);
	}
	local_var1=Slocal_result;
	Slocal_result=0;
	local_op=i;
	i=Dequeue(ptr);
	while(i!=equal){
		Slocal_result*=10;
		Slocal_result=Slocal_result+i;
		i=Dequeue(ptr);
	}
	local_var2=Slocal_result;
	//to handle if first variable is -ve
	if((local_op==minus_op && local_var2>local_var1) || (local_var1<0 && abs(local_var1)>local_var2 &&local_op==plus_op )||(local_var1<0 && (local_op==mult_op || local_op==div_op) )){
		CLCD_voidSendData('-');
	}
	switch(local_op){
		case plus_op:Slocal_result=local_var1+local_var2;break;
		case minus_op:Slocal_result=local_var1-local_var2;break;
		case mult_op:Slocal_result=local_var1*local_var2;break;
		case div_op:Slocal_result=local_var1/local_var2;break;
	}
	if(Slocal_result==0){
		CLCD_voidSendData('0');
	}
	else{
		CLCD_voidSendCompleteNum(abs(Slocal_result));
	}
}
