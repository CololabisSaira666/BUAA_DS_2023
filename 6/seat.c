#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>

typedef struct s{
    int id;
    char name[25];
    int seat;
}S;
S student[100];
int flag[102] = {0};

int cmp_seat(const void*a, const void *b);
int cmp_id(const void*a, const void *b);

int main()
{
    FILE *in, *out;
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
    int n, M, Q; // 学生人数
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        fscanf(in, "%d %s %d", &student[i].id, &student[i].name, &student[i].seat);
        flag[student[i].seat]=1;
    }
    fclose(in);
    // 操作1
    qsort(student, n, sizeof(student[0]), cmp_seat); 
    // 操作2
    M = student[n-1].seat; //当前表中安排的最大座位号
    j = n-1;
    if(M < n)
        Q = M;
    else Q = n;
    for ( i = 1; i <= Q; i++)
    {
        if(flag[i] == 0)
        {
            student[j--].seat = i;
            M = student[j].seat; //当前表中安排的最大座位号
            if(M < n)
                Q = M;
            else Q = n;
        }  
    }
    // 操作3
    qsort(student, n, sizeof(student[0]), cmp_seat); 
    M = student[n-1].seat;
    Q = student[0].seat;
    for(i=1; i<n; i++)
    {
        if(Q == student[i].seat) // 出现重复的座位
        {
            student[i].seat = ++M;
        }
        else
            Q = student[i].seat;
    }
    // 操作4
    qsort(student, n, sizeof(student[0]), cmp_id); 
    // 输出
    for(i = 0; i < n; i++)
    {
        fprintf(out, "%d %s %d\n", student[i].id, student[i].name, student[i].seat);
    }
    
    fclose(out);
    return 0;
}

int cmp_seat(const void*a, const void *b)
{
    S aa = *(S*)a;
    S bb = *(S*)b;
    if(aa.seat == bb.seat)
        return aa.id - bb.id;
    else 
        return aa.seat - bb.seat;
}

int cmp_id(const void*a, const void *b)
{
    S aa = *(S*)a;
    S bb = *(S*)b;
    return aa.id - bb.id;
}
