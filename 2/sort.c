#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2);

struct sort
{
    char name[25];
    char tel[12];
}list[105];


int main()
{
    int n, i, j;
    scanf("%d", &n);
    for ( i = 0; i < n; i++) // 读入
    {
        scanf("%s %s", list[i].name, list[i].tel);
    }
    for ( i = 0; i < n; i++)
    {
        int num = 1;
        for ( j = i + 1; j < n; j++)
        {
            if (strcmp(list[i].name, list[j].name) == 0 && strcmp(list[i].tel, list[j].tel) == 0)
            {
                strcpy(list[j].name, "\0");
            }
            if (strcmp(list[i].name, list[j].name) == 0 && strcmp(list[i].tel, list[j].tel) != 0)
            {
                int len = strlen(list[j].name);
                list[j].name[len] = '_';
                list[j].name[len+1] = num +'0';
                num++;
            }
        }  
    }
    qsort(list, n, sizeof(struct sort), cmp);
    for ( i = 0; i < n; i++)
    {
        if (strlen(list[i].name) != 0)
        {
            printf("%s %s\n", list[i].name, list[i].tel);
        }
    }
    return 0;
    
}
int cmp(const void *p1, const void *p2)
{
    struct sort *a = (struct sort*)p1;
    struct sort *b = (struct sort*)p2;
    return strcmp(a->name, b->name);
}