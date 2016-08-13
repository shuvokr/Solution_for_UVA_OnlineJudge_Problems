/*
        Shuvo
        Problem algo: Basic math
        Problem ID: 10137
        Problem name:  The Trip  :)
*/
//Templet start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define lld long long
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 1000+2

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();

int main()
{
    input();

    return 0;
}
void input()
{
    double in[ maxn ], high, low, tot, avr, dif;
    int n, i;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) break;
        tot = 0.00;
        fo(i, n)
        {
            sf("%lf", &in[ i ]);
            tot += in[ i ];
        }
        avr = tot / n;
        low = high = 0;
        fo(i, n)
        {
            dif = (double) (int)((in[i]-avr)*100.0)/100.0;
            if(in[i] > avr) high += dif;
            if(in[i] < avr) low += -dif;
        }

        if(high > low) pf("$%.2lf\n", high);
        else pf("$%.2lf\n", low);
    }
}
