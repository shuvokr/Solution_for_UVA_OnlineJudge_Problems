#include <stdio.h>
long long int phi[1000005];

void calculatePhi()
{
    int M = 1000005, i, p, k;
    for (i = 2; i < M; i++) phi[i] = i;
    for (p = 2; p < M; p++)
        if (phi[p] == p)
            for (k = p; k < M; k += p) phi[k] -= phi[k] / p;
    for(i = 2; i < M; i++) phi[ i ] += phi[i - 1];
}

int main()
{
    calculatePhi(); int n;
    while(scanf("%d", &n) && n) printf("%lld\n", phi[ n ]);
    return 0;
}

