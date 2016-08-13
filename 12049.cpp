#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int i, j, n, m, fs[ 10010 ], ls[ 10010 ], cou, T, f, l;
int main()
{
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++) scanf("%d", &fs[ i ]);
        for(i = 0; i < n; i++) scanf("%d", &ls[ i ]);
        sort(fs, fs + m); sort(ls, ls + n);
        cou = f = l = 0;
        while( true )
        {
            if(f == m || l == n) break;
            if(fs[ f ] == ls[ l ]) f++, l++;
            else if(fs[ f ] > ls[ l ]) l++, cou++;
            else f++, cou++;
        }
        cou += m - f + n - l;
        printf("%d\n", cou);
    }
    return 0;
}
