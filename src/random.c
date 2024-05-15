#include "../inc/my_library.h"


int* random(int a[],int length){

    srand(time(NULL));
    for(int i = 0;i < length; i++){
        a[i] = rand() % (length+1);
    }

    return a;
}