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
#define fo(i, n) for(i = 2; i < n; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)

void save();
void input();

long long catalen[20];

int main()
{
    catalen[0] = 1;
    catalen[1] = 1;

    save();
    input();

    return 0;
}
void save()
{
    int i, n, a, b;
    fo(i, 20)
    {
        n = i - 1;
        a = 2 * ((2 * n) + 1);
        b = n + 2;
        catalen[i] = (catalen[i - 1] * a) / b;
    }
}
void input()
{
    long long in;
    int i;
    bool ck;
    while(sf("%lld", &in) != EOF)
    {
        ck = false;
        for(i = 1; i < 20; i++)
        {
            if(catalen[i] == in)
            {
                pf("%d\n", i);
                ck = true;
                break;
            }
        }
        if(!ck) puts("0");
    }
}
