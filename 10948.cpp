#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

#define sf scanf
#define pf printf
#define LL unsigned long long
#define L long long
#define maxn 1000000+2

int N = 1000000;
int status[1000000];
int main()
{
    #ifdef monkey
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    for(int i = 1; i < 101; i++) pf("%d\n", i);

    int i, j;
    for( i = 2; i <= N; i++ )
    {
        if( status[i] == 0 )
        {
            for( j = 2 * i; j <= N; j += i )
                status[j] = 1;
        }
    }


    int n = 0, temp = 0, sk = 0;
    bool ck = true;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        sk = n / 2 + 1;
        ck = true;
        for( i = 2; i < sk; i++ )
        {
            if(status[i] == 0)
            {
                temp = n - i;
                if(status[temp] == 0)
                {
                    pf("%d:\n%d+%d\n", n, i, temp);
                    ck = false;
                    break;
                }
            }
        }

        if(ck)
        {
            pf("%d:\n", n);
            puts("NO WAY!");
        }
    }
}
