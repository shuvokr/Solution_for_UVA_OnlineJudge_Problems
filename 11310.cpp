/*
        Shuvo
        Problem algo: Botom up DP
        Problem ID: 11310
        Problem name: Delivery Debacle
*/
#include <stdio.h>

using namespace std;

int main()
{
    long long save[ 41 ], i;
    save[ 1 ] = 1; save[ 2 ] = 5;
    for(i = 3; i < 41; i++)
    {
        save[ i ] = (save[ i - 1 ] * 2) + (save[ i - 2 ] * 2);
        if(i % 2 == 0) save[ i ]++;
        else save[ i ]--;
    }
    int n, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld\n", save[ n ]);
    }
    return 0;
}
