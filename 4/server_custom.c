#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200
#define THRESHOLD 7 // 窗口增加的阈值
#define MAXSVR 5
#define MINSVR 3

void out(int i);

struct cust
{
    int type;
    int intime;
    int outime;
}Cust[1000];

int r = -1, front = 0, window = 3, win_able=3, judge;

int main()
{
    int cycle, clock, i, j, k, id = 0;
    int cust_num[MAXSIZE] = {0};
    //int winnum = MINSVR; //当前提供服务的窗口数
    int flag[MAXSIZE]={0};
    scanf("%d", &cycle);
    for (i = 0; i < cycle; i++)
    {
        scanf("%d", &cust_num[i]);
        if (cust_num[i] == 0)
            flag[i] == 1;
        
    }
    for (i = 0; i < cycle; i++)
    {
        for ( j = 0; j < cust_num[i]; j++)
        {
            scanf("%d", &Cust[id].type);
            id++;
        }
    }
    // 至此已经读入所需数据
    for(j=0; flag[j]; j++);
    for ( i = j; i < cycle; i++)
    {
        for ( k = 0; k < cust_num[i]; k++)
        {
            r++;
            Cust[r].intime = i;
        }
        while ((r+1-front)/window >= 7 && window < 5 && !flag[i])
        {
            window++;
            win_able++;
        } // 开设新的窗口
        out(i); // 输出
        while ((r+1-front)/window < 7 && window >3 && judge)
        {
            window--;
            win_able--;
        }
    }
    while (front < r+1)
    {
        out(i);
        while ((r+1-front)/window < 7 && window >3 && judge)
        {
            window--;
            win_able--;
        }
        i++;
    }
    
    return 0;
}

void out(int i) //第n
{
    int j;
    judge = 0;
    for ( j = 0; j < win_able; j++)
    {
        judge = 1;
        if (r + 1 == front)
            break;
        Cust[front++].outime = i;
        printf("%d : %d\n", front, i-Cust[front-1].intime);
    }
    win_able = window;
    for ( j = 0; j < front; j++)
    {
        if (Cust[j].type > 0)
            Cust[j].type--;        
    }
    for (j = 0; j < front; j++)
    {
        if (Cust[j].type > 0)
        {
            win_able--;
            if(win_able==0)
                break;
        }
    }
}