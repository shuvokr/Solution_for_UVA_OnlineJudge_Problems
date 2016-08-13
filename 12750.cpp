#include <stdio.h>
#include <string.h>

int main()
{
    int n, T, kag = 0, cnt, res;
    bool mark;
    char ch[ 2 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n); cnt = 0; mark = false;
        getchar();
        for(int i = 0; i < n; i++)
        {
            gets( ch );
            if( mark ) continue;
            cnt += ch[ 0 ] == 'W' ? -cnt : 1;
            if(cnt == 3)
            {
                mark = true;
                res = i + 1;
            }
        }
        if( mark ) printf("Case %d: %d\n", ++kag, res);
        else printf("Case %d: Yay! Mighty Rafa persists!\n", ++kag);
    }
    return 0;
}
