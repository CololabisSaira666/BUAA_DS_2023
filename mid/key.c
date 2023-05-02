#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int word[26] = {0}; //存放加密顺序
    int flag[26] = {0}; //标记是否已经被填入
    char key[50] = {0};
    char real[27] = {0};
    int F[26] = {0};
    int i, j = 0;
    gets(key);
    for ( i = 0; key[i]!='\0'; i++)
    {
        key[i] = tolower(key[i]);
        if (!(key[i]>='a' && key[i]<='z'))
        {
            continue;
        }
        if (flag[key[i] - 'a'] == 0) //如果此前未被读入
        {
            real[j] = key[i]; //得到处理后的
            j++;
            flag[key[i] - 'a'] = 1; //标记
        }
    }
    int len = strlen(real);
    //puts(real);
    j = 0;
    for(i = len-1; i>=0; i--)
    {
        word[j] = real[i];
        F[word[j]-'a'] = 1;
        j++;
        
    }
    i = 26;
    for ( ; j<26, i>=0; i--)
    {
        if(F[i-1] == 0)
        {
            word[j] = i-1+'a';
            j++;
        }
    }
    
    for (i = 0; i < 26; i++)
    {
        printf("%c %c\n",'a'+i, word[i]);
    }
    return 0;
}