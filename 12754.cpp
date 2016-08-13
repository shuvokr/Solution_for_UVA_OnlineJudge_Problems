#include <stdio.h>
#include <string.h>
int main()
{
    //freopen("input.txt", "r", stdin);
    char in[ 30 ][ 35 ];
    int r, c, len = 0, T, kag = 0;
    scanf("%d", &T); getchar();
    while(T--)
    {
        memset(in, 0, sizeof in);
        c = r = 0;
        bool mark = true;
        while(gets(in[ r ]) && in[ r ][ 0 ] != '*')
        {
            if(in[ r ][ 0 ] == NULL) continue;
            if(!c) c = strlen(in[ r ]);
            else if(c != strlen(in[ r ])) mark = false;
            r++;
        }
        if( !mark ) { printf("Case %d: Bad\n", ++kag); continue; }
        int D = c - 2;
        if(D * 2 + 3 != r) { printf("Case %d: Bad\n", ++kag); continue; }
        if(in[ 0 ][ 0 ] != '.' || in[ 0 ][c - 1] != '.') { printf("Case %d: Bad\n", ++kag); continue; }
        mark = true;
        for(int i = 1; i < c - 1; i++)
            if(in[ 0 ][ i ] != '-') mark = false, i = c;
        if( !mark ) { printf("Case %d: Bad\n", ++kag); continue; }
        int mid = r >> 1;
        if(strcmp(in[ 0 ], in[ mid ]) != 0) { printf("Case %d: Bad\n", ++kag); continue; }
        if(strcmp(in[ 0 ], in[r - 1]) != 0) { printf("Case %d: Bad\n", ++kag); continue; }
        if(mid != 1){
        if(in[ 1 ][ 0 ] != '|' || in[ 1 ][c - 1] != '|') { printf("Case %d: Bad\n", ++kag); continue; }
        mark = true;
        for(int i = 1; i < c - 1; i++)
            if(in[ 1 ][ i ] != '.') mark = false, i = c;
        if( !mark ) { printf("Case %d: Bad\n", ++kag); continue; }
        mark = true;
        for(int i = 2; i < mid; i++)
            if(strcmp(in[ 1 ], in[ i ]) != 0) mark = false, i = mid;
        for(int i = mid + 1; i < r - 1; i++)
            if(strcmp(in[ 1 ], in[ i ]) != 0) mark = false, i = r;
        }
        if( !mark ) printf("Case %d: Bad\n", ++kag);
        else printf("Case %d: %d\n", ++kag, D);
    }
    return 0;
}
