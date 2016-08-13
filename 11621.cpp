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
#define lld long long
#define ld long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

int input();
void save_res();

vector <long long> c23;

int main()
{
    input();

    return 0;
}
int input()
{
    save_res();
    lld m, low, high, mid, res;

    while(sf("%lli", &m) != EOF)
    {
        if(m == 0) return 0;
        low = 0; high = c23.size() - 1; mid = (low + high) / 2;
        while(low < high)
        {
            if(c23[mid] < m) low = mid + 1, mid = (low + high) / 2;
            else if (c23[mid] > m) high = mid - 1, mid = (low + high) / 2;
            else break;
        }

        if(c23[mid] >= m) pf("%lld\n", c23[mid]);
        else pf("%lli\n", c23[mid + 1]);
    }
}
void save_res()
{
    lld res = 2147483647, i, j, tmp;
    fo(i, 31)
        fo(j, 20)
        {
            tmp = pow(2 , i) * pow(3, j);
            c23.push_back(tmp);
        }
    sort(c23.begin(), c23.end());
}
