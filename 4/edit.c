#include <stdio.h>
#include <string.h>

#define MAX 520

void insert(int pos, char str[]);
void delete(int pos, int num);
void undo_insert();
void undo_delete();

struct instruction
{
    int op;
    int pos;
    char str[MAX];
    char final[MAX];
}oper[1000];

int top = 0;

int main()
{
    char s[MAX] = {0};
    char str[MAX] = {0};
    int n, i, op, pos, num;
    fgets(s, MAX, stdin);
    //puts(s);
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        top++;
        scanf("%d %d %s", &oper[top].op, &oper[top].pos, oper[top].str);
    }
    strcpy(oper[top].final, s);
    scanf("%d", &op);
    while (op != -1)
    {
        if (op == 1)
        {
            memset(str, 0, sizeof(char));
            scanf("%d %s", &pos, str);
            top++;
            insert(pos, str);
        }
        else if (op == 2)
        {
            scanf("%d %d", &pos, &num);
            top++;
            delete(pos, num);
        }
        else if (op == 3)
        {
            if (top == 0)
            {
                scanf("%d", &op);
                continue;
            } 
            else if (top > n)
            {
                top--;
            }
            else
            {
                if (oper[top].op == 1)
                {
                    top--;
                    undo_insert();
                }
                else if (oper[top].op == 2)
                {
                    top--;
                    undo_delete();
                }
                
            }            
        }
        
        scanf("%d", &op);
    }
    puts(oper[top].final);
    
    return 0;
}

// 插入
void insert(int pos, char str[])
{
    int len = strlen(str);
    strcpy(oper[top].final, oper[top-1].final);
    strcpy(oper[top].final + pos, str);
    strcpy(oper[top].final+pos+len, oper[top-1].final+pos);
}
// 删除
void delete(int pos, int num)
{
    int len;
    len = strlen(oper[top-1].final);
    if (num > len - pos)
    {
        num = len - pos;
    }
    strcpy(oper[top].final, oper[top-1].final);
    strcpy(oper[top].final+pos, oper[top-1].final+pos+num);
    oper[top].final[len-num] = '\0';
}
// 撤销插入
void undo_insert()
{
    int len = strlen(oper[top+1].str);
    int pos = oper[top+1].pos;
    int L = strlen(oper[top+1].final);
    strcpy(oper[top].final, oper[top+1].final);
    strcpy(oper[top].final+pos, oper[top+1].final+len+pos);
    oper[top].final[L-len] = '\0';
}
// 撤销删除
void undo_delete()
{
    int pos = oper[top+1].pos;
    int len = strlen(oper[top+1].str);
    strcpy(oper[top].final, oper[top+1].final);
    strcpy(oper[top].final+pos, oper[top+1].str);
    strcpy(oper[top].final+pos+len, oper[top+1].final+pos);
}