#include<stdio.h>

long ans[7502] = {0};
int k = 7500;

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
        printf("%d\n",ans[n]);
    return 0;
}
