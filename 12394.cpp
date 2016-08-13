#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef set<int> se;

char name[ 1010 ][ 15 ];
vector <vi> vr;

int main()
{
    int n, k, i, j, tmp, res;
    bool mark;
    while(~scanf("%d %d", &k, &n) && n)
    {
        se st[ 1010 ];
        vr.assign(n+2, vi());
        n++; k++;
        for(i = 1; i < n; i++) memset(name[ i ], 0, sizeof name[ i ]);
        for(i = 1; i < n; i++)
        {
            scanf("%s", name[ i ]);
            for(j = 1; j < k; j++)
            {
                scanf("%d", &tmp);
                vr[ tmp ].push_back( i );
                st[ tmp ].insert( i );
            }
        }
        res = 0;
        for(i = 1; i < n; i++)
        {
            mark = false;
            int a = vr[ i ].size(), b = st[ i ].size();
            if(a != b) mark = true;
            else if(b != k - 1) mark = true;
            else
            {
                for(j = 1; j < k; j++)
                {
                    tmp = vr[ i ][ j - 1 ];
                    if(strcmp(name[ i ], name[ tmp ]) == 0) mark = true, j = k;
                }
            }
            if( mark ) res++;
        }
        if( !res ) puts("NO PROBLEMS FOUND");
        else if(res > 1) printf("%d PROBLEMS FOUND\n", res);
        else puts("1 PROBLEM FOUND");
    }
    return 0;
}
