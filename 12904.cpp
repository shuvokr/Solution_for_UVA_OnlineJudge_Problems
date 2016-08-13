#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

double DP(int p, int cou, double val, int a, int b, int c);

int n, save[ 161 ], mark[ 161 ][ 161 ][ 161 ], res[ 4 ], ck;
double mx, D, mamo[ 161 ][ 161 ][ 161 ];

int main()
{
    int T, kag = 0; scanf("%d", &T);
    memset(mark, 0, sizeof mark); ck = 1;
    while( T-- )
    {
        scanf("%d", &n); memset(save, 0, sizeof save);
        D = n / 4.0;
        for(int i = 0, tmp; i < n; i++) scanf("%d", &tmp), save[ tmp ]++;
        for(int i = 0; i < 161; i++) save[ i ] += save[i - 1];
        mx = 10000000000000000.0000;
        double ans = DP(0, 0, 0, 0, 0, 0); ck++;
        printf("Case %d: %d %d %d\n", ++kag, res[ 0 ], res[ 1 ], res[ 2 ]);
    }
    return 0;
}
double DP(int p, int cou, double val, int a, int b, int c)
{
    if(cou >= 3)
    {
        int tmp = save[ 160 ] - save[ c ];
        double xx = D - (double)tmp;
        if(xx < 0) xx *= -1;
        if(mx > val + xx)
        {
            mx = val + xx;
            res[ 0 ] = a; res[ 1 ] = b; res[ 2 ] = c;
            //cout << a << " " << b << " " << c << " " << val << endl;
        }
        return xx;
    }
    if(p > 160) return 100000000000.00;
    double &ret = mamo[ a ][ b ][ c ];
    if(mark[ a ][ b ][ c ] == ck) return ret;
    mark[ a ][ b ][ c ] = ck;
    ret = 100000000000000.00;

    if(cou == 0)
    {
        for(int i = p; i < 162; i++)
        {
            int tmp = save[ i ];
            double xx = D - (double)tmp;
            if(xx < 0) xx *= -1;
            ret = min(ret, DP(i + 1, cou + 1, val + xx, i, b, c));
        }
    }
    if(cou == 1)
    {
        for(int i = p; i < 162; i++)
        {
            int tmp = save[ i ] - save[ a ];
            double xx = D - (double)tmp;
            if(xx < 0) xx *= -1;
            ret = min(ret, DP(i + 1, cou + 1, val + xx, a, i, c));
        }
    }
    if(cou == 2)
    {
        for(int i = p; i < 162; i++)
        {
            int tmp = save[ i ] - save[ b ];
            double xx = D - (double)tmp;
            if(xx < 0) xx *= -1;
            ret = min(ret, DP(i + 1, cou + 1, val + xx, a, b, i));
        }
    }
    return ret;
}

