#include <stdio.h>
#include <math.h>
int factor(int n);
const int pr = 500001;
int prime[ 41539 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i; //printf("%d\n", ind);
}
int main()
{
    primelist();
    int res[ pr ];
    res[ 1 ] = 1;
    for(int i = 2; i < pr; i++)
        if(!mark[ i ])
        {
            int j = i, k = factor( i );
            int cou = 1;
            while(j != k)
            {
                //puts("ok");
                cou++;
                j = k;
                k = factor( k );
            }
            res[ i ] = cou;
        }
        else res[ i ] = 1;
    int n, m, T, kag = 0, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        int s = -1;
        a = n < m ? n : m;
        b = n > m ? n : m; b++;
        for(int i = a; i < b; i++) s = s < res[ i ] ? res[ i ] : s;
        printf("Case #%d:\n%d\n", ++kag, s);
    }
    return 0;
}
int factor(int n)
{
    int k = 0, ret = 0;
    while(n > prime[ k ])
    {
        while(n % prime[ k ] == 0)
        {
            n /= prime[ k ];
            ret += prime[ k ];
        }
        k++;
        if(n == 1) break;
        if(mark[ n ])
        {
            ret += n;
            break;
        }
    }
    return ret;
}
