#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//生成伪随机数
int* random(int a[],int length);

/*
排序算法
*/
//冒泡排序
void bubble_sort(int arry[],int length);
//快速排序
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);


char** string_array(int num);
char* str(int str_size);
void free_arr(char **arr,int size);
void print_arr(char **arr,int size);

/*
字符串相关操作
*/
//计算字符串长度
int stringLength(char *str);
//比较字符串的大小
int stringCompare(char *str1, char *str2);
//将字符串转化成单精度浮点型
double stringToFloat(char *digits);
//将字符串转换成二进制
uint8_t parse(const char *inst);



#endif  //MY_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>