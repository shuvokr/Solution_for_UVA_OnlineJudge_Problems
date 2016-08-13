#include<stdio.h>
#include<stdio.h>

unsigned long long ans[10001] = {0};
int k = 10000;

int sive(int len)
{
    ans [0] = 1;
    int i = 0, j = 0, coin[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

    for(i = 0; i < 21; i++)
    {
        for(j = coin[i]; j < len; j++)
        {
            ans[j] += ans[j - coin[i]];
        }
    }
    return 0;
}

int main()
{
    sive(k);
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%llu\n",ans[n]);
    return 0;
}

