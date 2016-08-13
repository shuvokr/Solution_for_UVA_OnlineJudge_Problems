/*
    Shuvo
    DP: LIS
    UVA 11081
*/

#include <stdio.h>
#include <string.h>

using namespace std;

long long DP(int lena, int lenb, int lenc);

bool mark[ 62 ][ 62 ][ 62 ];
long long mamo[ 62 ][ 62 ][ 62 ];
char a[ 62 ], b[ 62 ], c[ 62 ];
const int MOD = 10007;
int a_len, b_len, c_len;

int main()
{
    int T; scanf("%d", &T);
    while( T-- )
    {
        scanf("%s %s %s", a, b, c);
        a_len = strlen( a ); b_len = strlen( b ); c_len = strlen( c );
        memset(mark, false, sizeof mark);
        printf("%lld\n", DP(0, 0, 0) % MOD);
    }
    return 0;
}
long long DP(int lena, int lenb, int lenc)
{
    if(lenc == c_len) return 1;
    long long &ret = mamo[ lena ][ lenb ][ lenc ];
    if(mark[ lena ][ lenb ][ lenc ]) return ret;
    mark[ lena ][ lenb ][ lenc ] = true; ret = 0;

    for(int i = lena; i < a_len; i++)
    {
        if(a_len - i + b_len - lenb < c_len - lenc) i = a_len;
        else
            if(a[ i ] == c[ lenc ]) ret = (ret + DP(i + 1, lenb, lenc + 1)) % MOD;
    }

    for(int i = lenb; i < b_len; i++)
    {

        if(a_len - lena + b_len - i < c_len - lenc) i = b_len;
        else
            if(b[ i ] == c[ lenc ]) ret = (ret + DP(lena, i + 1, lenc + 1)) % MOD;
    }
    return ret;
}
