#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * @brief   ����α���������
 * @param   a[]����������������
 *          length������ĳ��ȣ�ͬʱ��������ķ�Χ
 * @return  �����������
 * @note
*/
int* random(int a[],int length){

    srand(time(NULL));
    for(int i = 0;i < length; i++){
        a[i] = rand() % (length+1);
    }

    return a;
}