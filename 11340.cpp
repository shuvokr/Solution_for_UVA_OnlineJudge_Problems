/*
    Shuvo
    algo : Ad Hoq
*/
#include<stdio.h>
#include<string.h>
#include <iostream>

using namespace std;

int main()
{
    int counter, i, j, len, T, tmp, mapping[ 300 ], fres, lres;
    int tot;
    unsigned char ch;
    scanf("%d", &T);
    while( T-- )
    {
        memset(mapping, 0, sizeof mapping);
        scanf("%d", &counter);
        for(i = 0; i < counter; i++)
        {
            cin >> ch;
            scanf("%d\n", &len);
            mapping[ ch ] = len;
        }
        scanf("%d\n", &counter);
        tot = 0;
        for(i = 0; i < counter; i++)
        {
            while( true )
            {
                scanf("%c", &ch);
                if(ch == 10) break;
                tot += mapping[ ch ];
            }
        }

        tmp = tot % 100;
        tot /= 100;
        (tmp > 9) ? printf("%d.%d$\n", tot, tmp) : printf("%d.0%d$\n", tot, tmp);
    }
    return 0;
}
