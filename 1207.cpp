#include <stdio.h>
#include <string.h>

int DP(int x, int y);

char a[ 1001 ], b[ 1001 ];
int mamo[ 1001 ][ 1001 ], lena, lenb;

int main()
{
    while(~scanf("%d %s", &lena, a))
    {
        scanf("%d %s", &lenb, b);
        memset(mamo, -1, sizeof mamo);
        printf("%d\n", DP(0, 0));
    }
    return 0;
}
int DP(int x, int y)
{
    if(x >= lena && y >= lenb) return 0;
    if(mamo[ x ][ y ] != -1) return mamo[ x ][ y ];
    int ret = 1 << 29, aa = 0, bb = 0, cc = 0;
    if(a[ x ] == b[ y ]) ret = DP(x + 1, y + 1);
    aa = 1 + DP(x + 1, y);
    bb = 1 + DP(x, y + 1);
    cc = 1 + DP(x + 1, y + 1);
    aa = aa < bb ? aa : bb;
    aa = aa < cc ? aa : cc;
    ret = ret < aa ? ret : aa;
    return mamo[ x ][ y ] = ret;
}
