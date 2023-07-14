#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 618
struct station{				
	char stationName[30];	
	int IsChange;			 
};
struct vertex{				 
	int weight;				
	int lineID;				 
};
struct station StationID_list[M];	
struct vertex map[M][M];			
int lineID,StationNum,lineNum,IsChange,VerNum;	
int prev[M],dist[M],path[M],top,pathID[M][M];	
char Begin[30],End[30];	

int SearchMap(char *s)
{
	int i;
	for(i=0; i<VerNum; i++)
		if(strcmp(s,StationID_list[i].stationName) == 0)
			return i;	//返回
	return -1;
}

void Subway(FILE *fp)
{
	int i,j,ContainID,EdgeLast;
	char stationName[30];		
	fscanf(fp,"%d",&lineNum);	
	for(i=0; i<lineNum; i++)
	{
		fscanf(fp,"%d %d",&lineID,&StationNum);
		EdgeLast = -1;	
		for(j=0; j<StationNum; j++)
		{
			fscanf(fp,"%s %d",stationName,&IsChange);
			ContainID = SearchMap(stationName);	
			if(ContainID == -1)		
			{
				strcpy(StationID_list[VerNum].stationName,stationName);
				StationID_list[VerNum].IsChange=IsChange;				
				if(EdgeLast != -1)		
				{
					map[EdgeLast][VerNum].lineID = map[VerNum][EdgeLast].lineID = lineID;	
					map[EdgeLast][VerNum].weight = map[VerNum][EdgeLast].weight = 1;		
				}
				EdgeLast=VerNum;	
				VerNum++;			
			}
			else
			{
				if(EdgeLast != -1)	
				{
					map[EdgeLast][ContainID].lineID = map[ContainID][EdgeLast].lineID = lineID;
					map[EdgeLast][ContainID].weight = map[ContainID][EdgeLast].weight = 1;	
				}
				EdgeLast = ContainID;	
			}
		}
	}
}

void dijkstra(int vs, int ve)
{
    int i,j,k,min,tmp;
    int flag[M];      				
    for (i = 0; i < VerNum; i++)	
    {
        flag[i] = 0;              	
        prev[i] = vs;             	 
        dist[i] = map[vs][i].weight;	
    }
	dist[vs] = 0,flag[vs] = 1;		
    for (i = 0; i < VerNum - 1; i++)	
    {								
        min = 0x3f3f3f3f;
        for (j = 0; j < VerNum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        flag[k] = 1;				
        if(k==ve)	return;
        for (j = 0; j < VerNum; j++)
        {
            tmp = (map[k][j].weight==0x3f3f3f3f ? 0x3f3f3f3f : (min + map[k][j].weight));
            if (flag[j] == 0 && (tmp  < dist[j]) && map[k][j].lineID>0)
            {
                dist[j] = tmp;
                prev[j] = k;	//前驱 
            }
        }
    }
}
void PrintPath(int v1,int v2)
{		
	int i,EdgeLast=v1,pathLen=1,u=path[top-1];
	int lineId=map[EdgeLast][u].lineID;	
	printf("%s-%d",StationID_list[v1].stationName,lineId); 
	EdgeLast = u;
	for(i=top-2;i>=0;i--)	
	{
		u=path[i];	
		if(lineId != map[EdgeLast][u].lineID)	
		{
			lineId = map[EdgeLast][u].lineID;
			printf("(%d)-%s-%d",pathLen,StationID_list[EdgeLast].stationName,lineId);
			pathLen=0;
		}
		pathLen++;		
		EdgeLast = u;	
	}
	printf("(%d)-%s",pathLen,StationID_list[v2].stationName);
}


int main()
{	
	int i,j,v1,v2,t;
	FILE *fp = fopen("bgstations.txt","r");
	scanf("%s %s",Begin,End);
	for(i=0;i<M;i++)			
		for(j=0;j<M;j++)
		{	
			map[i][j].weight=map[j][i].weight=0x3f3f3f3f;	
			map[i][j].lineID=map[j][i].lineID=0;	
		}
	Subway(fp);		 
	v1=SearchMap(Begin);	
	v2=SearchMap(End);	
	dijkstra(v1,v2);	
	for(t=v2;t!=v1;t=prev[t])	
	{
		path[top]=t;
		top++;
	}
	PrintPath(v1,v2);	
	return 0;
}