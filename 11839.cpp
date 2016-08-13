#include <stdio.h>
int main()
{
    int T, n, cou, res;
    while(scanf("%d", &T) && T)
    {
        while( T-- )
        {
            cou = 0;
            for(int i = 0; i < 5; i++)
            {
                scanf("%d", &n);
                if(n < 128)
                {
                    cou++;
                    res = i;
                }
            }
            if(cou == 1) printf("%c\n", res + 65);
            else puts("*");
        }
    }
    return 0;
}
