/*
        Shuvo
        Problem Algo: Simpe Ad hoc
        Problem ID: 414
        Problem name: Machined Surfaces
*/
#include <stdio.h>
using namespace std;
int main()
{
    int maxi, res, cou, n, in[ 13 ], i, k;
    char c;
    while(~scanf("%d", &n))
    {
        if( !n ) return 0;
        maxi = -1; k = 0;
        while(n--)
        {
            cou = 0; i = 0;
            while(i < 26)
            {
                scanf("%c", &c);
                if(c == 'X') cou++;
                i++;
            }
            if(maxi < cou) maxi = cou;
            in[ k++ ] = cou;
        }
        res = 0;
        for(i = 0; i < k; i++)
            if(in[ i ] < maxi)
                res += maxi - in[ i ];
        printf("%d\n", res);
    }
}
