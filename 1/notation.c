#include <stdio.h>
#include <string.h>

void negExp(char a[]);
void posExp(char a[]);

int main()
{
    char num[101] = {0};
	gets(num);
    if (num[0] == '0')
    {
        negExp(num);
    }
    else if (num[1] == '.') // 处理形如1.00232的小数
    {
        for (int i = 0; i < strlen(num); i++)
        {
            printf("%c", num[i]);
        }
        printf("e0");
    }
    else
    {
        posExp(num);
    }
     
    return 0;
}

void negExp(char a[]) // 处理形如0.0002, 0.000234的小数
{
    int i, k = 1;
    for ( i = 2; i < strlen(a); i++)
    {
        if (a[i] == '0')
        {
            k++;
        } 
        else break;
    }
    if (i == strlen(a)-1) // 0.00002类型的小数
    {
        printf("%ce-%d", a[i], i-1);
    }
    else // 0.002324类型的小数
    {
        printf("%c.", a[k+1]);
        for ( i = k+2; i < strlen(a); i++)
        {
            printf("%c", a[i]);
        }
        printf("e-%d", k);
    }
    
    return;
}

void posExp(char a[]) // 处理12.2321的小数
{
    int i, k=0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] != '.')
        {
            k++;
        } 
        else break;
    }
    printf("%c.", a[0]);
    for (i = 1; i < strlen(a); i++)
    {
        if (a[i] != '.')
        {
            printf("%c", a[i]);
        }   
    }
    printf("e%d", k-1);
    return;
}