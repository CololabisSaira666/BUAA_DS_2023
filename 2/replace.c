#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1024

void strReplace(char line[], char in[], char out[], FILE *out_txt);

int main()
{
    FILE *in_txt, *out_txt;
    in_txt = fopen("filein.txt", "r");
    out_txt = fopen("fileout.txt", "w");
    char str1[100], str2[100], line[MAXLINE];
    scanf("%s", str1);
    scanf("%s", str2);
    while (fgets(line, MAXLINE, in_txt) != NULL)
    {
        strReplace(line, str1, str2, out_txt);
    }
    
    fclose(in_txt);
    fclose(out_txt);
    return 0;
}

void strReplace(char line[], char in[], char out[], FILE *out_txt) // 替换
{
    int i = 0, j = 0, k, flag;
    int c;
    while (line[i] != '\0')
    {
        if (tolower(line[i]) == tolower(in[j])) // 若相等，则继续查找
        {
            i++;
            j++;
        }
        else // 若不相等，则写入，返回上一位置继续查找
        {
            if (j == 0)
            {
                c = line[i];
                fputc(c, out_txt);
                i++;
            }
            else
            {
                for (flag = i - j ; flag < i; flag ++)
                {
                    c = line[flag];
                    fputc(c, out_txt);
                }
            }
            j = 0;
        }
        if (in[j] == '\0') //若查找到
        {
            for ( k = 0; k < strlen(out); k++) //写入代替换的字符串
            {
                c = out[k];
                fputc(c, out_txt);
            }
            j = 0;
        }
    }
}