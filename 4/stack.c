#include <stdio.h>

#define MAXSIZE 100

int top = -1;

int main()
{
    int stack[MAXSIZE];
    int op, num;
    scanf("%d", &op);
    while (op != -1)
    {
        
        if (op == 1)
        {
            scanf("%d", &num);
            if (isFULL())
            {
                printf("error ");
            }
            else
            {
                top++;
                stack[top] = num;
            }
        }
        else if (op == 0)
        {
            if (isEmpty())
            {
                printf("error ");
            }
            else
            {
                printf("%d ", stack[top]);
                top--;
            }
        }
        scanf("%d", &op);
    }
    
    return 0;
}

int isEmpty()
{
    return top == -1;
}

int isFULL()
{
    return top == MAXSIZE - 1;
}