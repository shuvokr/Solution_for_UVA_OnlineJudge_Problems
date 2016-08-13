#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LL unsigned long long
#define Lu unsigned long
#define L long long
int main()
{
    Lu T = 0, n = 0, m = 0, sum = 0;
    sf("%lu", &T);
    while(T--)
    {
        vector <int> v;
        sf("%lu", &n);
        for(int i = 0; i < n; i++)
        {
            sf("%lu", &m);
            v.push_back(m);
        }
        sort(v.begin(), v.end());
        for(int i = n - 3; i >= 0; i -= 3)
        {
            sum += v[i];
        }
        pf("%lu\n", sum); sum = 0;
    }
    return 0;
}
