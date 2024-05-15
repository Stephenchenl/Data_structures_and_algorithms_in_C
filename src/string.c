#include "../inc/my_library.h"



int stringLength(char *str) {
    int num = 0;
    while(*str++) {
        num++;
    }

    return num;
}


int stringCompare(char *str1, char *str2) {
    int ret = 0;
    while(ret == 0 && (*str1 || *str2)){
        if((*str1 - *str2) < 0) {
            ret = -1;
            *str1++;
            *str2++;
        }
        else if((*str1 - *str2) > 0) {
            ret = 1;
            *str1++;
            *str2++;
        }
        else {
            *str1++;
            *str2++;
        }
    }
    
    return ret;
}

double stringToFloat(char *digits){
    char *p1 = digits;
    char *p2 = digits;
    double inte = 0;
    double frac = 0;
    double ret;
    int i = 0;
    int j = -1;

    while(*p1 != '.'){
        p1++;
    }
    p1--;
    while(*p2 != '.'){
        p2++;
    }
    p2++;

    while(p1 != digits){
        inte += (*p1 - '0') * pow(10,i);
        i++;
        p1--;
    }
    inte += (*digits - '0') * pow(10,i);

    while (*p2){
        frac += (*p2 - '0') * pow(10,j);
        j--;
        p2++;
    }

    ret = inte + frac;

    return ret;
}

uint8_t parse(const char *inst){
    int i=0;
    uint8_t num = 0;

    for(i; i<8; i++){
        num += (inst[i] -'0') * pow(2,(7-i));
    }
    
    return num;
}