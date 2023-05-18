//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;		
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root=NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE]={{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step=0;						//ʵ�鲽�� 
FILE *Src, *Obj;
	
void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

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
	scanf("%d",&Step);					//���뵱ǰʵ�鲽�� 
	
	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	(Step==1) ? print1(): 1; 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	(Step==2) ? print2(Root): 2; 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	(Step==3) ? print3(): 3; 			//���ʵ�鲽��3���
	(Step>=4) ? atoHZIP(),print4(): 4; 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//��ʵ�鲽��1����ʼ 

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

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ

void createHTree()
{
	int i, j = 0, k;
	struct tnode *p, *L[150], *q;
	for(i = 0; i < 128; i++)
	{
		if(Ccount[i] > 0) // ����
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

//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ

char s[150];
void visitHTree(struct tnode* p, char c, int i)
{
	if(i >= 0)
		s[i] = c;
	if(p->left == NULL && p->right == NULL) //Ҷ�ڵ� 
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

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ
char S[200000] = {0};
void atoHZIP()
{
	int hc = 0;
	fseek(Src,0L,SEEK_SET); //SEEK_SET	�ļ��Ŀ�ͷ
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
			fputc(hc,Obj);     //�����Ŀ�꣨ѹ�����ļ���	
			printf("%x",hc);   //��ʮ�������������Ļ��
			hc = 0;
		}
	}

	
}

//��ʵ�鲽��4������

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
	
	printf("\nԭ�ļ���С��%ldB\n",in_size);
	printf("ѹ�����ļ���С��%ldB\n",out_size);
	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
