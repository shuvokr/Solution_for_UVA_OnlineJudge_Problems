#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define CLR( n, v ) memset(n, v, sizeof n)

int LCS(int fs, int sc);

int ar1[ 1002 ], i, ar2[ 1002 ], point, ind1, ind2;
char in[ 10010 ], tok[ 25 ];
int mamo[ 1002 ][ 1002 ];
map <string, int> m;
bool mark;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int kag = 0;
    while( gets( in ) )
    {
        m.clear();
        mark = true;
        if(in[ 0 ] == NULL) mark = false;
        point = 1;
        ind1 = ind2 = 0;

        i = 0;
        int len = strlen( in );
        while(i < len)
        {
            int k = 0; CLR(tok, 0);
            while(i < len && (isalpha( in[ i ] ) || isdigit( in[ i ] )))
                    tok[ k++ ] = in[ i++ ];
            if( k && m[ tok ] == 0 ) m[ tok ] = point++;
            if( k ) ar1[ ind1++ ] = m[ tok ];
            i++;
        }

        gets( in );
        if(in[ 0 ] == NULL) mark = false;
        i = 0;
        len = strlen( in );
        while(i < len)
        {
            int k = 0; CLR(tok, 0);
            while(i < len && (isalpha( in[ i ] ) || isdigit( in[ i ] )))
                    tok[ k++ ] = in[ i++ ];
            if( k && m[ tok ] == 0 ) m[ tok ] = point++;
            if( k ) ar2[ ind2++ ] = m[ tok ];
            i++;
        }
        //printf("  %d %d\n", ind1, ind2);
        if( !mark ) printf("%2d. Blank!\n", ++kag);
        else
        {
            //for(int i = 0; i < ind1; i++) printf("%d ", ar1[ i ]); puts("");
            //for(int i = 0; i < ind2; i++) printf("%d ", ar2[ i ]); puts("");
            CLR(mamo, -1);
            printf("%2d. Length of longest match: %d\n", ++kag, LCS(0, 0));
        }
    }
    return 0;
}
int LCS(int fs, int sc)
{
    if(fs == ind1) return 0;
    if(sc == ind2) return 0;
    if(mamo[ fs ][ sc ] != -1) return mamo[ fs ][ sc ];
    int ret = 0;
    if(ar1[ fs ] == ar2[ sc ]) ret = 1 + LCS(fs + 1, sc + 1);
    else ret = max(ret, max(LCS(fs + 1, sc), LCS(fs, sc + 1)));
    mamo[ fs ][ sc ]= ret;
    return ret;
}
