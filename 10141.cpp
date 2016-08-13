#include <stdio.h>
#include <string.h>
int main()
{
    char name[ 85 ], item[ 85 ], last[ 85 ];
    float tm, best, take, t;
    int n, m, i, price, j, kag = 0, space = 1;
    while(~scanf("%d %d", &n, &m) && (n || m))
    {
        if(space == 0) puts("");
        else space = 0;
        getchar();
        for(i = 0; i < n; i++) gets( name );
        best = 1E37;
        take = 0.0;
        for(i = 0; i < m; i++)
        {
            gets( name );
            scanf("%f %d", &tm, &price);
            getchar();
            for(j = 0; j < price; j++) gets( item );
            t = (float) price;
            if(t > take || (t == take && best > tm))
            {
                best = tm;
                take = t;
                strcpy(last, name);
                last[ strlen( name ) ] = NULL;
            }
        }
        printf("RFP #%d\n", ++kag);
        puts( last );
    }
    return 0;
}
