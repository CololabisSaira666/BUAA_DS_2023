#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    int count;
    struct node *link;
}Node;

int main()
{
    int n;
    scanf("%d", &n); //读入元素的个数
    int num;// 再次输入的数
    int add;//总的比较次数
    Node *p, *q, *before, *head;
    head=(Node *)malloc(sizeof(Node));
    head->link = NULL;
    scanf("%d", &num);
    q=(Node *)malloc(sizeof(Node));
    q->num = num;
    q->count = 1;
    q->link = NULL;
    head->link = q;
    p = q;
    n--;
    // 已经读取了第一个
    while (n)
    {
        scanf("%d", &num);
        p = head->link;
        before = head;
        for (;p != NULL; p = p->link)
        {
            add++;//增加比较次数
            if (p->num == num) //未比较
            {
                p->count++;
                //if (before != head) //元素不在链表头，要移动
                //{
                    before->link = p->link;
                    p->link = head->link;
                    head->link = p;
                    break;
                //}
            }
            
            before = p; // 更新前一位
        }
        if (p == NULL) //未查找到
        {
            q=(Node *)malloc(sizeof(Node));
            q->count = 1;
            q->num = num;
            q->link = NULL;
            before->link = q;
        }
        n--;
    }
    p = head->link;
    int i = 1;
    for (;p != NULL&& i<=5; p = p->link)
    {
        printf("%d %d\n", p->num, p->count);
        i++;
    }
    printf("%d", add);
    return 0;
}