#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d", &T);
	long long M, W, num, tot;
	while( T-- )
	{
		scanf("%lld %lld", &M, &W);
		priority_queue <long long> pq;
		for(int i = 0; i < M; i++)
		{
			scanf("%lld", &num);
			num *= (-1ll);
			pq.push( num );
		}
		tot = 0;
		int ans = 0;
		while(!pq.empty() && tot < W)
		{
            num = pq.top();
            pq.pop();
            num *= (-1ll);
            tot += num;
            ans += tot <= W ? 1 : 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
