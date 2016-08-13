#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int Tast, HL[ 10000 ][ 2 ], i, Q, D, qurey, j, mark, res;
    bool space = false;
    scanf("%d", &Tast);
    while(Tast--)
    {
        if( space ) puts("");
        else space = true;
        char company[ 10000 ][ 22 ];
        scanf("%d", &D);
        i = 0;
        for(; i < D; i++)
            scanf("%s%d%d", company[ i ], &HL[ i ][ 0 ], &HL[ i ][ 1 ]);
        scanf("%d", &qurey);
        i = 0;
        for(; i < qurey; i++)
        {
            scanf("%d", &Q);
            mark = j = 0;
            for(; j < D; j++)
            {
                if(Q >= HL[ j ][ 0 ] && Q <= HL[ j ][ 1 ]) mark++, res = j;
                if( mark == 2 ) j = D;
            }
            if(mark == 1) puts(company[res]);
            else puts("UNDETERMINED");
        }
    }
    return 0;
}
