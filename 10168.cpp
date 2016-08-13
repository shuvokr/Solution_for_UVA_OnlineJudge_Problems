#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void input();
void save_prime();

const int maxn = 1e7 + 1;

#define sf scanf
#define pf printf
#define fo(i, v, n) for(i = v; i < n; i++)
#define mem(a, v) memset(a, v, sizeof a)
#define pinf 1e9
#define ninf -1e9

int prime_list[ 664580 ];
bool mark[ maxn ];

int main()
{
    save_prime();
    input();

    return 0;
}
void save_prime()
{
    int i, j, sqrtn = 3163;
    mark[ 0 ] = mark[ 1 ] = false;
    mark[ 2 ] = true;
    for(i = 4; i < maxn; i +=2) mark[ i ] = false;
    for(i = 3; i < maxn; i +=2) mark[ i ] = true;

    for(i = 3; i < sqrtn; i += 2)
        if(mark[ i ])
            for(j = i * i; j < maxn; j += i + i)
                mark[ j ] = false;
    int cou = 1;
    prime_list[ 1 ] = 2;
    for(i = 3; i < 10000001; i+=2)
        if(mark[ i ]) prime_list[ ++cou ] = i;
}
void input()
{
    int i, j, k, l, N, len = 664580, tmp;
    bool imposible;
    while(~scanf("%d", &N))
    {
        imposible = true;
        if(N > 7)
        if( !(N % 2) )
        {
            N -= 4;
            if( N > 3 )
            fo(k, 1, len)
            {
                if(mark[ N - prime_list[ k ] ])
                {
                    printf("2 2 %d %d\n", prime_list[ k ], N - prime_list[ k ]);
                    k = len + 2; imposible = false;
                }
            }
        }
        else
        {
            N -= 5;
            if( N > 3 )
            fo(k, 1, len)
            {
                if(mark[ N - prime_list[ k ] ])
                {
                    printf("2 3 %d %d\n", prime_list[ k ], N - prime_list[ k ]);
                    k = len + 2; imposible = false;
                }
            }
        }
        if( imposible ) puts("Impossible.");
    }
}
