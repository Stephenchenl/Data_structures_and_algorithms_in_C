#include "../inc/compress.h"


/**
 * @brief   �γ̱���ѹ��
 * @param   *str����ѹ���ַ���
 * @return  ѹ������ַ���
 * @note
*/
// void runLengthEncoding(char *str){
//     char *temp = str;
//     int len = 0;
//     while(*temp != '\0'){
//         len++;
//     }

//     int maxstep = 5;
//     char *p = (char *)malloc(len * sizeof(char));
//     if(p == NULL){
//         perror("malloc error");
//         exit(1);
//     }
//     while (*str != '\0'){
//         int count = 0;
//         *p = *str;
//         *p++;
//         while (1){
//             if(*str == *(str+1)){
//                 count++;
//                 str++;
//             }
//             else{
//                 str++;
//                 *p = count;
//                 p++;
//                 break;
//             }
//         }
//     }
//     *p = '\0';
    

// }