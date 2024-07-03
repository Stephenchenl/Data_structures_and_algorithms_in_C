#include <stdio.h>
#include <stdlib.h>
#include "../inc/sort.h"

/**
 * @brief   ð������
 * @param   arry[]�������������
 *          length������ĳ���
 * @return  �޷���ֵ
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
 * @brief   ��������
 * @param   arr[]�������������
 *          low����һ��Ԫ�ص�����
 *          high�����һ��Ԫ�ص�����
 * @return  �޷���ֵ
 * @note
 */
void quicksort(int arr[], int low, int high){  
    if (low < high) {  
        int pi = partition(arr, low, high); //��ȡ��׼ֵ������  
  
        quicksort(arr, low, pi - 1); //�Ի�׼ֵ��ߵ���������п�������  
        quicksort(arr, pi + 1, high); //�Ի�׼ֵ�ұߵ���������п�������  
    }  
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; //ѡ�����һ��Ԫ����Ϊ��׼ֵ  
    int i = (low - 1); //С�ڻ�׼ֵ��Ԫ�ص�����  
  
    for (int j = low; j <= high - 1; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            swap_int(&arr[i], &arr[j]);  
        }  
    }  
    swap_int(&arr[i + 1], &arr[high]); //����׼ֵ�ŵ���ȷ��λ����  
    return (i + 1); //���ػ�׼ֵ������  
}