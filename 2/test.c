#include <stdio.h>

struct dent
{
    int n;
    int *m;
};

int main()
{
    int a=1, b=2, c=3;
    struct dent s[3]={{101,&a}, {102, &b}, {103, &c}};
    struct dent *p = s;
    printf("%d\n", *(++p)->m);
}