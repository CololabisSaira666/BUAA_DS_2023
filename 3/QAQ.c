#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int addr;
    int len;
    struct node *next;
}Node;

int main()
{
    Node *head, *p, *q, *t1, *now, *output;
    int n, i, addr, len, op, flag = 0, minlen;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    p = head;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        q = (Node *)malloc(sizeof(Node));
        scanf("%d%d", &addr, &len);
        q->addr = addr;
        q->len = len;
        q->next = NULL;

        p->next = q;
        p = q;
    }
    p->next = head->next;
    t1 = p;
    now = head;
    scanf("%d", &op);
    while (op != -1)
    {
        now = now->next;
        for ( ; ; t1 = now, now = now->next)
        {
            if (now->len >= op)
            {
                if (flag == 0)
                {
                    flag = 1;
                    minlen = now->len;
                    output = now;
                }
                if ((now->len < minlen) && flag == 1)
                {
                    /* code */
                }
                
            }
            if (now->next == head->next)
            {
                break;
            }
            
        }
        
        flag = 0;
        scanf("%d", &op);
    }
    
}