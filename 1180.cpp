#include <stdio.h>
#include <math.h>
bool isprime(long long n)
{
    if(n == 2) return true;
    if(n % 2 == 0 || n == 1) return false;
    int i, len = sqrt( n ) + 1;
    for(i = 3; i < len; i += 2)
        if(n % i == 0) return false;
    return true;
}
int main()
{
    long long i, j, k, ar, n, sum, tmp, next;
    scanf("%lld", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%lld,", &ar);
        if(!isprime( ar )) puts("No");
        else if(!isprime(pow(2, ar) - 1)) puts("No");
        else puts("Yes");
    }
    return 0;
}
