#ifndef STRING_H
#define STRING_H

//�����ַ������ַ���
int stringLength(const char *str);
//�Ƚ������ַ����Ĵ�С
int stringCompare(const char *str1, const char *str2);
//��������ַ���ת���ɸ�����
double stringToFloat(char *digits);
//������Ķ����ˡ�ʮ������ת����ʮ������ֵ
uint32_t stringToDecimal(char *inst);

#endif