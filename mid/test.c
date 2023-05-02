#include <stdio.h>
#include <stdlib.h>

int func(int n)
{
    if(n<=1)
        return 1;
    else
        return (2+n*func(n-1));
}

struct aaa
{
    int x;
};

struct a
{
    struct aaa www, qqq;
}tr;

int main()
{
    int m;
    m = func(5);
    printf("%d", m);
    char *pls[300], b[30];
    pls[0] = (char *)malloc(sizeof(b[30]));
    char *s= "BUAA";
    //*s = "BUAA";
    puts(s);
    tr.www.x = 15;
    printf("%d", tr.www.x = 15);
    return 0;
}