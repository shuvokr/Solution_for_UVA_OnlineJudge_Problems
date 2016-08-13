#include <stdio.h>
#include <math.h>

const int pr = 1000102;
int prime[ 78600 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 3; ind = 1;
    for(int i = 7; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i;
}

int main()
{
    primelist();
    int n, two, five, res;
    while(scanf("%d", &n) && n)
    {
        two = five = 0; res = 1; n++;
        for(int i = 2; i < n; i *= 2) two++;
        for(int i = 5; i < n; i *= 5) five++;
        two -= five; for(int i = 0; i < two; i++) res = (res * 2) % 10;
        for(int i = 0; prime[ i ] < n; i++)
            for(long long j = prime[ i ]; j < n; j *= prime[ i ]) res = (res * prime[ i ]) % 10;
        printf("%d\n", res);
    }
    return 0;
}
