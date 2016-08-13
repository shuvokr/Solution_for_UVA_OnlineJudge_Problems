/*
        Shuvo
        Problem algorithm: Sortest path find
        Problem ID: 423
        Problem name: MPI
*/
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

#define INF 1<<21

int main()
{
    int i, j, k, r, c, v, res, n;
    char tmp[ 20 ];
    int graph[ 102 ][ 102 ];
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++) graph[ i ][ j ] = INF;

        for(i = 1; i <= n; i++)
            for(j = 1; j < i; j++)
            {
                    memset(tmp, -1, sizeof(tmp));
                    scanf("%s", tmp);
                    if(tmp[ 0 ] != 'x')
                    {
                        sscanf(tmp, "%d", &v);
                        graph[ i ][ j ] = v;
                        graph[ j ][ i ] = v;
                    }
            }



        res = 1 >> 21;

        for(k = 1; k <= n; k++)
            for(i = 1; i <= n; i++)
                for(j = 1; j <= n; j++)
                    graph[ i ][ j ] = min(graph[ i ][ j ], graph[ i ][ k ] + graph[ k ][ j ]);

        for(i = 2; i <= n; i++) res = max(res, graph[ 1 ][ i ]);

        printf("%d\n", res);
    }

    return 0;
}
