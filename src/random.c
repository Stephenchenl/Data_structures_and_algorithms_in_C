#include <time.h>
#include <stdlib.h>
#include "../inc/my_library.h"

/*
以时间序列为准生成随机数
*/
int* random(int a[],int length,int MaxNumber){
    //使用当前时间生成一个随机数种子
    srand(time(NULL));
    //生成随机数组，模运算代表生成随机数的范围为[0,MaxNumber-1]；
    for(int i = 0;i < length; i++){
        a[i] = rand() % MaxNumber;
    }

    return a;
}