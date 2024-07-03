#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/lineList.h"


/**
 * @brief   创建顺序表，并动态分配内存
 * @param   capacity：顺序表的最大长度
 * @return  返回顺序表的指针
 * @note
*/
LineList_t* createLineList(int capacity){
    LineList_t *list = (LineList_t *)malloc(sizeof(LineList_t));
    list->data = (Element_t *)malloc(capacity * sizeof(Element_t));
    list->cur_len = 0;
    list->capacity = capacity;

    return list;
}


/**
 * @brief   释放顺序表及其分配的内存
 * @param   list：需要释放的顺序表
 * @return  
 * @note
*/
void releaselineList(LineList_t *list){
    if(list){
        if(list->data){
            free(list->data);
        }
        free(list);
    }
}

/**
 * @brief   在表尾插入元素
 * @param   list：顺序表
 *          value：待插入的值
 * @return
 * @note
*/
void pushlineList(LineList_t *list, Element_t value){

    if(!isFull(list)){
        Element_t *tmp = malloc(list->capacity * 2);
        for(int i=0; i < list->cur_len; i++){
            tmp[i] = list->data[i];
        }
        free(list->data);
        list->data = tmp;
        list->capacity *= 2;
    }
    list->data[list->cur_len++] = value;
}

/**
 * @brief   取出顺序表最后一个元素
 * @param   list：顺序表
 *          value：待取出的表尾元素
 * @return
 * @note
*/
void poplineList(LineList_t *list){

    if(!isEmpty(list)){
        list->cur_len--;
    }
    else{
        perror("list is empty");
    }

}

/**
 * @brief   遍历展示顺序表
 * @param   list：顺序表
 * @return
 * @note
*/
void showLineList(const LineList_t *list){

    for(int i=0; i < list->cur_len; i++){
        printf("%d ",list->data[i]);
    }
    printf("\n");
}

/**
 * @brief   判空
 * @param
 * @return
 * @note
*/
bool isEmpty(LineList_t *list){
    if(list->cur_len){
        return false;
    }

    return true;
}

/**
 * @brief   判满
 * @param
 * @return
 * @note
*/
bool isFull(LineList_t *list){
    if(list->cur_len >= list->capacity){
        return true;
    }

    return false;
}