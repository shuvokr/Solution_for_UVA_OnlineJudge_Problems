#include <cstdio>
#include <cstring>

using namespace std;

int dp(int pos, int cost);

int target, n, in[ 25 ];
bool res;
int mamo[ 25 ][ 1010 ];

int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &target, &n);
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]);
        res = false; memset(mamo, -1, sizeof mamo);
        int call = dp( 0, 0 );
        puts(res ? "YES" : "NO");
    }
    return 0;
}
int dp(int pos, int cost)
{
    if(cost > target) return 0;
    if( res ) return 0;
    if(cost == target) res = true;
    if(pos == n) return 0;
    if(mamo[ pos ][ cost ] != -1) return mamo[ pos ][ cost ];

    mamo[ pos ][ cost ] = in[ pos ] + dp(pos + 1, cost + in[ pos ]);
    mamo[ pos ][ cost ] = dp(pos + 1, cost);
}
