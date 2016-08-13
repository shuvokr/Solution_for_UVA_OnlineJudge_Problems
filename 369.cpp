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

vector <long long> stor;
vector <long long> st;

int main()
{
    input();

    return 0;
}
void input()
{
    long long int mal, kal, n, m, tmp, res, i, j, k;
    while(sf("%lld %lld", &n, &m) != EOF)
    {
        if(n + m == 0) break;
        if(n == m) pf("%lld things taken %lld at a time is 1 exactly.\n", n, m);
        else
        {
            stor.clear();
            st.clear();
            tmp = n - m;
            kal = 1;
            if(tmp > m)
            {
                k = tmp + 1;
                while(true)
                {
                    stor.push_back( k );
                    k++;
                    if(k > n) break;
                }
                for(i = 2; i <= m; i++) st.push_back( i );
            }
            else
            {
                k = m + 1;
                while(true)
                {
                    stor.push_back( k );
                    k++;
                    if(k > n) break;
                }
                for(i = 2; i <= tmp; i++) st.push_back( i );
            }
            mal = 1;
            for(i = stor.size() - 1; i >= 0; i--)
            {
                fo(j, st.size())
                {
                    if(stor[ i ] % st[ j ] == 0)
                    {
                        stor[ i ] /= st[ j ];
                        st[ j ] = 1;
                    }
                }
                mal *= stor[ i ];
            }

            kal = 1;
            fo(i, st.size()) kal *= st[ i ];
            mal /= kal;
            pf("%lld things taken %lld at a time is %lld exactly.\n", n, m, mal);
        }
    }
}
