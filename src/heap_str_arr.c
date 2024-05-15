#include "../inc/my_library.h"


char** string_array(int num){
    char **str_arr = (char **)malloc(num * sizeof(char *));
    if(str_arr == NULL){
        perror("Memory allocation failed!\n");
        exit(1);
    }

    return str_arr;
}


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


void free_arr(char **arr,int size){
    for(int i=0; i < size; i++){
        free(arr[i]);
    }
    free(arr);
    printf("\n");
}


void print_arr(char **arr,int size){
    printf("\n");
    for(int i=0; i < size; i++){
        printf("str_arr[%d]:",i);
        printf("%s\n",arr[i]);
    }
}