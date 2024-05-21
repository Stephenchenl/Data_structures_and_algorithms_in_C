#include "../inc/string.h"


/**
 * @brief   计算字符串的长度（字符的个数）
 * @param   *str：传入的字符串
 * @return  字符串中字符的个数
 * @note 
*/
int stringLength(const char *str) {
    int count = 0;
    for(int i = 0; *(str+i) != '\0'; i++){
        count++;
    }

    return count;
}


/**
 * @brief   实现两个字符串的按照ASCII字母顺序的逐位比较
 * @param   *str1：第一个字符串
 *          *str2：第二个字符串
 * @return  如果str1 == str2，返回0；
 *          如果str1 > str2，返回1；
 *          如果str1 < str2，返回-1；
 * @note
*/
int stringCompare(const char *str1, const char *str2) {
    int ret = 0;
    for(int i = 0; (ret == 0) && (*(str1+i) || *(str2+i)); i++){
        if((*(str1+i) - *(str2+i)) < 0) {
            ret = -1;
        }
        else if((*(str1+i) - *(str2+i)) > 0) {
            ret = 1;
        }
    }
    
    return ret;
}

/**
 * @brief   将传入的float、double形式的字符串转换成float、double数
 * @param   *digits：传入的浮点数字符串
 * @return  返回转换后的浮点数，默认返回双精度浮点数
 * @note
*/
double stringToFloat(const char *digits) {
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


/**
 * @brief   将传入的二、八、十六进制的字符串转换成十进制数输出
 * @param   *inst：传入的字符串
 * @return  返回转换后的十进制数值
 * @note
*/
uint32_t stringToDecimal(const char *inst) {
    int len = 0;
    char *temp = inst;
    while(*temp != '\0'){
        len++;
        temp++;
    }

    char type = '0';
    if(*inst == '0'){
        if(*(inst+1) == 'b'){
            type = 'b';
        }
        else if(*(inst+1) == 'x' || *(inst+1) == 'X'){
            type = 'x';
        }
        else if(*(inst+1) >= '0' && *(inst+1) <= '7'){
            type = 'o';
        }
        else{
            perror("input illegal");
        }
    }
    else{
        perror("input illegal");
    }

    int i = 0;
    uint32_t num = 0;
    switch(type) {
        case 'b':
            inst = inst+2;
            for(i; i < len-2; i++){
                num += (*(inst+i) - '0') * pow(2,((len-3)-i));
            }
            break;
        case 'o':
            for(i; i < len; i++){
                num += (*(inst+i) - '0') * pow(8,((len-1)-i));
            }
            break;
        case 'x':
            inst = inst+2;
            for(i; i < len-2; i++){
                num += (*(inst+i) - '0') * pow(16,((len-3)-i));
            }
            break;
        default:
            break;

    }
    
    return num;
}