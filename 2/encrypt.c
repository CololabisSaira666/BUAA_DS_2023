#include <stdio.h>

#define MAXLINE 1024

int main()
{
    FILE *in_txt, *out_txt;
    int c, line[MAXLINE];
    int i = 0, j = 25;
    in_txt = fopen("encrypt.txt", "r");
    out_txt = fopen("output.txt", "w");
    int word[26] = {0}; //存放加密顺序
    int flag[26] = {0}; //标记是否已经被填入
    while ((c=getchar()) != '\n')
    {
        if (flag[c - 'a'] == 0) //如果此前未被读入
        {
            word[i] = c - 'a';
            i++;
            flag[c - 'a'] = 1;
        }
    }
    for (; i < 26, j >= 0; j--)
    {
        if (flag[j] == 0) //从z开始反序追加
        {
            word[i] += j;
            i++; 
        }
    }
    while ((c = fgetc(in_txt)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + word[c - 'a'];
            fputc(c, out_txt);
        }
        else
        {
            fputc(c, out_txt);
        }
    }
    fclose(in_txt);
    fclose(out_txt);
    return 0;
}