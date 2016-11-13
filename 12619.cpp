#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int pr = 1001, mod = 1000000007;
int prime[ 170 ], ind;
bool mark[ pr ];
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i * i; j < pr; j += i + i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i;
}

long long bigmod ( long long a, long long p, long long md )
{
    long long res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % md;
        x = ( x * x ) % md;
        p >>= 1;
    }
    return res;
}

int vTmp[ 1000005 ];

int main()
{
	primelist();
	char num[ 10 ];
	int T, D, G, kag = 0;
	long long ans, ret;
	scanf("%d", &T);
	while( T-- )
	{
		memset(vTmp, 0, sizeof vTmp); ans = 0;
		scanf("%d", &D); getchar(); ret = 1;
		while( D-- )
		{
			gets( num );
			G = atoi( num );
			bool flag = G < 0 ? false : true;
			G -= G < 0 ? G + G : 0;
			for(int i = 0; prime[ i ] <= G && i < ind; i++)
			{
				if((G / prime[ i ]) * prime[ i ] != G) continue;
				int cou = 0;
				while((G / prime[ i ]) * prime[ i ] == G && G)
				{
					cou++; G /= prime[ i ];
				}
				long long tmp = vTmp[ prime[ i ] ] + 1;
				long long MI = bigmod(tmp, mod - 2, mod);
				ret = (ret * MI);
				vTmp[ prime[ i ] ] += flag ? cou : -cou;
				ret = ret < mod ? ret : ret % mod;
				ret *= (vTmp[ prime[ i ] ] + 1);
				ret = ret < mod ? ret : ret % mod;
			}
			if(G > 1)
			{
				long long tmp = vTmp[ G ] + 1;
				long long MI = bigmod(tmp, mod - 2, mod);
				ret = (ret * MI) % mod;
				
				vTmp[ G ] += flag ? 1 : -1;
				ret *= (vTmp[ G ] + 1);
				ret = ret < mod ? ret : ret % mod;
			}
			ans += ret;
			ans = ans < mod ? ans : ans % mod;
		}
		
		printf("Case %d: %lld\n", ++kag, ans);
	}
	return 0;
}
