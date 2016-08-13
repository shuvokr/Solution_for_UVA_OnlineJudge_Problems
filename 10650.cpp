#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void sieve();
int binary_search(int x);

vector <int> prime;
bool mark[ 32010 ];
int n, m, len, fl, st, en;

int main()
{
    sieve(); prime[ len ] = 1e9;
    int ln;
    while( ~scanf("%d %d", &n, &m) && (n || m) )
    {
        if(n > m) swap(n, m);

        int i = binary_search( n );

        while(prime[i + 2] <= m)
        {
            int dif = prime[i + 1] - prime[ i ];

            if(prime[i + 2] - prime[i + 1] == dif)
            {
                st = i; en = st + 2;
                while(i + 3 < len && prime[i + 3] - prime[i + 2] == dif) en++, i++;
                if(prime[ en ] <= m)
                {
                    if(!st || prime[ st ] - prime[st - 1] != dif)
                    {
                        printf("%d", prime[ st ]);
                        for(int k = st + 1; k <= en; k++) printf(" %d", prime[ k ]); puts("");

                    }
                }
                else break;
            }
            i++;
        }
    }
}
void sieve()
{
    mark[ 0 ] = mark[ 1 ] = false;
    mark[ 2 ] = false;

    for(int i = 4; i < 32001; i += 2) mark[ i ] = false;
    for(int i = 3; i < 32001; i += 2) mark[ i ] = true;

    int sq = sqrt( 32010 ) + 1;

    for(int i = 3; i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < 32001; j += i) mark[ j ] = false;
    prime.push_back( 2 );
    for(int i = 3; i < 32001; i += 2)
        if( mark[ i ] ) prime.push_back( i );
    len = prime.size();
}
int binary_search(int x)
{
    int left = 0, right = len, mid;
    while(right - left > 1)
    {
        mid = (left + right) >> 1;
        if(prime[ mid ] > x) right = mid;
        else left = mid;
    }
    if(prime[ left ] >= x) return left;
    else return right;
}
