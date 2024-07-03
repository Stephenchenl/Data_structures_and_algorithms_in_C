#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkQueue.h"


/**
 * @brief   链式队列入队
 * @param   que:队列结构体；data:数据
 * @return
 * @note
*/
void enQueue(LinkQueue *que, Element_t data){
    LinkQueueNode *node = malloc(sizeof(LinkQueueNode));
    node->data = data;
    node->next = NULL;

    if(que->rear){
        que->rear->next = node;
    }
    else {
        que->front = node;
    }
    que->rear = node;
}

/**
 * @brief   链式队列出队
 * @param   que:队列结构体；data:数据
 * @return
 * @note
*/
void dnQueue(LinkQueue *que, Element_t data){
    LinkQueueNode *bak;
    if(que->front){
        bak = que->front;
        *data = que->front->data;
        que->front = que->front->next;
        free(bak);
        if(que->front == NULL){
            que->rear = NULL;
        }
    }
}