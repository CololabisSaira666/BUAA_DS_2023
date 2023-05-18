#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

typedef struct tree {
    int type;
    int num;
    char op;
    int son[2];
}Tree;

char expr[MAX]; // 读入的表达式
int num[MAX] = {0}, ans[MAX];
char op[MAX] = {0};

int Top[MAX]; //转换后的长度

void conversion(char expr[]);
void suffix(char E[]);

int main() {
    int tree_top = 0;
    Tree tree_tree[MAX];
    int stack[MAX];
    int i = 0, j = 0;
    gets(expr);
    conversion(expr);
    suffix(expr);
    int k = 0;
    for ( i = 0; expr[i] != '\0'; i++)
    {
        if (num[i] == 0 && op[i] == '\0')
        {
            break;
        }
        if(op[i] == '+' || op[i] == '-' || op[i] == '*' || op[i] == '/')
        { //属于操作符号
            //printf("%c ", op[i]);
            k = k-2;
            tree_tree[j].type = 1;
            tree_tree[j].op = op[i];
            tree_tree[j].son[0] = Top[k];
            tree_tree[j].son[1] = Top[k+1];
            Top[k] = j;
            tree_top = Top[k];
            j++;
            k++;
        }
        else
        { // 属于操作数
            //printf("%d ", num[i]);
            tree_tree[j].type = 0;
            tree_tree[j].num = num[i];
            Top[k++] = j;
            j++;
        }
    }
    printf("\n");
    int top = -1;
    if (i != 1)
    {
        printf("%c ", tree_tree[tree_top].op);
        k = tree_tree[tree_top].son[0];
        j = tree_tree[tree_top].son[1];
        if (tree_tree[k].type == 1)
            printf("%c ", tree_tree[k].op);
        else printf("%d ", tree_tree[k].num);
        if (tree_tree[j].type == 1)
            printf("%c", tree_tree[j].op);
        else printf("%d", tree_tree[j].num);
    }
    else
    {
        printf("%d", num[0]);
    }
    printf("\n");


    for ( i = 0; expr[i] != '\0'; i++)
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
    printf("%d", ans[top]);

    return 0;
}

void conversion(char expr[]) 
{//转换表达式，去掉空格并存储
    int i, j;
    for ( i = 0; expr[i] != '='; i++){
        if (expr[i] != ' ')
        {
            expr[j++] = expr[i];
        }
    }
    expr[j] = '\0';
}

void suffix(char E[]) 
{
    int i, j = 0, stacktop = -1;
    char stack[201] = {0};
    for ( i = 0; expr[i] != '\0'; i++)
    {
        while (isdigit(expr[i]))
        {
            num[j] = num[j] * 10 + expr[i++] - '0';
            if (!isdigit(expr[i]))
            {
                j++;
            }
        }
        if (expr[i] == '\0')
        {
            break;
        }
        if (expr[i] == '(')
        {
            stacktop++;
            stack[stacktop] = expr[i];
            
        }
        else if (expr[i] == '+' || expr[i] == '-')
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
            stack[stacktop] = expr[i];
        }
        else if (expr[i] == '*' || expr[i] == '/')
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
            stack[stacktop] = expr[i];
        }
        else if (expr[i] == ')')
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
