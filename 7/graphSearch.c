#include <stdio.h>
#include <string.h>

int map[101][101];
int p[101];
int vertex, n = 0;

void dfs(int i);
void bfs(int i);

int main()
{
    int edge, i, v;
    int v1, v2;
    scanf("%d %d", &vertex, &edge);
    for(i = 0; i< edge; i++)
    {
        scanf("%d %d", &v1, &v2);
        map[v1][v2] = map[v2][v1] = 1;
    }
    scanf("%d", &v);
    p[0] = 1;
    dfs(0);
    printf("\n");
    memset(p,0,sizeof(p));
    n = 0;
    p[0] = 1;
    bfs(0);
    printf("\n");
    memset(p,0,sizeof(p));

    for(i=0; i<vertex; i++)
	{
		map[i][v] = map[v][i] = 0;
	}

    p[0] = 1;
    dfs(0);
    printf("\n");
    memset(p,0,sizeof(p));
    n = 0;
    p[0] = 1;
    bfs(0);
    printf("\n");
    memset(p,0,sizeof(p));

    return 0;
}

void dfs(int i)
{
    int j;
    printf("%d ", i);
    n++;
    if(n == vertex)
        return;
    for(j = 0; j<vertex; j++)
    {
        if(p[j] == 0 && map[i][j]==1)
        {
            p[j] = 1;
            dfs(j);
        }
    }
    return;
}

void bfs(int i)
{
    int head=0, tail=-1, queue[10001], temp, j;
	queue[++tail]=i;
    p[i]=1;
	while(head<=tail)
	{
		temp=queue[head++];
		printf("%d ", temp);
		for(j=0; j<vertex; j++)
		{
			if(p[j]==0 && map[temp][j]==1)
			{
				queue[++tail]=j;
				p[j]=1;
			}
		}
	}
	return;
}