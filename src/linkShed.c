#include <stdlib.h>
#include <stdio.h>
#include "../inc/linkShed.h"


/**
 * @brief   链式栈入栈
 * @param   top:头指针；data:数据
 * @return  返回入栈之后的头指针
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
 * @brief   链式栈出栈
 * @param   top:头指针；data:数据
 * @return  返回出栈之后的头指针
 * @note
*/
LinkShedNode *popShed(LinkShedNode *top, Element_t data){
    LinkShedNode *tmp = top->next;
    *data = top->data;
    free(top);

    return tmp;
}
