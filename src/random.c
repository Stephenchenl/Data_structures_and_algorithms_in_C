#include "../inc/tool.h"


/**
 * @brief   生成伪随机数数组
 * @param   a[]：存放随机数的数组
 *          length：数组的长度，同时是随机数的范围
 * @return  返回随机数组
 * @note
*/
int* random(int a[],int length){

    srand(time(NULL));
    for(int i = 0;i < length; i++){
        a[i] = rand() % (length+1);
    }

    return a;
}