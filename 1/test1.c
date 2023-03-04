#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void func(char *q)
{
	char a[] = "Hello";
	q = a;
}
int main()
{
	char *p;
	func(p);
	printf("%s\n", p);
	//return 0;
}
