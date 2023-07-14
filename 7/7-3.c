#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 101
#define INF 0x3f3f3f3f
int sum,top=0,MinSpanTreeVertex[200],egdesID[200][200];	 
void MinSpanTree_Prim(int weights[][M],int vertexNum,int FirstVertexID,int *edges)
{
	int min, minweight[M];
	int i, j, k;
	for(i=0; i<vertexNum; i++)	
	{
		minweight[i] = weights[FirstVertexID][i];		
		edges[i] = FirstVertexID;		 
	}
	minweight[FirstVertexID] = 0;	
	for(i=1; i<vertexNum; i++)
	{
		min = INF;
		for(j=0,k=0; j<vertexNum; j++)
			if(minweight[j]!=0 && minweight[j]<min)
			{
				min = minweight[j];
				k = j;				
			}
		sum += minweight[k];
		minweight[k] = 0;
		MinSpanTreeVertex[top] = egdesID[k][edges[k]]; 	
		top++;
		for(j=0; j<vertexNum; j++)	
			if(minweight[j]!=0 && weights[k][j] < minweight[j])
			{
				minweight[j] = weights[k][j];	
				edges[j] = k;
			}
	}
}

int cmp (const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int i, j, k, vertex, edge, ID;
	int v1, v2, w;
    int weights[M][M],edges[M];
	scanf("%d %d", &vertex, &edge);	//顶点个数和边个数 
	for(i=0; i<vertex; i++)
		for(j=0; j<vertex; j++)
			weights[i][j] = 0x3f3f3f3f;	//初始化 
    for(i=0;i<edge;i++)
	{
		scanf("%d %d %d %d",&ID,&v1,&v2,&w);	//录入信息 
		egdesID[v1][v2]=ID;
		egdesID[v2][v1]=ID;
		weights[v1][v2]=w;
		weights[v2][v1]=w;
	}
    MinSpanTree_Prim(weights, vertex,0, edges);
    printf("%d\n",sum);
    qsort(MinSpanTreeVertex,top,sizeof(int),cmp);
    for(i = 0; i<vertex-1; i++)
    {
        printf("%d ", MinSpanTreeVertex[i]);
    }
    
    return 0;
}