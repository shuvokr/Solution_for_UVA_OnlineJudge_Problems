#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T> T power ( T a, T p ) { long long res = 1, x = a; while ( p ) { if ( p & 1 ) res = res * x; x = x * x; p >>= 1; } return res;}

int main()
{
    char in[ 15 ];
    int T, len, num;
    long long sum;
    bool flag;
    scanf("%d", &T); getchar();
    while( T-- )
    {
        gets( in ); flag = false;
        len = strlen( in );
        num = atoi( in );
        sum = 0ll;
        for(int i = 0; i < 31 && !flag && sum < num; i++)
        {
            sum = 0ll;
            for(int j = 0; j < len; j++) sum += power(in[ j ] - 48, i);
            flag = sum == num ? true : false;
        }
        puts(flag ? "Armstrong" : "Not Armstrong");
    }
    return 0;
}
