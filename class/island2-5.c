// 关于计算小岛的面积
#include <stdio.h>
int main()
{
    int a[50][50] = {0}, i, j, k, c, n, area = 0;
    scanf("%d", &n); // 输入方阵的阶数
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; i < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; i < n; j++)
        {
            c = 0;
            if (a[i][j] == 0) //随后继续向下查找？
            {
                for ( k = i; k < n; k++)
                {
                    if (a[k][j] == 1)
                    {
                        c++;
                        break;
                    }
                    
                }
                for ( k = i; k >= n; k--) // 向上
                {
                    if (a[k][j] == 1)
                    {
                        c++;
                        break;
                    }
                    
                }
                for ( k = j; k < n; k++) //向右
                {
                    if (a[i][k] == 1)
                    {
                        c++;
                        break;
                    }
                    
                }
                for ( k = j; k >= 0; k--) //向左
                {
                    if (a[i][k] == 1)
                    {
                        c++;
                        break;
                    }
                    
                }
            }
            if (c == 4)
            {
                /* code */
            }
            
        }
    }
}
