#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//����α�����
int* random(int a[],int length);

/*
�����㷨
*/
//ð������
void bubble_sort(int arry[],int length);
//��������
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);


char** string_array(int num);
char* str(int str_size);
void free_arr(char **arr,int size);
void print_arr(char **arr,int size);

/*
�ַ�����ز���
*/
//�����ַ�������
int stringLength(char *str);
//�Ƚ��ַ����Ĵ�С
int stringCompare(char *str1, char *str2);
//���ַ���ת���ɵ����ȸ�����
double stringToFloat(char *digits);
//���ַ���ת���ɶ�����
uint8_t parse(const char *inst);



#endif  //MY_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>