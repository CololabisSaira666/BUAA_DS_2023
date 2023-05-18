//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman树结构
	char c;		
	int weight;					//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 		//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;						//实验步骤 
FILE *Src, *Obj;
	
void statCount();				//步骤1：统计文件中字符频率
void createHTree();				//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();				//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 				//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();					//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();					//输出步骤3的结果
void print4();					//输出步骤4的结果

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//输入当前实验步骤 
	
	statCount();						//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1) ? print1(): 1; 			//输出实验步骤1结果	
	createHTree();						//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2) ? print2(Root): 2; 		//输出实验步骤2结果	
	makeHCode();				   		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3) ? print3(): 3; 			//输出实验步骤3结果
	(Step>=4) ? atoHZIP(),print4(): 4; 	//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//【实验步骤1】开始 

void statCount()
{
	char c;
	
	while((c = fgetc(Src)) != EOF)
	{
		if(c != '\n')
			Ccount[c]++;
	} 
	Ccount[0] = 1;
}

//【实验步骤1】结束

//【实验步骤2】开始

void createHTree()
{
	int i, j = 0, k;
	struct tnode *p, *L[150], *q;
	for(i = 0; i < 128; i++)
	{
		if(Ccount[i] > 0) // 存在
		{
			p = (struct tnode*)malloc(sizeof(struct tnode));
			p->c = i;
			if(i == 0)
				p->weight = 1;
			else
				p->weight = Ccount[i];
			p->left = p->right = NULL;
			L[j++] = p;
		} 
	}
	for(i = 0; i < j-1; i++)
	{
		for(k = 0; k < j-i-1;k++)
		{
			if(L[k]->weight > L[k+1]->weight)
			{
				q = L[k];
				L[k] = L[k+1];
				L[k+1] = q;
			}
		}
	}
	while(j > 1)
	{
		q = (struct tnode*)malloc(sizeof(struct tnode));
		q->left = L[0];
		q->right = L[1];
		q->weight = L[0]->weight + L[1]->weight;
		for(i = 2; i < j; i++)
			L[i-2] = L[i];
		j-=2;
		for(i = j - 1; i>=0; i--)
		{
			if(q->weight >= L[i]->weight)
				break;
		}
		for(k = j - 1; k >= i+1; k--)
			L[k+1] = L[k];
		L[i+1] = q;
		j++;
	}
	Root=L[0];
}

//【实验步骤2】结束

//【实验步骤3】开始

char s[150];
void visitHTree(struct tnode* p, char c, int i)
{
	if(i >= 0)
		s[i] = c;
	if(p->left == NULL && p->right == NULL) //叶节点 
	{
		strcpy(HCode[p->c],s);
		s[i]='\0';
		return;
	}
	visitHTree(p->left, '0', i+1);
	visitHTree(p->right, '1', i+1);
	s[i] = '\0';
}

void makeHCode()
{
	visitHTree(Root, 'a', -1);
} 

//【实验步骤3】结束

//【实验步骤4】开始
char S[200000] = {0};
void atoHZIP()
{
	int hc = 0;
	fseek(Src,0L,SEEK_SET); //SEEK_SET	文件的开头
	int i;
	char c;
	while((c = fgetc(Src)) != EOF)
	{
		strcat(S, HCode[c]);
	}
	strcat(S, HCode[0]);
	int len=strlen(S);
	i = len;
	int j = 8-len%8;
	if(j < 8)
	{
		for (i=len; i<len+j; i++)
		 	S[i] = '0';
	}
	S[i] = '\0';
	for(i=0; S[i] != '\0'; i++) 
	{
    	hc = (hc << 1) | (S[i]-'0');
    	//printf("%c ",hc);
		if((i+1)%8 == 0) 
		{
			fputc(hc,Obj);     //输出到目标（压缩）文件中	
			printf("%x",hc);   //按十六进制输出到屏幕上
			hc = 0;
		}
	}

	
}

//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
