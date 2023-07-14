#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  512
struct edge {	//边结点结构
    int  eno; 	//边序号
    int  adjvex;	//邻接顶点
    int  weight;	//边的权重（可为距离或时间），本例中为1
    struct edge  *next;
 };
struct ver {	                 //顶点结构，邻接表下标即为顶点序号
    struct edge  *link;
} ; 
struct ver Graph[MAXSIZE]; //由邻接表构成的图
char Visited[MAXSIZE] = {0}; //标识相应顶点是否被访问 
int Paths[MAXSIZE]={0};       //独立路径，依次存放组成路径的边号
int Vnum;	                             //顶点数
int V0, V1;                              //启始顶点, 目标顶点
struct edge *insertEdge(struct edge *head, int avex, int eno);    //插入一条以边号为区分的边结点
void eDFS(int v,int level);      //按顶点的边进行的深度优先遍历算法
void printPath(int n);

int main()
{
	int en,eno,i,v1,v2;
	scanf("%d %d", &Vnum, &en);
	for(i=0; i<en; i++){
		scanf("%d %d %d", &eno, &v1, &v2);
		Graph[v1].link = insertEdge(Graph[v1].link,v2, eno);
		Graph[v2].link = insertEdge(Graph[v2].link,v1, eno);
	}
	V0 = 0; V1 = Vnum-1;
	Visited[V0] = 1;
	eDFS(V0,0);       // 按顶点的边，开启递归的按边的深度优先遍历
	return 0;
}

struct edge *insertEdge(struct edge *head, int avex, int eno)
{
    struct edge *e,*p;
    e =(struct edge *)malloc(sizeof(struct edge));
    e->eno = eno; e->adjvex = avex; e->weight = 1; e->next = NULL;
    if(head == NULL)  
	{ 
	      head=e; 
	      return head; 
	}
    for(p=head; p->next != NULL; p=p->next);
    p->next = e; 
    return head;
}

void printPath(int n)
{
	int i;
	for(i=0; i<n; i++)
	    printf("%d ", Paths[i]);
	printf("\n");
	return;
}

void eDFS(int v, int level)
{
    struct edge  *p;
    if(v == V1)
    { 
        printPath(level);
        return; 
    }
    for(p=Graph[v].link; p!= NULL; p=p->next)
    {
        if( !Visited[p->adjvex]){
            Paths[level] = p->eno;
            Visited[p->adjvex] = 1;
            eDFS(p->adjvex,level+1);
            Visited[p->adjvex] = 0;
        }
    }
    return;
} 