#include<stdio.h>

unsigned long long ans[30002] = {0};
int k = 30001;

int sive(int len)
{
    ans [0] = 1;
    int i = 0, j = 0, coin[] = {1, 5, 10, 25, 50};

    for(i = 0; i < 5; i++)
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
    {
        if(ans[n] > 1)
            printf("There are %llu ways to produce %d cents change.\n",ans[n],n);
        else
            printf("There is only 1 way to produce %d cents change.\n",n);
    }
    return 0;
}

