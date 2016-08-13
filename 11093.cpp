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

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main()
{
    input();

    return 0;
}
void input()
{
    int T, n, i, j, tmp, have, need, kag = 0, car, flag, k;
    vector < int > in;
    vector < int > pro;
    bool mark;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);
        in.clear();
        pro.clear();
        have = need = 0;
        fo(i, n)
        {
            sf("%d", &tmp);
            have += tmp;
            in.push_back( tmp );
        }
        fo(i, n)
        {
            sf("%d", &tmp);
            need += tmp;
            pro.push_back( tmp );
        }
        if(need > have) { pf("Case %d: Not possible\n", ++kag); continue; }
        car = 0; mark = false;
        fo(i, n)
        {
            flag = i; mark = false;
            car = in[ i ];
            for(j = flag+1; j != flag ; j++)
            {
                if(j == n) j = 0;
                k = j - 1;
                if(j == 0) k = n - 1;
                car -= pro[ k ];
                if( car < 0 )
                {
                    mark = false;
                    break;
                }
                else mark = true;
                car += in[ j ];
            }
            if(mark) break;
        }
        if(mark) pf("Case %d: Possible from station %d\n", ++kag, flag+1);
        else pf("Case %d: Not possible\n", ++kag);
    }
}
