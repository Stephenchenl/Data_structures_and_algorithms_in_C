#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../inc/string.h"



int main() {

    char c1[10] = "0b0011";
    uint32_t count = stringToDecimal(c1);
    printf("%lu\n",count);


    system("pause");

    return 0;
}