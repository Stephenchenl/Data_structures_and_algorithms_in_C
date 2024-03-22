#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

int* random(int a[],int length); //生成[0,length+1]范围的随机数组

void swap_int(int *a,int *b);    //交换两个整型变量的值

void bubble_sort(int arry[],int length);   //冒泡排序

/*
快速排序
*/
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

#endif  //MY_LIBRARY_H