#include <stdlib.h>
#include <stdio.h>
#include "../inc/linkShed.h"


/**
 * @brief   ��ʽջ��ջ
 * @param   top:ͷָ�룻data:����
 * @return  ������ջ֮���ͷָ��
 * @note
*/
LinkShedNode *pushShed(LinkShedNode *top, Element_t data){
    LinkShedNode *node = malloc(sizeof(LinkShedNode));
    if(node == NULL){
        perror("malloc");
        return top;
    }
    node->data = data;
    node->next = top;
    return node;
}

/**
 * @brief   ��ʽջ��ջ
 * @param   top:ͷָ�룻data:����
 * @return  ���س�ջ֮���ͷָ��
 * @note
*/
LinkShedNode *popShed(LinkShedNode *top, Element_t data){
    LinkShedNode *tmp = top->next;
    *data = top->data;
    free(top);

    return tmp;
}
