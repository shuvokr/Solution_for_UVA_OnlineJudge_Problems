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
#define maxn 100000+2

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    char in[ maxn ];
    int i, len, mod4, mod100, mod400, mod15, mod55;
    bool ck = false;
    while(gets( in ))
    {
        len = strlen( in );
        mod4 = mod100 = mod400 = mod15 = mod55 = 0;
        if( ck ) puts("");
        ck = true;
        fo(i, len)
        {
            mod4 = ( (mod4 * 10) + (in[ i ] - '0') ) % 4;
            mod100 = ( (mod100 * 10) + (in[ i ] - '0') ) % 100;
            mod400 = ( mod400 * 10 + (in[ i ] - '0') ) % 400;
            mod15 = ( mod15 * 10 + (in[ i ] - '0') ) % 15;
            mod55 = ( mod55 * 10 + (in[ i ] - '0') ) % 55;
        }
        //pf("%d %d\n", mod15, mod55);
        if( (mod4 == 0 &&  mod100 != 0) || mod400 == 0)
        {
            puts("This is leap year.");
            if( mod15 == 0 ) puts("This is huluculu festival year.");
            if( mod55 == 0 ) puts("This is bulukulu festival year.");
            continue;
        }
        if( mod15 == 0 )
        {
            puts("This is huluculu festival year.");
            continue;
        }
        puts("This is an ordinary year.");
    }
}
