#include <stdio.h>
#include <string.h>
#include <math.h>

int mamo[ 2010 ];

void prime_factor();

int pf[ 1001 ][ 100 ];
const int pr = 501;
int prime[ 100 ], ind;
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
    //printf("%d", ind);
}

int a, b;

int main()
{
    //freopen("output.txt", "w", stdout);
    primelist();
    prime_factor();
//    for(int i = 1; i < 10; i++)
//    {
//        for(int j = 1; j <= pf[ i ][ 0 ]; j++)
//        {
//            printf("%d ", pf[ i ][ j ]);
//        }
//        puts("okkkkkkkkkkk");
//    }
    int kag = 0;
    while(scanf("%d %d", &a, &b) && (a || b))
    {
        if(a == b)
        {
            printf("Case %d: 0\n", ++kag);
            continue;
        }
        if(b < a || mark[ a ]) printf("Case %d: -1\n", ++kag);
        else
        {
            //Iterative DP solution :)
            for(int i = a; i <= b; i++) mamo[ i ] = -1;
            mamo[ a ] = 0;
            for(int i = a; i <= b; i++)
            {
                if(mamo[ i ] == -1) continue;
                for(int j = 1; j <= pf[ i ][ 0 ]; j++)
                {
                    int x = i + pf[ i ][ j ];
                    if(mamo[ x ] == -1) mamo[ x ] = mamo[ i ] + 1;
                    else mamo[ x ] = mamo[ x ] < mamo[ i ] + 1 ? mamo[ x ] : mamo[ i ] + 1;
                }
            }
            if(mamo[ b ] > 0) printf("Case %d: %d\n", ++kag, mamo[ b ]);
            else printf("Case %d: -1\n", ++kag);
        }
    }
    return 0;
}
void prime_factor()
{
    memset(pf, 0, sizeof pf);
    for(int i = 1; i < 1001; i++)
    {
        int num = i, k = 1;
        for(int j = 0; j < ind; j++)
        {
            if(num % prime[ j ] == 0) pf[ i ][ k++ ] = prime[ j ];
            //printf("%d %d\n", prime[ j ], i);
        }
        pf[ i ][ 0 ] = k - 1;
    }
}
