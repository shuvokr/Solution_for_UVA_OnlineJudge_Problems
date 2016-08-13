#include <stdio.h>
#include <vector>
using namespace std;

void bit_sieve();
bool isok(int n);

#define M 10000
int marked[ M / 64 + 2 ];

#define on(x) (marked[x/64] & (1 << ((x%64) / 2)))
#define mark(x) marked[x/64] |= ( 1 << ((x%64) / 2 ))

vector <int> prime;
int main()
{
    bit_sieve();
    int i, n;
    bool yes;
    while(~scanf("%d", &n))
    {
        yes = false;
        if(n%2)
        {
            if(isok(n - 2)) i = 2, yes = true;
        }
        else
        {

            i = (n >> 1) - 1;
            if(!(i&1)) i--;
            for(; i > 1 ; i -= 2)
                if(isok( i ) && isok(n - i)) { yes = true; break; }
        }

        if( yes ) printf("%d is the sum of %d and %d.\n", n, i, n - i);
        else printf("%d is not the sum of two primes!\n", n);
    }

    return 0;
}
void bit_sieve()
{
    for(int i = 3; i * i < M; i += 2)
        if( !on( i ) )
            for(int j = i * i; j <= M; j += i + i) mark( j );

    prime.push_back( 2 );
    for(int i = 3; i < M; i += 2)
        if( !on( i ) ) prime.push_back( i );
}
bool isok(int n)
{
    if(n < 2) return false;
    for(int i = 0; i < prime.size() && prime[ i ] * prime[ i ] <= n; i++)
        if(n % prime[ i ] == 0) return false;
    return true;
}  
