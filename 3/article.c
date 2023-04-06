#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 32

typedef struct article
{
    char word[MAX];
    int count;
    struct article *link;
}WordList;
int search(WordList *List, char s[]);
WordList *insert(WordList *List, char s[]);

int cmp(char a[], char b[]);

int main()
{
    WordList *t;
    FILE *in;
    WordList *List = NULL;
    char word[MAX], c;
    int i = 0;
    in = fopen("article.txt", "r");
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
                List = insert(List, word);
                i = 0; 
            }
        }
    }
    for ( t = List; t != NULL; t = t->link)
    {
        printf("%s %d\n", t->word, t->count);
    }
    fclose(in);
    return 0;
}

WordList *insert(WordList *List, char s[]) //查找并插入
{
    WordList *p, *q, *r;
    if (search(List, s))
    {
        p = (WordList *)malloc(sizeof(WordList));
        strcpy(p->word, s);
        p->count = 1;
        if (List == NULL || cmp(s, List->word))
        {
            p->link = List;
            List = p;
        }
        else
        {
            r = List;
            for ( q = List; q != NULL; r = q, q = q->link)
            {
                if (cmp(s, q->word))
                {
                    break;
                }
                
            }
            //p = r->link;
            p->link = q;
            r->link = p;
            
        }
    }
    return List;
}

int search(WordList *List, char s[])
{
    WordList *p;
    if (List == NULL)
    {
        return 1;  
    }
    for ( p = List; p != NULL;p = p->link)
    {
        if (strcmp(s, p->word) == 0)
        {
            p->count++;
            return 0;
        }
    }
    if (p == NULL)
    {
        return 1; //没有相同的单词
    }
}

int cmp(char a[], char b[])
{
    if (strcmp(a, b) < 0)
    {
        return 1;
    }
    else return 0;
}