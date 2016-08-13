#include <cstdio>
#include <cstring>
bool isok(int s, int e);
char in[ 1010 ];
int res[ 1010 ] , i, j, T, len, s, e, cou, max;
int main()
{
    scanf("%d", &T); getchar();
    res[ 1 ] = 1; max = 1 << 31;
    while( T-- )
    {
        gets( in ); cou = 0;
        len = strlen( in );
        for(i = 1; i < len; i++)
        {
            res[i + 1] = 1 << 30;
            for(j = 0; j <= i; j++)
                if(isok(j, i))
                {
                    cou = res[i + 1] < res[ j ] + 1 ? res[i + 1] : res[ j ] + 1;
                    res[i + 1] = cou;
                }
        }
        printf("%d\n", res[ len ]);
    }
    return 0;
}
bool isok(int s, int e)
{
    while(s < e)
    {
        if(in[ s ] != in[ e ]) return false;
        s++; e--;
    }
    return true;
}
