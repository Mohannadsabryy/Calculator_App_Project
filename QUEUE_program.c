/*
 * QUEUE_program.c
 *
 *  Created on: Aug 26, 2023
 *      Author: user
 */
#include "STD_TYPES.h"
#include "QUEUE_interface.h"

void init(Queue *q){
    q->front=-1;
    q->rear=-1;
}
u8 isEmpty(Queue *q){
    if( (q->rear==-1 && q->front==-1) ){
        return 1;
    }
    else{
        return 0;
    }
}
u8 isFull(Queue *q){
    if((q->rear+1)%MAX_SIZE==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

u8 Enqueue(u8 element,Queue *q){
    if(isFull(q)==1){
        return 0xffffffff;
    }
    else if(isEmpty(q)){
            q->rear=0;
            q->front=0;
    }
    else{
        q->rear=(q->rear+1)%MAX_SIZE;
    }
    q->elements[q->rear]=element;
    return 1;
}
u8 Dequeue(Queue *q){
    if(isEmpty(q)==1){
        return 0xfffffff;
    }
    int element=q->elements[q->front];

    if(q->front==q->rear){

        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front=(q->front+1)%MAX_SIZE;
    }
    return element;
}
u8 Queue_size(Queue *q){
    if(isEmpty(q)){
        return 0;
    }
    else if(q->rear==q->front){
        return 1;
    }
    else if(q->rear > q->front){
        return (q->rear - q->front + 1);
    }
    else if(q->front > q->rear){
        return (MAX_SIZE-q->front) + (q->rear+1);
    }
}
void clear_Queue(Queue *q){
    q->front=-1;
    q->rear=-1;
}

