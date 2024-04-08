/*
 * QUEUE_interface.h
 *
 *  Created on: Aug 26, 2023
 *      Author: user
 */

#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_

#define MAX_SIZE 32
typedef struct{
	u8 elements[MAX_SIZE];
	u8 front;
	u8 rear;
}Queue;

void init(Queue *q);
u8 Enqueue(u8 element,Queue *q);
u8 Dequeue(Queue *q);
u8 isEmpty(Queue *q);
u8 isFull(Queue *q);
u8 Queue_size(Queue *q);
void clear_Queue(Queue *q);


#endif /* QUEUE_INTERFACE_H_ */
