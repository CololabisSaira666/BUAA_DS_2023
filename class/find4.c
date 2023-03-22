// 文件的读写, 将一个文件内容拷贝到另一个文件
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1024

int indexing(char s[], char t[]);
int index2(char s[], char t[]);

int main()
{
    char filename[64], s[81], line[MAXLINE];
    FILE *fp;
    scanf("%s", filename); // 文件名
    scanf("%s", s); 
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open file %s!\n", filename);
        return 1;
    }
    while (fgets(line, MAXLINE, fp) != NULL)
    {
        if (indexing(line, s) >= 0)
        {
            printf("%s", line);
        }
        
    }
    fclose(fp);                                                                                                                                                                                    
    return 0;    
}

int indexing(char s[], char t[]) //查找某字符串捏, s[]文本，t[]待查找的文本
{
    int i, j, k;
    for ( i = 0; s[i] != '\0'; i++)
    {
        for ( j = i, k = 0; t[k] != '\0' && tolower(s[j]) == tolower(t[k]); j++, k++); // 大小写无关的查找
        if (t[k] == '\0')
        {
            return i; // 返回索引值
        }
    }
    return -1;
}

int index2(char s[], char t[]) //只需一层循环的字符串查找
{
    int i=0, j=0;
    while (s[i] != '\0' && t[j] != '\0')
    {
        if (s[i] == t[j]) // 若相等，则继续
        {
            i++;
            j++;
        }
        else // 若不相等，则
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (t[j] == '\0')
    {
        return i-j;
    }
    else
    {
        return -1;
    }
    
    
}