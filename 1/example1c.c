#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_value 512


int main()
{
    int a1 = 0, a2, a3;
    char op1 = '+', op2, op3;
    while (op1 != '=')
    {
        scanf("%d %c", &a2, &op2);
        while (op2 == '*' || op2 == '/') //如果是乘除
        {
            scanf("%d %c", &a3, &op3);
            if (op2 == '*') a2 *= a3;
            else if(op2 == '/') a2 /= a3;
            op2 = op3; //如果仍是乘除，继续运算，否则做加减运算
        }
        if (op1 == '+') a1 += a2; 
        else if(op1 == '-') a1 -= a2;
        op1 = op2; //关于优先级的问题捏
    }
    printf("%d", a1);
    return 0;
}