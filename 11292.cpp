#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, dragon[ 20010 ], knight[ 20010 ];

int main()
{
    while(scanf("%d %d", &m, &n) && (m || n))
    {
        for(int i = 0; i < m; i++) scanf("%d", &dragon[ i ]);
        for(int i = 0; i < n; i++) scanf("%d", &knight[ i ]);
        if(n < m)
        {
            puts("Loowater is doomed!");
            continue;
        }
        sort(dragon, dragon + m);
        sort(knight, knight + n);
        int res = 0, dr = 0;
        for(int i = 0; i < n && dr != m; i++)
        {
            if(knight[ i ] < dragon[ dr ]) continue;
            dr++; res += knight[ i ];
        }
        if(dr == m) printf("%d\n", res);
        else puts("Loowater is doomed!");
    }
    return 0;
}
