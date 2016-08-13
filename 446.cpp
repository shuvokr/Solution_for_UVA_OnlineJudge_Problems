#include <stdio.h>
#include <string.h>
int main()
{
    int a, b, c, i, k, T;
    scanf("%d", &T);
    char cc[ 14 ], ccc[ 14 ], sign;
    while(T--)
    {
        scanf("%X %c %X", &a, &sign, &b);
        c = a; k = 0;
        while(c > 0)
        {
            cc[ k++ ] = (c % 2)+'0';
            c >>= 1;
        }
        for(i = k; i < 13; i++) printf("0");
        for(i = k-1; i > -1; i--) printf("%c", cc[ i ]);

        printf(" %c ", sign);

        c = b; k = 0;
        while(c > 0)
        {
            cc[ k++ ] = (c % 2)+'0';
            c >>= 1;
        }
        for(i = k; i < 13; i++) printf("0");
        for(i = k-1; i > -1; i--) printf("%c", cc[ i ]);

        printf(" = ");
        if(sign == '+')
            printf("%d\n", a + b);
        else printf("%d\n", a - b);
    }
    return 0;
}
