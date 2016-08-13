#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define lu unsigned long int
#define sf scanf
#define pf printf
char x[130], y[130];
int c[150][150];
int LCS(int m, int n)
{
    int i, j;

    for(i = 0; i <= m; ++i) c[i][0] = 0;
    for(j = 0; j <= n; ++j) c[0][j] = 0;

    for(i = 1; i <= m; ++i)
        for(j = 1; j <= n; ++j)
        {
            if(x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i - 1][j] >= c[i][j - 1])
                c[i][j] = c[i - 1][j];
            else c[i][j] = c[i][j - 1];
        }

    return c[m][n];
}
int main()
{
    int len, i, j, k, count, z = 0;
    while(gets(x))
    {
        if(x[0] == '#') return 0;
        gets(y);
        int a = strlen(x), b = strlen(y);
        count = LCS(a, b);

        pf("Case #%d: you can visit at most %d cities.\n",++z, c[a][b]);

    }
    return 0;
}
