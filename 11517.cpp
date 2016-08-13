#include <stdio.h>
#include <string.h>
void dp();
const int INF = 1 << 30;
int mamo[ 10010 ], res[ 10010 ], in[ 110 ], n, maxn, T, i;
int main()
{
    scanf("%d", &T);
    while( T-- )
    {
        int tmp = 1 << 30;
        scanf("%d %d", &maxn, &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &in[ i ]);
            if(maxn == in[ i ]) tmp = 0;
        }
        if(!tmp)
        {
            printf("%d 1\n", tmp);
            continue;
        }
        for(i = 0; i < 10001; i++) mamo[ i ] = 0, res[ i ] = INF;
        mamo[ 0 ] = 1; dp();
    }
    return 0;
}
void dp()
{
    res[ 0 ] = 0;
    for(int k = 0; k < n; k++)
        for(int j = 10000; j >= in[ k ]; j--)
            if(mamo[j - in[ k ]])
                mamo[ j ] = 1,
                res[ j ] = res[ j ] > res[j - in[ k ]] + 1 ? res[j - in[ k ]] + 1 : res[ j ];
    for(i = maxn; i < 10001; i++) if(mamo[ i ]) printf("%d %d\n", i, res[ i ]), i = 10001;
}
