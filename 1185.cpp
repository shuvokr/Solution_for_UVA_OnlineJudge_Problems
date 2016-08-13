/*
                                    Shuvo
                                     1185
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf

int main()
{
    int t, n, i;
    double temp;
    scanf("%d", &t);
    while( t-- )
    {
        sf("%d", &n);
        if(n == 1) puts("1");
        else
        {
            temp = 0;
            while( n ) temp += log10(n--);
            pf( "%.0lf\n", ceil(temp) );
        }
    }
    return 0;
}

