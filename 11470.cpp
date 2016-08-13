#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int i, j, k, n, input[12][12], sum, ans[6], sqr, ck, z = 0;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        if(n < 0) n = abs(n);
        ck = n;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <=n; j++)
            {
                scanf("%d", &input[i][j]);
            }
        }
        if(n % 2 == 0) sqr = n / 2;
        else sqr = (n / 2) + 1;
        sum = 0; k = 0; int x = 1;
        for(k = x; k <= sqr; k++)
        {
            for(j = k; j <= n; j++)
            {
                sum += input[k][j];
                sum += input[n][j];
            }

            for(j = k+1; j <= n-1; j++)
            {
                sum += input[j][k];
                sum += input[j][n];
            }
            ans[k] = sum;
            n--;
            sum = 0; x++;
        }
        if(ck % 2 != 0)
        ans[sqr] /= 2;
        printf("Case %d: %d", ++z, ans[1]);

        for(i = 2; i <= sqr; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
