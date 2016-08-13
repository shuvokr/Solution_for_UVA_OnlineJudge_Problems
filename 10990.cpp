#include <stdio.h>
#define M 2000001
int phi[ M ], res[ M ];

void calculatePhi();
void save_result();
int depthphi(int n);

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    calculatePhi();
    save_result();
    int m, n, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &m, &n);
        printf("%d\n", res[ n ] - res[m - 1]);
    }
    return 0;
}
void calculatePhi()
{
    for (int i = 1; i < M; i++) phi[i] = i;
    for (int p = 2; p < M; p++)
        if (phi[p] == p)
            for (int k = p; k < M; k += p) phi[k] -= phi[k] / p;
}
void save_result()
{
    res[ 1 ] = 0;
    res[ 2 ] = 1;
    for(int i = 3; i < M; i++)
        res[ i ] = depthphi( phi[ i ] ) + res[i - 1];
}
int depthphi(int n)
{
    int ret = 0;
    while(phi[ n ] != 1) n = phi[ n ], ret++;
    return ret + 2;
}

