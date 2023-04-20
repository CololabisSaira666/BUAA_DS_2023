#include <stdio.h>


struct
{
    int x;
    char *y;
}tab[2] = { {1, "ab"}, {2, "cd"}}, *p = tab;


int main()
{
    printf("%c", *(++p)->y);
    return 0;
}

/*
int main()
{
    
    int a[4] = {1, 2, 3, 4};
    int *p;
    p = &a[2];
    printf("%d %d\n", ++*p, *--p);
    
   /*
   char ch[] = "600";
   int a, s = 0;
   for(a = 0; ch[a]>='0' && ch[a] <= '9'; a++)
    s = 10*s + ch[a] - '0';
    printf("%d", s);
   
}
 */