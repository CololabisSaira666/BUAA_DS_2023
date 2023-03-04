#include<stdio.h>
int mark[10] = {0};
char stack[11]; // 生成的全排列数字串
void num(int m, int n);
int Num;


int main()
{
	scanf("%d",&Num);
	num(0, Num);
	return 0;
}

void num(int m, int n)
{
    int i;
    if (n == 0)
    {
        stack[m] = '\0';
        for(i = 0; i <= Num; i++)
        {
            printf("%c ", stack[i]);
        }
        printf("\n");
        //puts(stack); //输出
        return;
    }
    for ( i = 1; i <= Num; i++)
    {
        if (mark[i] == 0) //此前未使用
        {
            mark[i] = 1;
            stack[m] = '0' + i; // 放置当前数字
            num(m+1, n-1);
            mark[i] = 0;
        }
    }    
    
}