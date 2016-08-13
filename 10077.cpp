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
    int ru, rl, lu, ll, x, y, fu, fl;
    while(sf("%d %d", &x, &y) != EOF)
    {
        if(x == 1 && y == 1) break;
        fu = fl = ru = ll = 1;
        rl = lu = 0;
        while( true )
        {
            if(fl == x && fu == y) break;
            if(fu * x < fl * y)
            {
                pf("L");
                lu = fu;
                ll = fl;
            }
            else
            {
                pf("R");
                ru = fu;
                rl = fl;
            }
            fu = ru + lu;
            fl = rl + ll;
        }
        puts("");

    }
}
