/*
    Shuvo
    Problem no: 12457. Problem name: Tennis contest
*/
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
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, -1, sizeof(n))

int input();
double dp(int win, int match);
double dp_array[51][51], p;
int n, tot;

int main()
{
    input();

    return 0;
}
int input()
{
    int i, j, tmp, T;
    double res;
    sf("%d", &T);
    while(T--)
    {
        sf("%d%lf", &n, &p);
        fo(i, 51) fo(j, 51) dp_array[i][j] = -1.0;
        res = dp(0, 0);
        pf("%.2lf\n", res);
    }
}
double dp(int win, int match)
{
    if(win == n) return 1.0;
    else if(match == 2 * n - 1) return 0.0;
    else if(dp_array[match][win] != -1.0) return dp_array[match][win];
    else
    {
        dp_array[match][win] = (p * dp(win + 1, match + 1)) + ((1 - p) * dp(win, match + 1));
        return dp_array[match][win];
    }

}
