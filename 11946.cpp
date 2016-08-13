//Templet start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200000+2
#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, k, tmp, T, len;
    char in[ 92 ];

    map <int, char> m;
    m[ 0 ] = 'O';
    m[ 1 ] = 'I';
    m[ 2 ] = 'Z';
    m[ 3 ] = 'E';
    m[ 4 ] = 'A';
    m[ 5 ] = 'S';
    m[ 6 ] = 'G';
    m[ 7 ] = 'T';
    m[ 8 ] = 'B';
    m[ 9 ] = 'P';

    bool ck = false;
    sf("%d", &T);
    getchar();
    while(T--)
    {
        if(ck) puts("");
        else ck = true;
        i = 0;
        while( gets(in) )
        {
            if(in[ 0 ] == 0) break;
            len = strlen( in );
            fo(k, len)
            {
                if(!isdigit( in[ k ] )) pf("%c", in[ k ]);
                else pf("%c", m[ in[ k ] - '0' ]);
            }
            puts("");
        }
    }
}
