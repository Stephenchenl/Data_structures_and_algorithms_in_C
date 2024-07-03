#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkQueue.h"


/**
 * @brief   ��ʽ�������
 * @param   que:���нṹ�壻data:����
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
 * @brief   ��ʽ���г���
 * @param   que:���нṹ�壻data:����
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