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

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int n, T, i, len, res;
    char p[2002];
    sf("%d", &T);

    while(T--)
    {
        res = 0;
        sf("%d%s", &n, p);
        len = strlen(p);

        fo(i, len) res = (res * 10 + (p[i] - 48)) % n;

        pf("%d\n", res);
    }
}
