#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool ck(int aa, int bb, int cc);
bool mark[ 10 ];
int cou1, cou2;
int y[ 107 ], z[ 2366 ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, a, b, tmp, len, tot = 0;

    for(i = 100; i < 1000; i++)
    {
        for(j = i; j < 1000; j++)
        {
            if(!(i % 10) && !(j % 10)) continue;
            tmp = i * j;
            if(tmp & 1) continue;
            len = log10( tmp ) + 1;
            if(len == 6 && ck(i, j, tmp)) y[ tot++ ] = tmp;
        }
    }
    sort(y, y + tot); tot--;
    for(i = 0; i < tot; i++) if(y[ i ] == y[i + 1]) y[ i ] = 0;

    tot = 0;
    for(i = 1000; i < 10000; i++)
    {
        for(j = i; j < 10000; j++)
        {
            if(!(i % 10) && !(j % 10)) continue;
            tmp = i * j;
            if(tmp & 1) continue;
            len = log10( tmp ) + 1;
            if(len != 8) continue;
            if(ck(i, j, tmp)) z[ tot++ ] = tmp;
        }
    }
    sort(z, z + tot);
    for(i = 0; i < tot; i++) if(z[i] == z[i + 1]) z[ i ] = 0;

    int m;

    while(~scanf("%d", &m) )
    {
        if(m == 4) printf("1260\n1530\n6880\n");
        if(m == 6) for(i = 0; i < 107; i++) if(y[ i ]) printf("%d\n", y[ i ]);
        if(m == 8) for(i = 0; i < 2366; i++) if(z[ i ]) printf("%d\n", z[ i ]);
        puts("");
    }
    return 0;
}
bool ck(int aa, int bb, int cc)
{
    int ch1[ 10 ], ch2[ 10 ];
    memset(ch1, 0, sizeof ch1);
    memset(ch2, 0, sizeof ch2);
    int i;
    i = 0;
    while( aa )
    {
        int t = aa % 10;
        ch1[ t ]++;
        aa /= 10;
    }
    while( bb )
    {
        int t = bb % 10;
        ch1[ t ]++;
        bb /= 10;
    }
    while( cc )
    {
        int t = cc % 10;
        ch2[ t ]++;
        cc /= 10;
    }
    for(i = 0; i < 10; i++)
        if(ch1[ i ] != ch2[ i ]) break;
    if(i == 10) return true;
    else return false;
}
