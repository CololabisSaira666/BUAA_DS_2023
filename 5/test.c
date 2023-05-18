#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode{      //简化的树形数组 
	int ID;				  		//树节点的编号 
	struct TreeNode *child[4];//树节点的子树地址
}Tree,*Treep;
struct Port{	//出口结构体 
	int ID;		//出口编号 
	int size;	//人流大小 
}port[2000];
Tree node[2000];
int q[1000] ;	//q里存的是层次遍历序 
int root,tmp,child;
int i,j,top=0,num;
void layerorder(Treep t)	//层次遍历 
{
	Treep Queue[200],p;
	int front,rear;
	if(t!=NULL)
	{
		Queue[0]=t;
		front=-1,rear=0;
		while(front<rear)	//队列里还有元素 
		{
			p=Queue[++front];
			if(p->child[0]==NULL && p->child[1]==NULL && p->child[2]==NULL)
			{
				q[top]=p->ID;	//存下层次遍历	
				top++;
			}
			for(i=0;i<=3;i++)
			{
				if(p->child[i]!=NULL)	// 若子树非空 
				{
					Queue[++rear]=p->child[i];	//继续 
				}
			}
		}
	}
}
int cmp(const void*p1,const void*p2)
{
	struct Port *a=(struct Port*)p1;
	struct Port *b=(struct Port*)p2;
	if(a->size!=b->size)return b->size-a->size;	//排人流 
	else return a->ID-b->ID;	//排编号 
}
int main()
{	
	while(1)	//录入信息 
	{
		scanf("%d",&root);
		if(root==-1)	break;
		else
		{
			num++;
			node[root].ID=root;
			i=0;
			while(1)
			{
				scanf("%d",&child);
				if(child==-1)	break;
				else
				{
					node[root].child[i]=&node[child];
					node[child].ID=child;
					i++;
				}
			}
		}
	}
	layerorder(&node[100]);	//层次遍历根 
	for(i=0;i<top;i++)
	{
		scanf("%d %d",&port[i].ID,&port[i].size);	//录入信息 
	}
	qsort(port,top,sizeof(struct Port),cmp);	//排序 
	for(i=0;i<top;i++)
		printf("%d<-%d\n",q[i],port[i].ID);//输出 
	return 0;
}