#include <iostream>
#include <cstdio>
#include<map>
#include<cstring>
#include <algorithm>
using namespace std;
int main ()
{
    map<int,char>M;
    int n, i, j, l, d, a[ 100 ];
    char s[ 100 ];
    scanf("%d", &n); getchar();
    for(i = 0; i < n; i++)
    {
        gets( s );
        l = strlen( s );
        for(j = 0; j < l; j++)
        {
            d = s[ j ];
            if(d > 64 && d < 91) d = d * 2;
            else d = 131 + 2 * (s[ j ] - 97);
            M[ d ] = s[ j ];
            a[ j ] = d;
        }
        sort(a, a + l);
        do
        {
            for(j = 0; j < l; j++) cout << M[ a[ j ] ];
            puts("");
        } while ( next_permutation (a, a + l));
    }
    return 0;
}
