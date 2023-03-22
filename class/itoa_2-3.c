// 将一个整数转换为字符串？
#include <stdio.h>
#include <string.h>

void itoa(int n, char q[]);
void reserve(char s[]);
 
int main()
{
    int n; //输入的待转换的整型数
    char s[20];
    scanf("%d", &n);
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char q[]) //转换
{
    int i, sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        q[i++] = n % 10 +'0';
    } while ((n /= 10) > 0);
    if (sign < 0)
    {
        q[i++] = '-';
    }
    q[i] = '\0';
    reserve(q); // 倒转捏
}

void reserve(char s[])
{
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j ;i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }   
}