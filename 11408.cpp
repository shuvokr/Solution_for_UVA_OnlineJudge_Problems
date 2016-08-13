#include<stdio.h>
int a, b, i, j, tot = 0, answer;
int deprime[ 5000001 ];
int totdeprimes[ 5000001 ];
int main()
{
    for(i = 4; i < 5000001; i += 2) deprime[ i ] = 2;
    for(i = 3; i < 5000001; i += 2)
        if( !deprime[ i ] )
            for(j = 2 * i; j < 5000001; j += i) deprime[ j ] += i;
    for(i = 2; i < 5000001; i++) totdeprimes[ i ] = !deprime[ deprime[ i ] ] ? ++tot : tot;
    while(scanf("%d", &a) && a)
    {
        scanf("%d", &b);
        answer = totdeprimes[ b ] - totdeprimes[ a ];
        answer += totdeprimes[ a ] > totdeprimes[a - 1] ? 1 : 0;
        printf("%d\n", answer);
    }
    return 0;
}
