#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   游程编码压缩--字符串版
 * @param   *str：待压缩字符串
 * @return  压缩后的字符串
 * @note
 */
char *runLengthEncodingInString(char *str)
{

    char *len = str;
    int strlen = 0;
    while (*len++ != '\0')
    {
        strlen++;
    }

    char *encoding = (char *)malloc(strlen * sizeof(char));
    if (encoding == NULL)
    {
        perror("malloc error");
        exit(1);
    }

    int maxstep = 5;
    char *run = str;
    char *temp = encoding;
    while (*run != '\0')
    {
        int count = 1;
        *temp = *run;
        while (*run == *temp)
        {
            if (*run == *(run + 1))
            {
                count++;
            }
            run++;
            if (count == maxstep)
            {
                run++;
                break;
            }
        }
        temp++;
        *temp = '0' + count;
        temp++;
    }
    *temp = '\0';

    return encoding;
}

/**
 * @brief   游程编码压缩--文件版
 * @param   *filename：待压缩文件
 * @return  压缩后的文件
 * @note
 */
// void runLengthEncodingInFile(const char *filename)
// {

//     FILE *file = fopen(filename, "r+");
//     if (file == NULL)
//     {
//         perror("fopen");
//         exit(1);
//     }

//     fseek(file, 0, SEEK_END);
//     int fileLen = ftell(file);
//     fseek(file, 0, SEEK_SET);
// }