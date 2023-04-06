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
    int word[35] = {0}, i ,j, num; // 存放已生成的密钥
    int flag[26] = {0}; // 标记
    char secret[26];
    Key *head = (Key *)malloc(sizeof(Key)), *p, *q, *t1, *t2;
    head->link = NULL;
    p = head;
    //in = fopen("in.txt", "r");
    
    while ((c = getchar()) != '\n')
    {
        if (flag[c - 'a'] == 0) //显示此前未被生成
        {
            flag[c - 'a'] = 1;
            q = (Key *)malloc(sizeof(Key));
            q->s = c;
            q->link = NULL; //生成新的节点
            
            p->link = q;
            p = q;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (flag[i] == 0)
        {
            q = (Key *)malloc(sizeof(Key));
            q->s = 'a' + i;
            q->link = NULL; //生成新的节点
            
            p->link = q;
            p = q;
        }
    }
    p->link = head->link; // 生成环形链表
    t1 = p; // 头节点的前一节点
    str = head->link->s;
    newstr = head->link->s;
	//t2 = p;
    for ( i = 0; i < 25; ) // 生成对应表
    {
        j = 1;
        
        t1->link = head->link->link;
        head->link = head->link->link;
        p = head->link;

        num = Ascii(newstr);

        for (q = head->link; ;p = q, q = q->link)
        {
			
            if (j == num)
            {
                secret[newstr - 'a'] = q->s;
				//num = Ascii(head->link->s);
				printf("%c %d %d", newstr, num, j);
                printf(" %d %c %c\n", i, q->s, p->s);
                i++;
                break;
            }
            j++;
        } // 写入
        head->link = q;
		newstr = head->link->s;
		t1 = p;
        //free(q);
    }
    printf("\n");
    secret[head->link->s-'a'] = str;
    for ( i = 0; i < 26; i++)
    {
        printf("%d %c\n", i, secret[i]);
    }
    

    /*
    for (q = head->link; q ;q = q->link)
    {
        
        printf("%c", q->s);
        if (q->link == head->link)
        {
            break;
        }
        
        
    }
    */
    return 0;
}