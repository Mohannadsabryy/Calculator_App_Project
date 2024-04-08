/*
 * Math.c
 *
 *  Created on: Aug 28, 2023
 *      Author: user
 */

#include "STD_TYPES.h"
#include "Math.h"

s8 abs(s8 num){
	s8 result;
	if(num<0){
		return num*-1;
	}
	else{
		return num;
	}
}
