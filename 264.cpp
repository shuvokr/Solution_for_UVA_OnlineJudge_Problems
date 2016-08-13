#include <stdio.h>
int f(int n) { return n * (n + 1) / 2; }
int main()
{
    int n, tmp;
    while( ~scanf("%d", &n) )
    {
        if(n == 1)
        {
            puts("TERM 1 IS 1/1");
            continue;
        }
        int low = 1, high = 4999, mid = (low + high) / 2, last;
        while( high - low > 1 )
        {
            tmp = f( mid );
            if(tmp < n) low = mid;
            else high = mid;
            mid = (low + high) / 2;
        }
        low++;
        low % 2 == 0 ?  printf("TERM %d IS %d/%d\n", n, n - f(low - 1), f( low ) - n + 1):
                        printf("TERM %d IS %d/%d\n", n, f( low ) - n + 1, n - f(low - 1));
    }
    return 0;
}
