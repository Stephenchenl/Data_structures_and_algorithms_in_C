#include "../inc/my_library.h"


/*
在堆空间中创建字符串数组，
字符串本身是一级指针，因为存放字符串的数组就是二级指针

参数：
    int num：指定字符串数组的元素个数

返回值：返回这个字符串数组的指针
*/
char** string_array(int num){
    char **str_arr = (char **)malloc(num * sizeof(char *));
    if(str_arr == NULL){
        perror("Memory allocation failed!\n");
        exit(1);
    }

    return str_arr;
}

/*
在堆空间中创建字符串

参数：
    str_size：每个字符串允许的最大长度

返回值：返回指向字符串的指针
*/
char* str(int str_size){
    char *string = (char *)malloc(str_size * sizeof(char));
    if (string == NULL){
        perror("Memory allocation failed!\n");
        exit(1);
    }
    printf("please enter a string:\n");
    scanf("%s",string);

    return string;
}

//释放字符串数组的堆空间
void free_arr(char **arr,int size){
    for(int i=0; i < size; i++){
        free(arr[i]);
    }
    free(arr);
    printf("成功释放字符串数组的堆空间！\n");
}

//打印字符串数组
void print_arr(char **arr,int size){
    printf("字符串数组中包含：\n");
    for(int i=0; i < size; i++){
        printf("str_arr[%d]:",i);
        printf("%s\n",arr[i]);
    }
}


/*
往字符串数组中填充字符串：

char **str_arr = string_array(str_num);
for(int i=0; i < str_num; ++i){
        str_arr[i] = str(50);
        if(str_arr[i] == NULL){
            free_arr(str_arr,i);
            exit(EXIT_FAILURE);
        }
    }
*/