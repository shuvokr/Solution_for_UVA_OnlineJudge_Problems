#include<stdio.h>
unsigned long long int way[30002];
int coin[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
int sieve (int k)
{
    way[0] = 1;
    int i, j;
    for(i=0; i<11; i++)
        for(j=coin[i]; j<k; j++)
            way[j] += way[j-coin[i]];
    return 0;
}
int main()
{
    sieve(30002);
    float n;
    int k;
    while(scanf("%f",&n) != EOF)
    {
        if(n == 0) return 0;
        k = (int)(n * 100 +0.5);
        k/=5;
        printf("%6.2f%17llu\n",n,way[k]);
    }
    return 0;
}
