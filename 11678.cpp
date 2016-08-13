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
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

int input();

int main()
{
    input();

    return 0;
}
int input()
{
    int tmp, i, m, n, cou, am, bn, maxm, maxn;
    bool arm[100001], arn[100001];
    while(sf("%d%d", &m, &n) != EOF)
    {
        if(n + m == 0) return 0;

        fo(i, 100001) arm[i] = false;
        fo(i, 100001) arn[i] = false;

        maxm = 0; maxn = 0;
        fo(i, m)
        {
            sf("%d", &tmp);
            if(maxm < tmp) maxm = tmp;
            arm[tmp] = true;
        }

        fo(i, n)
        {
            sf("%d", &tmp);
            if(maxn < tmp) maxn = tmp;
            arn[tmp] = true;
        }
        maxm++;
        maxn++;

        am = 0; bn = 0;

        fo(i, maxm) if(arm[i]) am++;
        fo(i, maxn) if(arn[i]) bn++;

        cou = 0;
        if(am < bn)
        {
            fo(i, maxm) if(arm[i] && !arn[i]) cou++;
        }
        else
        {
            fo(i, maxn) if(arn[i] && !arm[i]) cou++;
        }

        pf("%d\n", cou);
    }
}
