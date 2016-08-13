#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define pf printf
#define sf scanf
#define lu unsigned long int
#define N 102
int main()
{
    int MAX, i, j, a, b, ar1[N], ar2[N], c[N][N], z = 0;
    while(sf("%d%d",&a,&b) != EOF)
    {
        if(a == 0 && b == 0) return 0;

        for(i = 0; i < a; i++) sf("%d",&ar1[i]);
        for(i = 0; i < b; i++) sf("%d",&ar2[i]);

        if(a > b) MAX = a; else MAX = b;

        for(i = 0; i < MAX; i++) c[i][0] = c[0][i] = 0;

        for(i = 1; i <= a; i++){
            for(j = 1; j <= b; j++)
            {
                if(ar1[i - 1] == ar2[j - 1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else if(c[i - 1][j] >= c[i][j - 1])
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = c[i][j - 1];
            }
        }
        pf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++z, c[i - 1][j - 1]);
    }
    return 0;
}
