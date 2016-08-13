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
#define LLu unsigned long long
#define Lu unsigned long
#define LLd long long
#define Ld long

int main()
{
    int n = 0, i = 0;
    LLd m;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        vector <long long> v;
        for(i = 0; i < n; i++)
        {
            sf("%lld", &m);
            v.push_back(m);
        }
        sort(v.begin(), v.end());
        pf("%lld", v[0]);
        for(i = 1; i < n; i++)
            pf(" %lld", v[i]);
        pf("\n");
    }
}
