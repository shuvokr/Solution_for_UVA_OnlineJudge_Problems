#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char in[ 90 ];
    int len, res, cou, i, T;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in ); cou = res = i = 0;
        len = strlen( in );
        while(i < len)
        {
            while(in[ i ] == 'O' && i < len)
            {
                i++; cou++; res += cou;
            }
            while(in[ i ] == 'X' && i < len) i++;
            while(in[ i ] != 'X' && in[ i ] != 'O' && i < len) i++;
            cou = 0;
        }
        printf("%d\n", res);
    }
    return 0;
}
