#include <stdio.h>
#include <string.h>
#include <ctype.h>

double num[201], ans[201];
char op[201];

void suffix(char s[]);

int main()
{
    int i, j = 0, top = -1;
    char x[202] = {0}, cal[202] = {0};
    //memset(num,-1,sizeof(num));
    gets(x);
    for ( i = 0; x[i] != '\0'; i++)
    {
        if (x[i] != ' ' && x[i] != '=')
        {
            cal[j] = x[i];
            j++;
        }
    }
    cal[j] = '\0';
    suffix(cal);
    puts(op);
    for ( i = 0; cal[i] != '\0'; i++)
    {
        if (num[i] != 0)
        {
            top++;
            ans[top] = num[i];
        }
        else if (op[i] != '\0')
        {
            switch (op[i])
            {
            case '+':
                ans[top-1] = ans[top-1] + ans[top];
                break;
            case '-':
                ans[top-1] = ans[top-1] - ans[top];
                break;
            case '*':
                ans[top-1] = ans[top-1] * ans[top];
                break;
            case '/':
                ans[top-1] = ans[top-1] / ans[top];
                break;
            default:
                break;
            }
            ans[top] = 0;
            top--;
        }
        if (num[i] == 0 && op[i] == '\0')
        {
            break;
        }
        
    }
    //printf("%d\n", top);
    printf("%.2lf", ans[top]);
    return 0;
}

void suffix(char s[])
{
    int i, j = 0, stacktop = -1;
    char stack[201] = {0};
    for ( i = 0; s[i] != '\0'; i++)
    {
        while (isdigit(s[i]))
        {
            num[j] = num[j] * 10 + s[i++] - '0';
            if (!isdigit(s[i]))
            {
                j++;
            }
        }
        if (s[i] == '\0')
        {
            break;
        }
        if (s[i] == '(')
        {
            stacktop++;
            stack[stacktop] = s[i];
            
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (stacktop > -1)
            {
                if (stack[stacktop] == '(')
                {
                    break;
                }
                else op[j++] = stack[stacktop--];
            }
            stacktop++;
            stack[stacktop] = s[i];
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (stacktop > -1)
            {
                if (stack[stacktop] == '(' || stack[stacktop] == '+' || stack[stacktop] == '-')
                {
                    break;
                }
                else op[j++] = stack[stacktop--];  
            }
            stacktop++;
            stack[stacktop] = s[i];
        }
        else if (s[i] == ')')
        {
            while (stack[stacktop] != '(' && stacktop > -1)
            {
                op[j++] = stack[stacktop--];
            }
            stacktop--;
        }
    }
    while (stacktop > -1)
    {
        op[j++] = stack[stacktop--];
    }
}
