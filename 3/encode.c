#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct data
{
    char s;
    struct data *link;
    
}Key;

int Ascii(char c)
{
	int num = c;
	return num;
}

int main()
{
    FILE *in, *out;
    char c, str, newstr;
    int i ,j, num; // 存放已生成的密钥
    int flag[95] = {0}; // 标记
    int secret[95];
    Key *head = (Key *)malloc(sizeof(Key)), *p, *q, *t1;
    head->link = NULL;
    p = head;
    in = fopen("in.txt", "r");
    out = fopen("in_crpyt.txt", "w");
    while ((c = getchar()) != EOF)
    {
        if (flag[c - ' '] == 0) //显示此前未被生成
        {
            flag[c - ' '] = 1;
            q = (Key *)malloc(sizeof(Key));
            q->s = c;
            q->link = NULL; //生成新的节点
            
            p->link = q;
            p = q;
        }
    }
    for (i = 0; i < 95; i++)
    {
        if (flag[i] == 0)
        {
            q = (Key *)malloc(sizeof(Key));
            q->s = ' ' + i;
            q->link = NULL; //生成新的节点
            
            p->link = q;
            p = q;
        }
    }
    p->link = head->link; // 生成环形链表
    t1 = p; // 头节点的前一节点
    str = head->link->s;
    newstr = head->link->s;
    for ( i = 0; i < 94; ) // 生成对应表
    {
        j = 1;
        p->link = head->link->link;
        head->link = head->link->link;
        //p = head->link;

        num = Ascii(newstr);
        //printf("%d ", num);
        for (q = head->link; ;p = q, q = q->link)
        {
            if (j == num)
            {
                secret[newstr - ' '] = q->s - ' ';
				//num = Ascii(head->link->s);
				//printf("%c %d %d", newstr, num, j);
                //printf(" %d %c %c\n", i, q->s, p->s);
                i++;
                break;
            }
            j++;
        } // 写入
        head->link = q;
		newstr = head->link->s;
		t1 = p;
    }
    secret[newstr - ' '] = str - ' ';
    
    while ((c = fgetc(in)) != EOF)
    {
        if (c >= ' ' && c <= '~')
        {
            c = ' ' + secret[c - ' '];
            fputc(c, out);
        }
        else
        {
            fputc(c, out);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}