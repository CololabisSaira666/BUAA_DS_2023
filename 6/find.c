#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 25
#define NHASH  3001
#define MULT  37

FILE *in;
char W[MAX]; //待查找的单词
int num;
int post[30] = {0,248,415,745,940,1114,1271,1357,1458,1597,1623,1649,1758,1911,1980,2065,2336,2351,2541,2943,3116,3193,3231,3351,3351,3365,3367};
struct find{
    char data[MAX];
}words[3500];
typedef struct node{
    char word[MAX];
    struct node * next;
}Node;
Node *hashtable[20000];

int pre();
void sequentialSearch();
void binarySearch();
void indexTable();
void hashSearch();
unsigned int hash(char *str);
Node *create_node(char list[]);
void insert_node(char list[]);

int main()
{
    in=fopen("dictionary3000.txt","r");
    int op; // 查找方法
    scanf("%s %d", &W, &op);
    num = strlen(W);
    W[num] = '\0';
    num = pre();
    if (op == 1)
        sequentialSearch();
    else if(op == 2)
        binarySearch();
    else if(op == 3)
        indexTable();
    else if(op == 4)
    {
        for ( int i = 0; i < num; i++)
            insert_node(words[i].data);
        hashSearch();
    }
        
    //printf("%d", num);
    return 0;
}

int pre() // 读入单词表
{
    int i = 0, l;
    char line[MAX];
    while (fscanf(in, "%s", line) != EOF)
    {
        l = strlen(line);
        line[l] = '\0';
        strcpy(words[i++].data, line);
    }
    return i;
}

void sequentialSearch() //顺序查找方式查找
{
    int i = 0, r;
    for ( i = 0; i < num; i++)
    {
        //puts(W);
        //puts(words[i].data);
        r = strcmp(W, words[i].data);
        //printf("%d ", r);
        if (r == 0)
        {
            printf("1 %d", i+1);
            return;
        }
        if (r < 0)
        {
            printf("0 %d", i+1);
            return;
        }
    }
    printf("0 %d", i);
}

void binarySearch() // 折半查找
{
    int count = 0; // 查找次数
    int low = 0, high = num - 1, mid;
    while(low <= high)
    {
        count++;
        mid = (low + high) / 2;
        if(strcmp(W, words[mid].data) == 0) // 查找到
        {
            printf("1 %d", count);
            return;
        }
        else if (strcmp(W, words[mid].data) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("0 %d", count);
}

void indexTable() //构建索引表后折半查找
{
    char c = W[0];
    int low = post[c-'a'];
    int high = post[c-'a'+1]-1;
    int mid, count = 0;
    while(low <= high)
    {
        count++;
        mid = (low + high) / 2;
        if(strcmp(W, words[mid].data) == 0) // 查找到
        {
            printf("1 %d", count);
            return;
        }
        else if (strcmp(W, words[mid].data) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("0 %d", count);
}

void hashSearch()
{
    int i = hash(W);
    int count = 0;
    Node *p = hashtable[i];
    if(p == NULL) // 未查找到
    {
        count++;
        printf("0 %d", count);
        return;
    }
    else
    {
        while (p != NULL)
        {
            count++;
            if(strcmp(p->word, W) == 0){
                printf("1 %d", count);
                return;
            }
            else if(strcmp(p->word, W) < 0)
                p = p->next;
            else{
                printf("0 %d", count);
                return;
            }
        }
        
    }
    printf("0 %d", count);
}

void insert_node(char list[])
{
    int insert = hash(list);
    Node *p = hashtable[insert];
    if(p == NULL) // 未产生过冲突
        hashtable[insert] = create_node(list);
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = create_node(list);
    }
}

Node *create_node(char list[])
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->next = NULL;
    strcpy(new->word, list);
    return new;
}

unsigned int hash(char *str)
{
    unsigned int h=0;
    char *p;
    for(p=str; *p!='\0'; p++)
        h = MULT*h + *p;
    return h % NHASH;
}