/*
    Shuvo
    Problem algo: Greade ( =D )
*/
#include <stdio.h>

using namespace std;

int in[ 102 ][ 102 ], cossum[ 102 ][ 102 ];

int main()
{
    int i, j, a, b, tmp, n, m, res;
    while(~scanf("%d %d", &m, &n) && (n || m))
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &tmp);
                in[ i ][ j ] = (tmp == 1) ? 0 : 1;
                if( i )
                    in[ i ][ j ] += (in[i - 1][ j ] && !tmp) ? in[i - 1][ j ] : 0;
            }
        }
        res = -1;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                tmp = in[ i ][ j ];
                for(a = j+1; a < n && in[ i ][ j ] <= in[ i ][ a ]; a++) tmp += in[ i ][ j ];
                for(a = j-1; a > -1 && in[ i ][ j ] <= in[ i ][ a ]; a--) tmp += in[ i ][ j ];
                res = res < tmp ? tmp : res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
