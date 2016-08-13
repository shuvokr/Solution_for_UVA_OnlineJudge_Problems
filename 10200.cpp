#include <stdio.h>
#include <string.h>
#include <math.h>

const int pr = 10001;
int prime[ 1500 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;

    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i;
}


void input();
void call();

int res[ 10010 ];

int main()
{
    primelist();
    call();

    input();

    return 0;
}
void input()
{
    int a, b;
    while(~scanf("%d %d", &a, &b))
    {
        int x = b - a + 1;
        int y = res[b + 1] - res[ a ];

        double ans = (double(y) / double(x)) * 100.00;
        ans = ans + 1e-9;
        printf("%.2lf\n", ans);
    }
}
void call()
{
    memset(res, 0, sizeof res);
    for(int i = 0; i < 10001; i++)
    {
        int num = i * i + i + 41;
        bool mar = true;

        for(int k = 0; k < ind && prime[ k ] * prime[ k ] <= num; k++)
            if(num % prime[ k ] == 0) mar = false, k = ind;

        if( mar ) res[i + 1] = 1;
        res[i + 1] += res[ i ];
    }
}
