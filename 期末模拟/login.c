#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct login
{
    int id;
    char name[20];
    int m; //机器号
    int time; // 登录时间
    int flag;
}Login;

int cmp(const void *p1, const void *p2)
{
    struct login *a = (struct login*)p1;
    struct login *b = (struct login*)p2;
    return a->id - b->id;
}

int main()
{
    int n, i, j;
    Login student[200];
    Login flag[200] = {0};
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d %s %d %d", &student[i].id, &student[i].name, &student[i].m, &student[i].time);
        student[i].flag = 0;
        if(i >= 1)
        {
            for ( j = 0; j < i; j++)
            {
                if((student[i].id == student[j].id) & (student[i].m != student[j].m))
                {
                        student[j].flag=1;
                        i--;
                        n--;
                        break;
                }
            }
        }
    }
    //printf("--\n");
    j = 0;
    for ( i = 0; i < n; i++)
    {
        if(student[i].flag)
        {
            flag[j].id = student[i].id;
            strcpy(flag[j].name, student[i].name);
            //printf("%d\n", flag[j].id);
            j++;
            //flag[j].name = 
        }
            //printf("%d %s\n", , student[i].name);
    }
    //printf("--\n");
    qsort(flag, j, sizeof(flag[0]), cmp);
    //printf("--\n");
    for ( i = 0; i < j; i++)
    {
        printf("%d %s\n", flag[i].id, flag[i].name);
    }
    return 0;
}