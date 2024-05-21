#include "../inc/string.h"


/**
 * @brief   �����ַ����ĳ��ȣ��ַ��ĸ�����
 * @param   *str��������ַ���
 * @return  �ַ������ַ��ĸ���
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
 * @brief   ʵ�������ַ����İ���ASCII��ĸ˳�����λ�Ƚ�
 * @param   *str1����һ���ַ���
 *          *str2���ڶ����ַ���
 * @return  ���str1 == str2������0��
 *          ���str1 > str2������1��
 *          ���str1 < str2������-1��
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
 * @brief   �������float��double��ʽ���ַ���ת����float��double��
 * @param   *digits������ĸ������ַ���
 * @return  ����ת����ĸ�������Ĭ�Ϸ���˫���ȸ�����
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
 * @brief   ������Ķ����ˡ�ʮ�����Ƶ��ַ���ת����ʮ���������
 * @param   *inst��������ַ���
 * @return  ����ת�����ʮ������ֵ
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