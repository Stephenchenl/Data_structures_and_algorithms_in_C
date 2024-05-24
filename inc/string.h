#ifndef STRING_H
#define STRING_H

//计算字符串中字符数
int stringLength(const char *str);
//比较两个字符串的大小
int stringCompare(const char *str1, const char *str2);
//将传入的字符串转换成浮点数
double stringToFloat(const char *digits);
//将传入的二、八、十六进制转换成十进制数值
uint32_t stringToDecimal(const char *inst);

#endif