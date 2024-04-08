/*
 * CLCD_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: user
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidInit(void);
void CLCD_voidSendString(u8 *Copy_pu8String);
void CLCD_voidSetXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition);
void CLCD_voidPrintCustomData(u8 *Copy_u8Data,u8 Copy_u8PatternNum,u8 Copy_u8XPosition,u8 Copy_u8YPosition);
void CLCD_voidSendCompleteNum(u8 Copy_u8Num);
#endif /* CLCD_INTERFACE_H_ */
