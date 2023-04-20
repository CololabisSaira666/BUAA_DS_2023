#include <stdio.h>
#include <string.h>

#define MAX 205

struct stack
{
    char c;
    int line;
}S[300];

char str[MAX], *p1, *p2;
int top = -1, len;

int main()
{
    int Line = 0;
    FILE *fp;
    int i, flag0 = 0,flag1 = 0, flag2 = 0;
    int xl = 0, xr = 0, yl = 0, yr = 0;
    fp = fopen("example.c", "r");
    while (fgets(str, MAX, fp) != NULL)
    {
        Line++;
        //puts(str);
        for ( i = 0; str[i] != '\0'; i++)
        {
            
            if (flag0)
            {
                if (str[i] == '\'')
                {
                    flag0 = 0;
                    i++;
                }
            }
            if (flag0) continue;
            if (flag1)
            {
                if (str[i] == '\"')
                {
                    flag1 = 0;
                    i++;
                } 
            }
            if (flag1) continue;
            if (flag2)
            {
                if (str[i] == '*' && str[i+1] == '/')
                {
                    flag2 = 0;
                    i++;
                }
            }
            if (flag2) continue;
            if (str[i] == '/' && str[i+1] == '/')
            {
                break;
            }
            
            if (str[i] == '\'')
            {
                flag0 = 1;
                continue;
            }
            else if (str[i] == '\"')
            {
                flag1 = 1;
                continue;
            }
            else if (str[i] == '/' && str[i+1] == '*')
            {
                flag2 = 1;
                i++;
                continue;
            }

            if (str[i] == '(')
            {
                top++;
                xl++;
                S[top].c = str[i];
                S[top].line = Line;
            }
            else if (str[i] == ')')
            {
                top++;
                xr++;
                S[top].c = str[i];
                S[top].line = Line;
            }
            else if (str[i] == '{')
            {
                top++;
                yl++;
                S[top].c = str[i];
                S[top].line = Line;
            }
            else if (str[i] == '}')
            {
                top++;
                yr++;
                S[top].c = str[i];
                S[top].line = Line;
            }
        }
        memset(str,0,MAX);
    }
    fclose(fp);
    int top1 = -1, top2 = -1;
    int addr1[150] = {0}, addr2[150] = {};
    int jixu = 0;
    //printf("%d\n", flag1);
    //printf("%d %d %d %d\n", xl,xr,yl,yr);

    if (xl == xr && yl == yr)
    {
        for ( i = 0; i <= top; i++)
        {
            printf("%c", S[i].c);
        }
        
    }
    else
    {
        for ( i = 0; i <= top; i++)
        {
            if (S[i].c == '(')
            {
                top1++;
                addr1[top1] = i;
            }
            else if (S[i].c == ')' && top1 != -1)
            {
                top1--;
            }
            else if (S[i].c == ')' && top1 == -1)
            {
                printf("without maching ')' at line %d", S[i].line);
                jixu = 1;
                break;            
            }
            if (S[i].c == '{')
            {
                top2++;
                addr2[top2] = i;
            }
            else if (S[i].c == '}' && top2 != -1)
            {
                top2--;
            }
            else if (S[i].c == '}' && top2 == -1)
            {
                printf("without maching '}' at line %d", S[i].line);
                jixu = 1;
                break;          
            }
        }
    }
    if (jixu == 0)
    {
        if (top1 != -1)
        {
            i = addr1[top1];
            printf("without maching '(' at line %d", S[i].line);
            
        }else if (top2 != -1)
        {
            i = addr2[top2];
            printf("without maching '{' at line %d", S[i].line);
        }
    }
    //printf("\n%d %d", top1, top2);
    return 0;
}


void simplification()
{
    p1 = strstr(str, "//");
    p2 = strstr(str, "/*");
    if (p1 == NULL && p2 == NULL)
    {
        len = strlen(str);
    } 
    
    
}