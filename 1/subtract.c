#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define maxsize 100
char ans[maxsize] = {'\0'};
int compare(char a[], char b[]);
void sub(char A[], char B[]);
void rmzero(char a[]);
char a[maxsize] = {'\0'}, b[maxsize] = {'\0'};
int main()
{
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
	rmzero(a);
    rmzero(b);
	if (compare(a, b)>0)//a>b
	{
       sub(a, b);//计算a-b 
    } 
	else if (compare(a, b) < 0) //a<b
	{
        printf("-"); //这时要先输出负号 
        sub(b, a);//计算b-a 
    } 
	else //a等于b 
	{
        ans[0] = '0';
        ans[1] = '\0'; 
    }
    i = 0;
    j = strlen(ans)-1;
    while (i<j) { //把ans中的元素逆序调整 
        char temp=ans[i];
        ans[i]=ans[j];
        ans[j]=temp; 
        i++;j--;
    }
    rmzero(ans);//去掉可能的前导0 
    printf("%s\n",ans);//输出 
    return 0;
}

int compare(char a[], char b[]) //
{    int i;
    if (strlen(a) < strlen(b)) //a位数少于b 
    {
        return -1;
    } else if (strlen(a) > strlen(b))//a位数多于b 
    {
        return 1;
    }
    for ( i = 0; i < strlen(a); i++)// 
    {
        if (a[i] > b[i])//a>b 
        {
            return 1;
        } else if (a[i] < b[i])//a<b
		{ 
            return -1;
        }
    }
    return 0;
}

void sub(char A[], char B[]) //
{
	int i, j , k , flag,flag2;
	i=strlen(A)-1;
	j=strlen(B)-1;
	k=0;
	flag=0;// 
	flag2=0;// 
	while(i>=0 && j>=0)
	{
	   if(A[i]>'0') //当前的计算位的数大于0 
	   {
	   	A[i]=A[i]-flag;//
	   	flag2=0;
	   }
	   else if(A[i]=='0' && flag==1) 
	   {
	   	 A[i]='9';//
	   	 flag2=1;//
	   }
	   //以下判断计算前是否要借位 
 	   if(A[i]<B[j]) //还要借位
	   {
	   	 flag=1;		 
	   }
	   else  
	   {
	   	 flag=0;
	   }
	   ans[k]=A[i]+flag*10-B[j]+'0'; 
	   if(flag2==1)
	   {
	   	flag=1;
	   }
	   i--;j--;k++; 
	}
	while(i>0)//A位数多于B
	{
		if(A[i]-'0'-flag<0) //A[i]是0 
			{
				A[i]='9';
				flag=1; //还要借位 
			}
		else //A[i]不是0 
			{
				A[i]=A[i]-flag;
				flag=0;//不用借位 
			}
		ans[k]=A[i];
		k++; i--;
     }
	if(A[i]-flag>'0')//处理最后一位
	{
		ans[k]=A[i]-flag;
		k++;
	}
	ans[k]='\0';//最后 
	return;
}

void rmzero(char a[]) /* 去掉前导0捏*/
{
    int i = 0, j, len;
    len = strlen(a);
    while (i < len && a[i] == '0') //定位到第一个非0值的位置 
    {
        i++;
    }
    if (i == len)//如果都是0 
    {
        a[0] = '0';
        a[1] = '\0';
    } 
	else //去掉前导0 
	{ 
        j = i;
	    for ( i=0 ; j < len; j++, i++)
        {
            a[i] = a[j];            
        }
        a[i] = '\0';
    }
}