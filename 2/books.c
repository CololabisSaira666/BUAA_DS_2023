#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *p1, const void *p2);

struct books
{
    char name[51];
    char author[21];
    char publish[31];
    char date[11];
}book[520];


int main()
{
    FILE *in, *out;
    in = fopen("books.txt", "r");
    out = fopen("ordered.txt", "w");
    int  i = 0;
    while (fscanf(in, "%s%s%s%s", book[i].name, book[i].author, book[i].publish, book[i].date) != EOF)
    {
        i++;
    }
    int len = i, op = 0;
    char key[51];
    while (scanf("%d", &op) != 0)
    {
        if (op == 1) //录入操作
        {
            scanf("%s%s%s%s", book[len].name, book[len].author, book[len].publish, book[len].date);
            len++;
        }
        else if (op == 2) //查找操作
        {
            scanf("%s", key);
            qsort(book, len, sizeof(book[0]), cmp);
            for ( i = 0; i < len; i++)
            {
                if (strstr(book[i].name, key) != NULL)
                {
                    printf("%-50s%-20s%-30s%-10s\n", book[i].name, book[i].author, book[i].publish, book[i].date);
                }
            }
        }
        else if (op == 3) //删除操作
        {
            scanf("%s", key);
            for ( i = 0; i < len; i++)
            {
                if (strstr(book[i].name, key) != NULL)
                {
                     book[i].name[0] = '\0';
                }
            }
        }
        else if (op == 0)
        {
            break;
        }
    }
    qsort(book, len, sizeof(book[0]), cmp);
    for ( i = 0; i < len; i++)
    {
        if (book[i].name[0] != '\0')
        {
            fprintf(out,"%-50s%-20s%-30s%-10s\n", book[i].name, book[i].author, book[i].publish, book[i].date);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}

int cmp(const void *p1, const void *p2)
{
    struct books *a = (struct books*)p1;
    struct books *b = (struct books*)p2;
    return strcmp(a->name, b->name);
}

