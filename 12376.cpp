    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <ctype.h>
    #include <string>
    #include <sstream>
    #include <iostream>
    #include <vector>
    #include <stack>
    #include <queue>
    #include <map>
    #include <list>
    #include <algorithm>

    using namespace std;

    #define sf scanf
    #define pf printf
    #define LLD long long
    #define LD long
    #define fo(i, n) for(i = 0; i < n; i++)
    #define of(i, n) for(i = n - 1; i >= 0; i--)
    #define mem(n) memset(n, 0, sizeof(n))

    void input();
    int BFS(int index);

    int in[ 102 ][ 102 ];
    int node, edge, valu[ 102 ];

    int main()
    {
        input();

        return 0;
    }
    void input()
    {
        int i, j, T, tmp, a, b, kag = 0;
        sf("%d\n", &T);
        while(T--)
        {
            sf("%d%d", &node, &edge); mem( valu );
            fo(i, node) sf("%d", &valu[ i ]);
            fo(i, 102) fo(j, 102) in[ i ][ j ] = 0;
            fo(i, edge)
            {
                sf("%d%d", &a, &b);
                in[ a ][ b ] = 1;
            }
            pf("Case %d: ", ++kag);
            BFS( 0 );
        }
    }
    int BFS(int index)
    {
        int max = 0, res = 0, last_pos = -1;
        queue < int > Q;
        int i, tmp;
        Q.push( index );
        while(!Q.empty())
        {
            tmp = Q.front(); Q.pop();
            max = -1;
            fo(i, node)
            {
                if(in[ tmp ][ i ] == 1)
                {
                    in[ tmp ][ i ] = 0;
                    if(max < valu[ i ])
                    {
                        max = valu[ i ];
                        last_pos = i;
                    }
                }
            }
            if(max != -1) res += max, Q.push( last_pos );
        }
        pf("%d %d\n", res, last_pos);
    }
