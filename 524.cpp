#include <stdio.h>
#include <string.h>
using namespace std;
void backtrack(int pos);
int ar[ 18 ], n, kag = 0;
bool prime[ 32 ], mark[ 17 ], space;
int main()
{
    ar[ 0 ] = 1; space = false;
    prime[ 0 ] = prime[ 1 ] = false; prime[ 2 ] = true;
    for(int i = 4; i < 32; i+=2) prime[ i ] = false;
    for(int i = 3; i < 32; i+=2) prime[ i ] = true;
    for(int i = 3; i < 7; i += 2)
        if(prime[ i ])
            for(int j = i + i; j < 32; j += i) prime[ j ] = false;
    memset(mark, true, 17);
    while(~scanf("%d", &n))
    {
        if(space) puts("");
        else space = true;
        printf("Case %d:\n", ++kag);
        if(n == 1) puts("1");
        else if(!(n % 2)) backtrack( 1 );
    }
    return 0;
}
void backtrack(int pos)
{
    if(pos > n) return;
    if(pos == n && prime[ar[pos - 1] + 1])
    {
        printf("1");
        for(int i = 1; i < n; i++) printf(" %d", ar[ i ]);
        puts("");
    }
    else
    for(int i = 2; i <= n; i++)
    {
        if(mark[ i ])
        if(prime[ar[pos - 1] + i])
        {
            ar[ pos ] = i; mark[ i ] = false;
            backtrack(pos + 1);
            mark[ i ] = true;
        }
    }
}
