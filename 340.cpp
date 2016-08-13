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
#define oof(i, n) for(i = n - 1; i >= 0; i--)

int input();

int main()
{
    input();

    return 0;
}
int input()
{
    int n, i, sm, nm, j, kag = 0;
    bool ck1 = false, ck2 = false;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        int mein[1002];

        fo(i, n) sf("%d", mein + i);
        pf("Game %d:\n", ++kag);

        while(1)
        {
            int tmp[1002], sk[1002];
            ck1 = true;
            sm = 0;
            fo(i , n)
            {
                sf("%d", &tmp[i]);
                if(tmp[i] != 0) ck1 = false;
                if(tmp[i] == mein[i]) sm++;
            }

            if(ck1) break;
            nm = 0;
            fo(i, n) sk[i] = mein[i];

            fo(i, n)
                fo(j, n)
                    if(tmp[i] == sk[j]) nm++, tmp[i] = -1, sk[j] = -2;

            pf("    (%d,%d)\n", sm, nm - sm);
        }
    }
}
