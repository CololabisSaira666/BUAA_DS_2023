#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[512] = {0};
	fgets(str, 512, stdin);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-')
		{
			if (str[i-1] >= 'a' && str[i-1] <= 'z' && str[i+1] >= 'a' && str[i+1] <= 'z' && str[i-1] < str[i+1])
			{
				for (char a = str[i-1]+1; a < str[i+1]; a++)
				{
					printf("%c", a);
				}
				
			} else if (str[i-1] >= 'A' && str[i-1] <= 'Z' && str[i+1] >= 'A' && str[i+1] <= 'Z' && str[i-1] < str[i+1])
			{
				for (char a = str[i-1]+1; a < str[i+1]; a++)
				{
					printf("%c", a);
				}
			} else if (str[i-1] >= '0' && str[i-1] <= '9' && str[i+1] >= '0' && str[i+1] <= '9' && str[i-1] < str[i+1])
			{
				for (char a = str[i-1]+1; a < str[i+1]; a++)
				{
					printf("%c", a);
				}
			} else printf("%c", str[i]);
		} else {
			printf("%c", str[i]);
		}
		
	}
	return 0;
	
}
