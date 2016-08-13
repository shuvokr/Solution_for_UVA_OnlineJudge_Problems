#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool mark[ 3628810 ];
int main()
{
    memset(mark, true, sizeof mark);
    long long T, div, len, tmp, res, ten;
    char n[ 12 ];
    scanf("%lld", &T);
    while( T-- )
    {
        scanf("%s %lld", n, &div); res = 0;
        len = strlen( n ); sort(n, n + len);
        do
        {
            tmp = 0;
            for(int i = 0; i < len; i++) tmp = tmp * 10 + (n[ i ] - 48);
            if(!(tmp % div)) res++;
        }while(next_permutation(n, n + len));

        printf("%lld\n", res);
    }
    return 0;
}
