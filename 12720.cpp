#include <stdio.h>
#include <string.h>

char A[ 100005 ];
long long precal[ 100005 ];

long long bigmod ( long long a, long long p, long long mod )
{
    long long res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % mod;
        x = ( x * x ) % mod;
        p >>= 1;
    }
    return res;
}

int main()
{
	long long i, mod = 1000000007ll;
	for(i = 0ll; i < 100001ll; i++) precal[ i ] = bigmod(2ll, i, mod);
	
	int T, kag = 0, len, mid, L, R, p;
	long long ans;
	scanf("%d", &T); getchar();
	while( T-- )
	{
		gets( A );
		len = strlen( A );
		mid = len >> 1;
		ans = 0; p = len - 1;
		if(len&1)
		{
			ans += A[ mid ] == 48 ? 0 : precal[ p ]; p--;
			ans = ans < 5000000000000000000ll ? ans : ans % mod;
			L = mid - 1; R = mid + 1;
			while(L > -1)
			{
				if(A[ L ] == 49)
				{
					ans += A[ L-- ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
					
					ans += A[ R++ ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
				}
				else
				{
					ans += A[ R++ ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
					
					ans += A[ L-- ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
				}
			}
		}
		else
		{
			L = mid - 1; R = mid;
			while(L > -1)
			{
				if(A[ L ] == 49)
				{
					ans += A[ L-- ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
					
					ans += A[ R++ ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
				}
				else
				{
					ans += A[ R++ ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
					
					ans += A[ L-- ] == 48 ? 0 : precal[ p ]; p--;
					ans = ans < 5000000000000000000ll ? ans : ans % mod;
				}
			}
		}
		printf("Case #%d: %lld\n", ++kag, ans % mod);
	}
	return 0;
}
