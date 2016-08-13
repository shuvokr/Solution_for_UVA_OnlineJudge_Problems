#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define foo(i, n) for(i = 1; i <= n; i++)
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int Y;
    while(sf("%d", &Y) != EOF)
    {
        Y--;
        int Pope;
        sf("%d", &Pope);
        int in[Pope], i, max = 0, frest, last, j, count;
        fo(i, Pope) sf("%d", &in[i]);

        fo(i, Pope)
        {
            j = i, count = 0;
            while(in[j] <= in[i] + Y) j++, count++;
            if(count > max) max = count, frest = in[i], last = in[j - 1];
        }
        pf("%d %d %d\n", max, frest, last);
    }
}
