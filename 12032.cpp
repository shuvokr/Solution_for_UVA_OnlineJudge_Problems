#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    long T, n, kag = 0, max = -1, dif = 0, i, tmp;
    vector <long> in;
    sf("%ld", &T);
    while(T--)
    {
        sf("%ld", &n);
        in.clear();
        max = -1;
        in.push_back(0);
        fo(i, n)
        {
            sf("%ld", &tmp), in.push_back(tmp), dif = in[i] - in[i - 1];
            if(dif > max) max = dif;
        }

        long result = max;
        fo(i, n)
        {
            dif = in[i] - in[i - 1];
            if(dif == max) max--;
            else if(dif > max) {result++; break;}
        }

        pf("Case %ld: %ld\n", ++kag, result);
    }
}
