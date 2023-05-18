#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    int depth;
    struct tree *lchild;
    struct tree *rchild;
}Tree;

void print(Tree *t);
Tree *Insert(Tree *t, int data, int depth);

int main()
{
    int n, i, num, depth;
    Tree *t = NULL;
    scanf("%d", &n); //需要读入的个数
    
    for ( i = 0; i < n; i++)
    {
        depth = 0;
        scanf("%d", &num);
        t = Insert(t, num, depth);
    }
    print(t);
    return 0;
}

Tree *Insert(Tree *t, int data, int depth)
{
    depth++;
    if (t == NULL)
    {
        t = (Tree *)malloc(sizeof(Tree));
        t->data = data;
        t->lchild = t->rchild = NULL;
        t->depth = depth;
    }
    else if (data < t->data)
        t->lchild = Insert(t->lchild, data, depth);
    else if (data >= t->data)
        t->rchild = Insert(t->rchild, data, depth);
    return t;
}

void print(Tree *t)
{
    if (t)
    {
        if (!(t->lchild) && !(t->rchild))
        {
            printf("%d %d\n", t->data, t->depth);
        }
        print(t->lchild);
        print(t->rchild);
    }
}