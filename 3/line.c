#include <stdio.h>
#include <stdlib.h>

struct line
{
    int count;
    int x1;
    int y1;
    int x2;
    int y2;
    struct line *next;
};
typedef struct line *Lineptr;
typedef struct line Line;

// 链表储存线段组

Lineptr delete(Lineptr list, Lineptr p);

int main()
{
    int n, i=1, j, flag = 0, max = 1;
    int x1, x2, y1, y2; 
    scanf("%d", &n);
    Lineptr first=NULL, p, q, find, r;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    q = (Lineptr)malloc(sizeof(Line));
    q->count = 1;
    q->x1 = x1;
    q->x2 = x2;
    q->y1 = y1;
    q->y2 = y2;
    q->next = NULL;
    first = p = q;
    p = q;
    for ( i = 1; i < n; i++) //输入数据，已知“第一个端点的X轴坐标小于第二个端点的X轴坐标，即x1<x2”
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); //读入第i条线段
        //遍历链表
        for ( find = first; find != NULL; find = find->next)
        {
            if (x1==find->x1 && y1==find->y1)
            {
                flag = 1;
                find->count++;
                r=find;

                find->x1 = x2;
                find->y1 = y2;

                find = find->next;

                for (; find != NULL; find = find->next)
                {
                    if (r->x1 == find->x1 && r->y1 == find->y1)
                    {
                        r->count += find->count;

                        r->x1 = find->x2;
                        r->y1 = find->y2;
                        delete(first, find);
                    }
                    else if (r->x1 == find->x2 && r->x1 == find->y2)
                    {
                        r->count += find->count;

                        r->x1 = find->x1;
                        r->y1 = find->y1;
                        delete(first, find);
                    }
                    
                }
                
            }
            else if (x1==find->x2 && y1==find->y2)
            {
                flag = 1;
                find->count++;

                find->x2 = x2;
                find->y2 = y2; 
            }
            else if (x2==find->x1 && y2==find->y1)
            {
                flag = 1;
                find->count++;

                find->x1 = x1;
                find->y1 = y1;
            }
            else if (x2==find->x2 && y2==find->y2)
            {
                flag = 1;
                find->count++;

                find->x2 = x1;
                find->y2 = y1;
            }
            if (flag = 1)
            {
                break;
            }
            r = find;
        }

        if (flag = 0) //没有匹配，需要新建一个节点
        {
            q = (Lineptr)malloc(sizeof(Line));
            q->count = 1;
            q->x1 = x1;
            q->x2 = x2;
            q->y1 = y1;
            q->y2 = y2;
            q->next = NULL;

            r->next = q;
            }
        
        flag = 0;
    }

    // 寻找最大的count
    for (find = first; find != NULL; find = find->next)
    {
        printf("%d %d %d %d\n",find->x1, find->y1, find->x2, find->y2);
        if (find->count > max)
        {
            r = find;
            max = find->count;
        }
        
    }

    if (r->x1 < r->x2)
    {
        printf("%d %d %d", max, r->x1, r->y1);
    }
    else
    {
        printf("%d %d %d", max, r->x2, r->y2);
    }
    return 0;
}


// 删除一个节点
Lineptr delete(Lineptr list, Lineptr p)
{
    Lineptr r;
    if (p == list)
    {
        list = list->next;
        free(p);
    }
    else
    {
        for (r = list; r->next != p && r->next !=NULL; r->next);
        if (r->next != NULL)
        {
            r->next = p->next;
            free(p);                
        }
    }
}












typedef struct node{
	int x1,y1; //前端点 
	int x2,y2; //后端点 
	int LinkNum; //能接上的下一条线段的编号 
}Node;

#include "stdio.h"
#include "stdlib.h"
int main()
{
	int i,n,x1,x2,y1,y2;
	Node *p;
	scanf("%d",&n);//线段数量
	p=(Node *)calloc(n,sizeof(Node));//动态数组，n个元素，每个元素是一个Node类型 
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2); //输入线段 
		(p+i)->x1=x1;(p+i)->y1=y1;(p+i)->x2=x2;(p+i)->y2=y2;(p+i)->LinkNum=-1;
		
		for(int j=i-1;j>=0;j--)//和已有的线段进行对比，看是否有连续关系 
		{
			if((p+j)->x2==(p+i)->x1 && (p+j)->y2==(p+i)->y1)
			{
				(p+j)->LinkNum=i;//第j条线段后面要接第i条线段 
			}
			if((p+j)->x1==(p+i)->x2 && (p+j)->y1==(p+i)->y2)
			{
				(p+i)->LinkNum=j;//第i条线段后面要接第j条线段 
			}
		}
	}
	int max=0,index;
	for(i=0;i<n;i++) //找连续数量最多的情况 
	{
	  int num=1;
	  Node *temp=p+i;  
	  while(temp->LinkNum!=-1)
	  {
	  	num++;//有后续的一条线段,记数加1 
		temp=p+temp->LinkNum;
	  }
	  if(max<num)
	  {
	  	max=num;
	  	index=i;
	  }
	}
	printf("%d %d %d\n",max,(p+index)->x1,(p+index)->y1);
	return 0;
}
