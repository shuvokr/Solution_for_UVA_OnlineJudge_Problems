#include <stdio.h>
#include <string.h>

int DP(int val);
int save[ 10 ], mamo[ 100010 ], n;

int main()
{
    int i, tmp, c = 0;
    save[ 0 ] = save[ 1 ] = 1;
    for(i = 0; i < 100001; i++) mamo[ i ] = 1000000;
    for(i = 2; i < 10; i++) save[ i ] = i * save[i - 1];
    for(i = 1; i < 100001; i++) tmp = DP(i);
    while( ~scanf("%d", &n) ) printf("%d\n", mamo[ n ]);
    return 0;
}
int DP(int val)
{
    if(val == 0) return 0;
    int &ret = mamo[ val ], i;
    if(ret < 1000000) return ret;

    for(i = 0; save[ i ] <= val; i++)
    {
        int tmp = 1 + DP(val - save[ i ]);
        ret = ret < tmp ? ret : tmp;
    }
    return ret;
}

