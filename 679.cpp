#include <stdio.h>
int main()
{
    int D, I, i, left, right, maxp, T, now, sav[ 21 ];
    sav[ 1 ] = 2;
    for(i = 2; i < 21; i++) sav[ i ] = sav[i - 1] << 1;
    while(~scanf("%d", &T) && T != -1)
    {
        while( T-- )
        {
            scanf("%d %d", &D, &I);
            maxp = sav[ D ];
            now = 1;
            left = 2; right = 3;
            for(;left < maxp && right < maxp;)
            {
                switch(I % 2)
                {
                    case 1 :
                        now = left;
                        I = (I >> 1) + 1;
                        goto jump;
                    case 0 :
                        now = right;
                        I >>= 1;
                        goto jump;
                }
                jump:
                left = now << 1, right = left + 1;
            }
            printf("%d\n", now);
        }
    }
    return 0;
}
