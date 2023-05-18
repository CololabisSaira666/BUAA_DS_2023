#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 32

typedef struct tree
{
    char word[MAX];
    int count;
    struct tree *lchild;
    struct tree *rchild;
}Tree;

Tree *insert(Tree *p, char *w);
void print(Tree *p);

int main()
{
    FILE *in;
    char word[MAX], c;
    int i = 0;
    in = fopen("article.txt", "r");
    Tree *root = NULL, *p;
    while (1)
    {
        
        if(feof(in))
		{
			break;
		}
        c = fgetc(in);
        if (c >= 'A' && c <= 'Z')
        {
            c = tolower(c);
            word[i] = c;
            i++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            word[i] = c;
            i++;
        }
        else
        {
            word[i] = '\0';
            if (i != 0) // 读取到单词
            {
                //puts(word);
                root = insert(root, word);
                i = 0; 
            }
        }
    }
    p = root;
    for ( i = 0; i < 3; i++)
    {
        if (p != NULL)
        {
            if (i != 0)
                printf(" ");
            printf("%s", p->word);
        }
        else
        {
            break;
        }
        p = p->rchild;
    }
    printf("\n");
    print(root);
    return 0;
}

Tree *insert(Tree *p, char *w)
{
    int cond;
    if (p == NULL)
    {
        p = (Tree *)malloc(sizeof(Tree));
        strcpy(p->word, w);
        p->count = 1;
        p->lchild = p->rchild = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->lchild = insert(p->lchild, w);
    else
        p->rchild = insert(p->rchild, w);
    return p;
}

void print(Tree *p)
{
    if (p != NULL)
    {
        print(p->lchild);
        printf("%s %d\n", p->word, p->count);
        print(p->rchild);
    }
    
}