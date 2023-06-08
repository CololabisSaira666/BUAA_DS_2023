#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
typedef struct tree{
    int count;
    int judge;
    struct tree* word[26];
}TreeNode,*Tree;
Tree creat_node()
{
    Tree new=(Tree)malloc(sizeof(TreeNode));
    new->count=0;
    new->judge=0;//1 is stop_word,0 is passage
    memset(new->word,0,sizeof(new->word));
    return new;
}
void insert(Tree t,char s[],int stop)
{
    Tree cur=t;
    int i;
    for(i=0;isalpha(s[i]);i++)
    {
        int c=s[i]-'a';
        if(cur->word[c]==NULL)
        {
            cur->word[c]=creat_node();
        }
        cur=cur->word[c];
    }
    if(cur->judge==1)
    {
        return;
    }
    cur->count++;
    if(stop)
    {
        cur->judge=1;
    }
    else
    {
        cur->judge=0;
    }
}
int search(Tree t,char s[])
{
    Tree node=t;
    char *p=s;
    //for(;(*p!='\0') && (!isalpha(*p));++p);
    while(isalpha(*p) && node!=NULL)
    {
        node=node->word[*p-'a'];
        p++;
    }
    //if (node!=NULL && node->count>0)
    if(node->judge==1)
        return 0;
    else
        return node->count;
}
char passage[30000000]={0};
char change_passage[30000000]={0};
int word[30000000][2];

struct sentence{
    int start;
    int final;
    int num;
}sentence[102455];
int cmp(const void *a,const void *b)
{
    if((*((struct sentence *)a)).num>(*((struct sentence *)b)).num)
        return -1;
    if((*((struct sentence *)a)).num<(*((struct sentence *)b)).num)
        return 1;
    return 0;
}
int main() {
    int n,i;
    Tree t=creat_node();
    char newword[20];
    char ch;
    int flag=0;
    long long len=0;
    char change[128]={0};
    FILE *in,*in_stop,*out;
    in_stop=fopen("stopwords.txt","r");
    in=fopen("article1.txt","r");/*article*/
    assert(in);
    out=fopen("results.txt","w");
    scanf("%d",&n);
    for(i='a';i<='z';i++)
    {
        change[i]=(char)i;
    }
    for(i='A';i<='Z';i++)
    {
        change[i]=(char)(i-'A'+'a');
    }
    while(fscanf(in_stop,"%s",newword)!=EOF)
    {
        insert(t,newword,1);
    }
    while(((ch=fgetc(in))!=EOF))
    {
        passage[len]=ch;
        if(isalpha(ch))
        {
            change_passage[len]=change[ch];
        }
        else
        {
            change_passage[len]=ch;
        }
        len++;
    }
    //=================record word====================
    int k=0;
   if(isalpha(change_passage[0]))
    {
        word[k][0]=0;
        for(i=0;i<len;i++)
        {
            if(!isalpha(change_passage[i+1]))
            {
                word[k][1]=i;
                flag=i+1;
                break;
            }
        }
        k++;
        int is_zero=0,is_in=0;
        while(i<len)
        {
            for(i=flag;i<len;i++)
            {
                if(isalpha(change_passage[i]) && (!isalpha(change_passage[i-1])) && is_in==0)
                {
                    word[k][0]=i;
                    flag=i;
                    is_zero=1;
                    is_in=1;
                    break;
                }
                if(!isalpha(change_passage[i+1]) && (is_zero==1))
                {
                    word[k][1]=i;
                    flag=i+1;
                    k++;
                    is_zero=0;
                    is_in=0;
                    break;
                }
            }
        }
        //printf("out ! out\n");
    }
    else
    {
        flag=0;
        int is_zero=0,is_in=0;
        while(flag<len)
        {
            for(i=flag+1;i<len;i++)
            {
                if(isalpha(change_passage[i]) && (!isalpha(change_passage[i-1])) && is_in==0)
                {
                    word[k][0]=i;
                    flag=i;
                    is_zero=1;
                    is_in=1;
                    break;
                }
                if(!isalpha(change_passage[i+1]) && (is_zero==1))
                {
                    word[k][1]=i;
                    flag=i+1;
                    k++;
                    is_zero=0;
                    is_in=0;
                    break;
                }
            }
        }
    }
    for(i=0;i<k;i++)
    {
        insert(t,change_passage+word[i][0],0);
    }
    //=================record word end=================
    //=================record sentence================
   int m=0,flag_2=0;
    if(isalpha(change_passage[0]))
    {
        for(i=0;i<len;i++)
        {
            sentence[m].start=0;
            if((change_passage[i]=='.')||(change_passage[i]=='?')||(change_passage[i]=='!'))
            {
                sentence[m].final=i;
                flag_2=i+1;
                break;
            }
        }
        m++;
        int is_in=0,is_end=1;
        while(i<len)
        {
            for(i=flag_2;i<len;i++)
            {
                if((isalpha(change_passage[i])&&(!isalpha(change_passage[i-1]))&&is_end==1)||((change_passage[i]=='\'')&&(!isalpha(change_passage[i-1]))&&is_end==1))
                {
                    sentence[m].start=i;
                    flag_2=i;
                    is_in=1;
                    is_end=0;
                    break;
                }
                if(((change_passage[i]=='.')||(change_passage[i]=='?')||(change_passage[i]=='!'))&&(is_in==1))
                {
                    sentence[m].final=i;
                    flag_2=i+1;
                    m++;
                    is_in=0;
                    is_end=1;
                    break;
                }
            }
        }
        //printf("out of sentence");
    }
    else
    {
        flag_2=0;
        int is_in=0,is_end=1;;
        while(i<len)
        {
            for(i=flag_2;i<len;i++)
            {
                if(isalpha(change_passage[i])&&(!isalpha(change_passage[i-1]))&&is_end==1)
                {
                    sentence[m].start=i;
                    flag_2=i;
                    is_in=1;
                    is_end=0;
                    break;
                }
                if(((change_passage[i]=='.')||(change_passage[i]=='?')||(change_passage[i]=='!'))&&(is_in==1))
                {
                    sentence[m].final=i;
                    flag_2=i+1;
                    m++;
                    is_in=0;
                    is_end=1;
                    break;
                }
            }
        }
    }
    //======================record sentence end=========================
    int num=0;
    for(i=0;i<m;i++)
    {
        for(int j=sentence[i].start;num<k && j<sentence[i].final;j=word[num][0])
        {
            sentence[i].num+=search(t,change_passage+word[num][0]);
            num++;
        }
    }
  char s[10]="d";
    int t1=search(t,s);
    printf("%d\n",t1);
    qsort(sentence,m-1,sizeof(struct sentence),cmp);
     //=====================output==========================
     printf("%d ",sentence[0].num);
     for(i=sentence[0].start;i<=sentence[0].final;i++)
     {
     printf("%c",passage[i]);
     }
     printf("\n");
     printf("%d ",sentence[1].num);
     for(i=sentence[1].start;i<=sentence[1].final;i++)
     {
     printf("%c",passage[i]);
     }
     printf("\n");
     printf("%d ",sentence[2].num);
     for(i=sentence[2].start;i<=sentence[2].final;i++)
     {
     printf("%c",passage[i]);
     }
     printf("\n");
     printf("%d ",sentence[3].num);
     for(i=sentence[3].start;i<=sentence[3].final;i++)
     {
     printf("%c",passage[i]);
     }
     printf("\n");
     printf("%d ",sentence[4].num);
     for(i=sentence[4].start;i<=sentence[4].final;i++)
     {
     printf("%c",passage[i]);
     }
     printf("\n");
     for(i=0;i<n;i++)
     {
     fprintf(out,"%d ",sentence[i].num);
     for(int j=sentence[i].start;j<=sentence[i].final;j++)
     fprintf(out,"%c",passage[j]);
     fprintf(out,"\n");
     }
    return 0;
}
