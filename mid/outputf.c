#include <stdio.h>
#include <string.h>

#define MAX 105

int main()
{
    char format[MAX], s[MAX];
    int i, m = 0, n = 0, len;
    int flag = 0; // 是否存在-
    gets(format);
    gets(s);
    if (format[1] == '-')
    {
        flag = 1;
        i = 2;
    }
    else{
        i = 1;
    }    
    for ( ; format[i] >= '0' && format[i] <= '9'; i++)
    {
        m = 10*m + format[i] - '0';
    }
    i++;
    for ( ; format[i] >= '0' && format[i] <= '9'; i++)
    {
        n = 10*n + format[i] - '0';
    }
    //printf("%d %d %d", flag, m, n);
    len = strlen(s);
    //printf("%d", len);
    if (flag == 0) // 左对齐
    {
        if (m >= len) // 字符串全部输出
        {
            if (n > len)
            {
                for ( i = 0; s[i]!='\0'; i++)
                {
                    printf("%c", s[i]);
                }
                i = n-len;
                while (i >= 1)
                {
                    printf("#");
                    i--;
                }
            }
            else
            {
                for ( i = 0; s[i]!='\0'; i++)
                {
                    printf("%c", s[i]);
                }
            }
        }
        else
        {
            if (n > m)
            {
                
                for ( i = 0; i<m; i++)
                {
                    printf("%c", s[i]);
                }
                i = n-m;
                while (i >= 1)
                {
                    printf("#");
                    i--;
                }
            }
            else
            {
                for ( i = 0; i<m; i++)
                {
                    printf("%c", s[i]);
                }
            }
        }
    }
    else // 右对齐
    {
        if (m >= len) // 字符串全部输出
        {
            if (n > len)
            {
                i = n-len;
                while (i >= 1)
                {
                    printf("#");
                    i--;
                }
                for ( i = 0; s[i]!='\0'; i++)
                {
                    printf("%c", s[i]);
                }
                
                
            }
            else
            {
                for ( i = 0; s[i]!='\0'; i++)
                {
                    printf("%c", s[i]);
                }
            }
        }
        else
        {
            if (n > m)
            {
                i = n-m;
                while (i >= 1)
                {
                    printf("#");
                    i--;
                }
                for ( i = 0; i<m; i++)
                {
                    printf("%c", s[i]);
                }
                
                
            }
            else
            {
                for ( i = 0; i<m; i++)
                {
                    printf("%c", s[i]);
                }
            }
        }
    }
    
}

