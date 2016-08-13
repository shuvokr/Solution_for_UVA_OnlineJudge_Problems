#include<cstdio>
#include<cmath>
int main()
{
    long long int n = 0;
    int kag = 0;
    while(~scanf("%lld", &n) && n) printf("Case %d: %d\n", ++kag, int( ceil((3 + sqrt(9 + 8 * n)) / 2.0) ));
    return 0;
}
