#include <stdio.h>
#include <string.h>

int main()
{
    char in[ 55 ];
    int T, kag = 0, i; scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in );
        int len = strlen( in );
        int ans = -1;

        for(i = 0; i < len; i++)
        {
            if(in[ i ] == '<')
            {
                int cou = 1;
                if(i + 1 != len && (in[i + 1] == '-' || in[i + 1] == '='))
                {
                    i++;
                    char ch = in[ i ];
                    cou++;
                    int next = i + 1;
                    while(next < len && in[ next ] == ch) cou++, next++;
                    i = next - 1;
                }
                ans = ans < cou ? cou : ans;
            }
        }

        for(i = len - 1; i > -1; i--)
        {
            if(in[ i ] == '>')
            {
                int cou = 1;
                if(i - 1 != -1 && (in[i - 1] == '-' || in[i - 1] == '='))
                {
                    i--;
                    char ch = in[ i ];
                    cou++;
                    int next = i - 1;
                    while(next > -1 && in[ next ] == ch) cou++, next--;
                    i = next + 1;
                }
                ans = ans < cou ? cou : ans;
            }
        }
        printf("Case %d: %d\n", ++kag, ans);
    }
    return 0;
}

