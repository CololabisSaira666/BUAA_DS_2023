// 将数字字符串转换为整数
#include <stdio.h>

int atoi(char s[]);

int main()
{
    char s[20];
    scanf("%s", s);
    printf("%d\n", atoi(s));
    return 0;
}


int atoi(char s[])
{
    int i, n, sign;
    for ( i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++); 
    sign = 1; //第一个非空白字符存在，是数字或正负号，则开始转换
    if (s[i] == '+' || s[i] == '-')
    {
        sign = (s[i++] == '+') ? 1:-1;
    }
    for ( n = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = 10*n +s[i] - '0';
    }
    return (sign * n);
    
}