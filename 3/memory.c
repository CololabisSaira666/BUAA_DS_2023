#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int addr;
    int len;
    struct node *link;
}Node;


int main()
{
    int n, i, addr, len;
    Node *p, *q, *now=NULL, *head = NULL;

    int op, minlen, /*minaddr,*/ flag = 0;
    Node *output = NULL, *now_ = NULL, *before = NULL;

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        q=(Node *)malloc(sizeof(Node));
        scanf("%d%d", &addr, &len);
        q->addr = addr; q->len = len;
        q->link = NULL;
        if (head == NULL)
        {
            head = p = q;
        }
        else
        {
            p->link = q;
        }
        p=q;
        //printf("%d %d\n", p->addr, p->len);
    }
    p->link = head;
    now_ = p;
    //查找是否存在：
    
    scanf("%d", &op);
    while (op != -1)
    {
        for ( now = head; now; now = now->link)
        {
            if (now->len >= op)
            {
                if (flag == 0) // 第一次查找到空闲
                {
                    flag = 1;
                    //minaddr = now->addr;
                    minlen = now->len;
                    output = now; //指向当前的空闲
                    before = now_;
                
                }
                if ((now->len < minlen) && flag == 1)
                {
                    //minaddr = now->addr;
                    minlen = now->len;
                    output = now;
                    before = now_;
                }
            }
            
            now_ = now;
            
            if (now->link == head) //完成了一次循环遍历
            {
                //now_=now->link;
                break;
            }
            
        }
        if (flag == 1) //查询到空闲块
        {
            if(minlen > op) //分配后仍有剩余
            {
                output->len = output->len - op;
                head = output;
                now_ = before;
            }
            else if (minlen == op)
            {
                n--;
                now_ = before;
                head = output->link;
                before->link = head;
                free(output);
            }
        }
        flag = 0;
        //now_ = head;
        scanf("%d", &op);
    }

    
    for ( now = head, i = 0; i < n; i++, now = now->link)
    {
        printf("%d %d\n", now->addr, now->len);
        /*
        if (now->link == head) //完成了一次循环遍历
            {
                break;
            }
        */
    }
    return 0;
}