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
#define maxn 200+2

#define white 0
#define black 1

typedef pair<int, int> pii;
typedef  vector<int> vi;
typedef vector<pii> vii;


int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end

vector < int > graph[ 26 ];
int vis[ 26 ];

void input();
void reset();

int main()
{
    input();

    return 0;
}
void input()
{
    char in[ 300 ], s, e, from, to, a[ 2 ], b[ 2 ];
    int tmp, i, len, k, cou;
    bool flag;
    while(~scanf("%s", in))
    {
        reset();
        len = strlen( in );
        if(len == 1 && in[ 0 ] == '#') break;
        scanf("%s %s %d", a, b, &k);
        s = a[ 0 ]; e = b[ 0 ];
        s -= 'A'; e -= 'A';
        from = in[ 0 ];
        for(i = 1; i < len && in[ i ] != '.'; i++)
        {
            if(in[ i ] == ':')
            {
                i++;
                while(in[ i ] != ';' && i < len && in[ i ] != '.')
                {
                    to = in[ i++ ];
                    graph[ from - 'A' ].pb( to - 'A' );
                }
                if(in[ i ] == ';') from = in[i + 1]; i++;
            }
        }
        cou = 0;
        while(!vis[ s ])
        {
            flag = false;
            vis[ e ]++;
            len = graph[ s ].size();
            for(i = 0; i < len; i++)
            {
                int v = graph[ s ][ i ];
                if(!vis[ v ])
                {
                    vis[ e ]--;
                    e = s; cou++;
                    if(!(cou % k)) printf("%c ", e + 'A'), vis[ e ]++;
                    s = v;
                    flag = true; break;
                }
            }
            if( !flag ) break;
        }
        printf("/%c\n", s + 'A');
    }
}
void reset()
{
    for(int i = 0; i < 26; i++) graph[ i ].clear();
    memset(vis, 0, sizeof vis);
}
