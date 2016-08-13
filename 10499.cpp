#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    LLD n = 0;
    LLU res = 0;
    while(sf("%lld", &n) != EOF)
    {
        if(n < 0) return 0;
        if(n == 1) puts("0%");
        else
        {
            res = n * 25;
            pf("%llu%%\n", res);
        }
    }
}
