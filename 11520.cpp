#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    char grid[12][12], c;
    int T, z = 0, n, i, j, k;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);
        pf("Case %d:\n", ++z);

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> grid[i][j];

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == '.')
                    for(k = 65;; k++)
                    {
                        if(grid[i][j-1] != k && grid[i][j+1] != k && grid[i-1][j] != k && grid[i+1][j] != k)
                        {
                            grid[i][j] = k;
                            break;
                        }
                    }
                pf("%c", grid[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
