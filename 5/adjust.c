#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct tree
{
    int i;
    struct tree *child[3];
}Tree, *nTree;

typedef struct node 
{
    int i;
    int num; // 人流量
}Node;

Tree Structure[300];
int top = 0;
int q[1000];
Node pos[300];

void traversal(nTree root);
int cmp(const void *p1, const void *p2);

int main()
{
    int r, s; //分支节点以及信号
    scanf("%d", &r);
    int i, j, k;
    while (r != -1) //输入树结点之间的关系
    {
        Structure[r].i = r;
        i = 0;
        scanf("%d", &s);
        while (s != -1)
        {
            Structure[r].child[i] = &Structure[s];
            Structure[s].i = s;
            i++;
            scanf("%d", &s);
        }
        scanf("%d", &r);
    }
    //printf("1\n");
    traversal(&Structure[100]);
    //printf("%d", top);

    for ( i = 0; i < top; i++)
        scanf("%d %d", &pos[i].i, &pos[i].num);
    qsort(pos, top, sizeof(Node), cmp);
    for (i = 0; i < top; i++)
        printf("%d->%d\n", pos[i].i, q[i]);

    return 0;
}

void traversal(nTree root)
{
    nTree Q[200], p;
	int front, rear, i;
    if(root != NULL)
    {
        Q[0] = root;
        front = -1;
        rear = 0;
        while (front < rear)
        {
            p = Q[++front];
            if (p->child[0]==NULL && p->child[1]==NULL && p->child[2]==NULL)
                q[top++] = p->i;
            for ( i = 0; i < 3; i++)
            {
                if(p->child[i] != NULL)
                    Q[++rear] = p->child[i];
            }
        }
    }
}

int cmp(const void *p1, const void *p2)
{
    Node *a = (Node *)p1;
    Node *b = (Node *)p2;
    if (a->num != b->num)
        return b->num - a->num;
    else 
        return a->i - b->i;
    
}