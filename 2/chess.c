#include <stdio.h>

void chess(int a[19][19]);

int main()
{
    int a[19][19] = {0}, i, j;
    for ( i = 0; i < 19; i++) // 输入棋盘
    {
        for ( j = 0; j < 19; j++)
        {
            scanf("%d", &a[i][j]);
        } 
    }
    chess(a);
    return 0;
}

void chess(int a[19][19])
{
    int i, j, k, flag = 0, cnt = 0;
    for ( i = 0; i < 19; i++)
    {
        for ( j = 0; j < 19; j++)
        {
            if (a[i][j] == 1)
            {
                for ( k = i+1, cnt=0; k < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[k][j] == 1)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(i == 0) // 如果在棋盘边缘
                    {
                        if (a[i+4][j] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (i == 15)
                    {
                        if (a[i-1][j] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i-1][j] == 0 || a[i+4][j] == 0)
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                // ***********************************************
                flag = 0;
                for ( k = j+1, cnt=0; k < 19, cnt<3; k++, cnt++) // 向右查找
                {
                    if (a[i][k] == 1)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(j == 0) // 如果在棋盘边缘
                    {
                        if (a[i][j+4] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 15)
                    {
                        if (a[i][j-1] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i][j+4] == 0 || a[i][j-1] == 0)
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
                for ( k = 1, cnt=0; k+i < 19, k+j < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[i+k][j+k] == 1)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(j == 0 || i == 0) // 如果在棋盘边缘
                    {
                        if (a[i+4][j+4] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 15 || i == 15)
                    {
                        if (a[i-1][j-1] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i+4][j+4] == 0 | a[i-1][j-1] == 0)
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
                for ( k = 1, cnt=0; k+i < 19, k+j < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[i+k][j-k] == 1)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(i == 0 || j == 18) // 如果在棋盘边缘
                    {
                        if (a[i+4][j-4] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 3 || i == 15)
                    {
                        if (a[i-1][j+1] == 0) //满足有一端为空白
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i-1][j+1] == 0 | a[i+4][j-4] == 0)
                        {
                            printf("1:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
            }
            if (a[i][j] == 2)
            {
                for ( k = i+1, cnt=0; k < 19, cnt<3; k++, cnt++) // 向右查找
                {
                    if (a[k][j] == 2)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(i == 0) // 如果在棋盘边缘
                    {
                        if (a[i+4][j] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (i == 15)
                    {
                        if (a[i-1][j] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i-1][j] == 0 || a[i+4][j] == 0)
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                // ***********************************************
                flag = 0;
                for ( k = j+1, cnt=0; k < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[i][k] == 2)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(j == 0) // 如果在棋盘边缘
                    {
                        if (a[i][j+4] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 15)
                    {
                        if (a[i][j-1] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i][j+4] == 0 || a[i][j-1] == 0)
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
                for ( k = 1, cnt=0; k+i < 19, k+j < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[i+k][j+k] == 2)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(j == 0 || i == 0) // 如果在棋盘边缘
                    {
                        if (a[i+4][j+4] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 15 || i == 15)
                    {
                        if (a[i-1][j-1] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i+4][j+4] == 0 | a[i-1][j-1] == 0)
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
                for ( k = 1, cnt=0; k+i < 19, k+j < 19, cnt<3; k++, cnt++) // 向下查找
                {
                    if (a[i+k][j-k] == 2)
                    {
                        flag++;
                    }
                }
                if (flag == 3) // 如果有四个连成一排
                {
                    if(i == 0 || j == 18) // 如果在棋盘边缘
                    {
                        if (a[i+4][j-4] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else if (j == 3 || i == 15)
                    {
                        if (a[i-1][j+1] == 0) //满足有一端为空白
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }
                    else
                    {
                        if (a[i-1][j+1] == 0 | a[i+4][j-4] == 0)
                        {
                            printf("2:%d,%d\n", i+1, j+1);
                            return;
                        }
                    }  
                }
                flag = 0;
            }
            /*if (i >= 16 && j >= 16)
            {
                printf("No\n");
                return;
            }
            */
        }
    }
    printf("No\n");
    return;
}