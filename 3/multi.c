#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int coef;
    int index;
    struct poly *link;
}Poly;

Poly *input()
{
    int coef, index;
    Poly *head = NULL, *p, *q;
    while (1)
    {
        scanf("%d%d", &coef, &index);
        q = (Poly *)malloc(sizeof(Poly));
        q->coef = coef;
        q->index = index;
        if (head == NULL)
        {
            head = p = q;
        }
        else
        {
            p->link = q;
        }
        p = q;
        if (getchar() == '\n')
        {
            break;
        }
    }
    p->link = NULL;
    return head;
}

Poly *mult(Poly *a, Poly *b) //多项式相乘
{
    Poly *P,*Rear,*t1,*t2,*t, *New;
    int coef,index;
    t1=a;
    t2=b;
    P=(Poly *)malloc(sizeof(Poly));
    P->link =NULL;
    Rear=P;
    while(t2){
        New = (Poly *)malloc(sizeof(Poly));
        New->coef = t1->coef *t2->coef;
        New->index = t1->index +t2->index;
        New->link = NULL;
        Rear->link = New;
        Rear = New;
        t2 = t2->link ;        
    } 
    t1 = t1->link ;
    while(t1){
        t2 = b;
        Rear = P;
        while(t2){
            coef=t1->coef *t2->coef ;
            index=t1->index +t2->index ;
            while(Rear->link &&Rear->link->index >index)
                Rear=Rear->link ;
            if(Rear->link && Rear->link->index == index){
                if(Rear->link->coef +coef)
                    Rear->link->coef +=coef;
                else { 
                    t=Rear->link ;
                    Rear->link =t->link ;
                    free(t);
                }
            } 
            else{
                t=(Poly *)malloc(sizeof(Poly));
                t->coef =coef;
                t->index =index;
                t->link =Rear->link ;
                Rear->link =t;
                Rear=Rear->link ;
            }
            t2=t2->link ;
        }
        t1=t1->link ;
    }
    t=P;
    P=P->link ;
    free(t);
    return P;
}

void output(Poly *head)
{
    Poly *c;
    c = head;
    //c = c->link;
    while (c)
    {
        printf("%d %d ", c->coef, c->index);
        c = c->link;
    }
    printf("\n");
}

int main()
{
    Poly *a, *b, *c;
    a = input();
    b = input();
    //a = del(a);
    //output(a);
    c = mult(a, b);
    //output(a);
    //output(b);
    output(c);
    return 0;
}