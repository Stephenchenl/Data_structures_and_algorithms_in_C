#include <stdio.h>
#include <stdlib.h>
#include "../inc/sort.h"

/**
 * @brief   冒泡排序
 * @param   arry[]：待排序的数组
 *          length：数组的长度
 * @return  无返回值
 * @note
 */
void bubble_sort(int arry[], int length)
{

    for (int i = 0; i < length - 1; i++)
    {
        int t = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arry[j] > arry[j + 1])
            {
                t = 1;
                int temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
            }
        }
        if (!t)
        {
            break;
        }
    }
}

/**
 * @brief   快速排序
 * @param   arr[]：待排序的数组
 *          low：第一个元素的索引
 *          high：最后一个元素的索引
 * @return  无返回值
 * @note
 */
void quicksort(int arr[], int low, int high){  
    if (low < high) {  
        int pi = partition(arr, low, high); //获取基准值的索引  
  
        quicksort(arr, low, pi - 1); //对基准值左边的子数组进行快速排序  
        quicksort(arr, pi + 1, high); //对基准值右边的子数组进行快速排序  
    }  
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //选择最后一个元素作为基准值  
    int i = (low - 1); //小于基准值的元素的索引  
  
    for (int j = low; j <= high - 1; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            swap_int(&arr[i], &arr[j]);  
        }  
    }  
    swap_int(&arr[i + 1], &arr[high]); //将基准值放到正确的位置上  
    return (i + 1); //返回基准值的索引  
}