#include <stdio.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int i, n, a;
    while(~scanf("%d", &n))
    {
        a = 0;
        for(i = 0; i < 32; i++)
            a = (n & (1 << i)) ? a | 1 << ( ( 3 - (i >> 3) ) << 3 ) + (i % 8) : a;
        printf("%d converts to %d\n", n, a);
    }
    return 0;
}

