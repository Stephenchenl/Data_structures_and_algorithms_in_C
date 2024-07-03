#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/lineList.h"


/**
 * @brief   ����˳�������̬�����ڴ�
 * @param   capacity��˳������󳤶�
 * @return  ����˳����ָ��
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
 * @brief   �ͷ�˳����������ڴ�
 * @param   list����Ҫ�ͷŵ�˳���
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
 * @brief   �ڱ�β����Ԫ��
 * @param   list��˳���
 *          value���������ֵ
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
 * @brief   ȡ��˳������һ��Ԫ��
 * @param   list��˳���
 *          value����ȡ���ı�βԪ��
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
 * @brief   ����չʾ˳���
 * @param   list��˳���
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
 * @brief   �п�
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
 * @brief   ����
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