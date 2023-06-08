#include <stdio.h>
#include <ctype.h>
typedef struct featureVector //网页特征向量
{
    int feature;
    int weight;
    
}feature_vector;


int main()
{
    int i;
    int M, N;
    char s[20];
    scanf("%s %d %d", &s, &N, &M);
    // 读取hashvalue.txt的内容
    char Hash[10001][130];
    FILE *hashvalue, *article, *stopword, *sample;
    article = fopen("article.txt", "r");
    stopword = fopen("stopword.txt", "r");
    sample = fopen("sample.txt", "r");
    hashvalue = fopen("hashvalue.txt", "rb");
    for ( i = 0; i < N; i++)
    {
        fscanf(hashvalue, "%s", Hash[i]);
        Hash[i][M] = '\0';
    }
    
    return 0;
}                                                                                                                                                                                  