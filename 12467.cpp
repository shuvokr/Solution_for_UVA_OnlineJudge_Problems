#include <stdio.h>
#include <string.h>

int main()
{
    char in[ 1000010 ];
    int T, i, ans; scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in ); ans = 0;
        for(i = strlen( in ) - 1; i > -1; i--)
        {
            if(in[ i ] == in[ 0 ])
            {
                int a = 0, b = i;
                while(b > -1 && in[ a ] == in[ b ]) a++, b--;
                ans = ans < a ? a : ans;
            }
            i = ans < i ? i : -1;
        }
        for(i = ans - 1; i > -1; i--) printf("%c", in[ i ]); puts("");
    }
    return 0;
}
