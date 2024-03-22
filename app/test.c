#include <stdio.h>
#include <stdlib.h>
#include "../inc/my_library.h"

int main(){

    int a[100]; //定义一个数组，元素用随机数填充
    int a_len = sizeof(a)/sizeof(a[0]); //计算数组大小

    random(a,a_len,101);

    //打印数组
    for(int x = 0;x < a_len;x++){
        printf("%d ",a[x]);
    }
    printf("\n");

    //冒泡排序
    for(int i = 0; i < a_len-1; i++){  
        for(int j = 0; j < a_len-i-1; j++){  
            if(a[j] < a[j+1]){  
                // 交换 arr[j] 和 arr[j+1]  
                int temp = a[j];  
                a[j] = a[j+1];  
                a[j+1] = temp;  
            }
        }
    }

    //打印数组
    for(int x = 0;x < a_len;x++){
        printf("%d ",a[x]);
    }
    printf("\n");

    system("pause");

    return 0;
}

// int partition(int array[],int smaller,int bigger){
//     int basic = array[bigger];
//     int i = smaller -1;
//     for(int j = smaller;j < bigger; ++i){
//         if(array[i] > basic){
//             i++;
//             swap_int(&array[i],&array[j]);
//         }
//     }
//     swap_int(&array[i+1],&array[bigger]);

//     return i+1;
// }

// void quick_sort(int array[],int smaller,int bigger){
//     if(smaller < bigger){
//         int part = partition(array,smaller,bigger);
//         quick_sort(array,smaller,part - 1);
//         quick_sort(array,part + 1,bigger);
//     }
// }