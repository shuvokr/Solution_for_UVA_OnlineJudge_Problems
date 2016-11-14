#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i;
	long long ar[ 301 ]; ar[ 1 ] = ar[ 2 ] = 1; ar[ 0 ] = 0;
	for(i = 3; i < 301; i++) ar[ i ] = (ar[i - 1] + ar[i - 2]) % 100;
	for(i = 2; i < 301; i++) ar[ i ] += ar[i - 1];
	
	long long a, b, tmp, ans;
	int T;
	scanf("%d", &T); getchar();
	char num[ 30 ], *point;
	while( T-- )
	{
		gets( num );
		point = strtok(num, " ");
		a = atol( point );
		point = strtok(NULL, " ");
		b = atol( point );
		
		tmp = b / 300;
		b -= (tmp * 300);
		ans = (tmp * ar[ 300 ]) + ar[ b ];
		
		a--;
		tmp = a / 300;
		a -= (tmp * 300);
		ans -= ((tmp * ar[ 300 ]) + ar[ a ]);
		
		printf("%lld\n", ans);
	}
	return 0;
}
