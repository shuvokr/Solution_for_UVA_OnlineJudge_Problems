#include <stdio.h>
int n, g, ans, in[ 102 ], i, x, y;

int main()
{
    while(scanf("%d %d", &n, &g)!=EOF)
    {
        ans = 0; int ind = 0;
        for(i = 0; i < 101; i++) in[i] = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            if(x > y) ans += 3;
            else if(x == y && g) ans += 3, g--;
            else if(x == y) ans++;
            else in[y - x]++;
        }
        for(i = 1; i < 101 && g; i++)
        {
            if(in[ i ] > 0)
            {
                ind = g / (i + 1);
                if(in[ i ] <= ind)
                {
                    ans += (3 * in[ i ]);
                    g -= in[i] * (i + 1);
                }
                else
                {
                    ans += (3 * ind);
                    g -= ind * (i + 1);
                    in[i] -= ind;

                    ind = g / i;
                    if(in[ i ] <= ind)
                    {
                        ans += in[ i ];
                        g -= (in[i] * i);
                    }
                    else
                    {
                        ans += ind;
                        g -= (ind * i);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

