#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int N = 1000000;
bool *status = new bool[1000000], *res = new bool[1000000];

int main()
{
    int sqrtn, i, j;
    for(i = 0; i <= N; i++) status[i] = true;
    for(i = 4; i <= N; i += 2) status[i] = false;
    status[2] = true;

    for(i = 3; i <= 1000; i += 2)
        if(status[i])
            for(j = i * i; j <= N; j += i)
                status[j] = false;

    for(i = 1; i <= N; i++) res[i] = false;

    for(i = 3; i <= N; i += 2)
        if(status[i]) // If i is a prime
        {
            int sk = i;
            int sum = 0;
            int len = (int)(log10(sk));
            for(int k = 0; k <= len; k++)
            {
                sum += sk % 10;
                sk = sk / 10;
            }
            if(status[sum]) res[i] = true;
        }

    res[1] = false;
    res[2] = true;
    int m, n, T, ans[ 1000001 ], cou = 1;
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;

    for(i = 3; i <= 1000000; i++)
    {
        if(res[i])
        {
            cou++;
            ans[i] = cou;
        }
        else ans[i] = cou;
    }

    sf("%d", &T);
    while(T--)
    {
        sf("%d %d", &m, &n);
        cou = ans[ n ] - ans[m - 1];
        pf("%d\n", cou);
    }
    return 0;
}
