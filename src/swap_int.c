#include "../inc/my_library.h"


/*
交换两个整型变量的值
*/
void swap_int(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}