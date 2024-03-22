#include <stdio.h>
#include "../inc/my_library.h"

/*
冒泡排序,从小到大

适用情况：基本只适合小数据排序，没什么优点

时间复杂度：O(n^2)

参数解释：
    int arry[]：整型数组
    int length：数组的元素个数

基本思想：从第一个开始依次对相邻的两个元素进行比较，
    如果是从小到大的排序，则当第一个元素大于第二个元素时交换，然后往后移动一步；
    反之亦然。
    直到进行了（数组长度-1）次排序才结束
    
优化：有时候可能存在已经是有序数列，但仍然没有结束排序循环的情况，
    这种情况下，我们可以设立一个标志位，当某一轮完全没有交换的时候就直接结束循环
*/
void bubble_sort(int arry[],int length){

    for(int i = 0; i < length-1; i++){
        int t = 0;  //用于检验是否有交换的标志位，默认为0
        for(int j = 0; j < length-i-1; j++){
            if(arry[j] > arry[j+1]){
                t = 1;  //标志位，用于检验此轮是否有交换
                // 交换 arr[j] 和 arr[j+1]
                int temp = arry[j];
                arry[j] = arry[j+1];
                arry[j+1] = temp;
            }
        }
        if(!t){
            printf("预计排序轮数：%d,实际排序轮数：%d\n",(length-1),(i+1));
            printf("排序已完成，提前结束。\n");
            break;
        }
    }

}