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
    char in[101][122], out[101][122];
    int i, n, m, tmp, kag = 0, k = 0, j, len;
    bool ck;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        getchar();
        char rin[1202], rout[1202];
        memset(rin, 0, 1202);
        memset(rout, 0, 1202);

        fo(i, n) gets(in[i]);

        sf("%d", &m);
        getchar();
        fo(i, m) gets(out[i]);

        ck = true;
        if(n == m)
        {
            fo(i, n)
            {
                if(strcmp(in[i], out[i]) != 0)
                {
                    ck = false;
                    break;
                }
            }
            if(ck)
            {
                pf("Run #%d: Accepted\n", ++kag);
                continue;
            }
        }

        k = 0;
        fo(i, n)
        {
            len = strlen(in[i]);
            fo(j, len) if(isdigit(in[i][j])) rin[k++] = in[i][j];
        }
        k = 0;
        fo(i, m)
        {
            len = strlen(out[i]);
            fo(j, len) if(isdigit(out[i][j])) rout[k++] = out[i][j];
        }

        if(strcmp(rin, rout) == 0) pf("Run #%d: Presentation Error\n", ++kag);
        else pf("Run #%d: Wrong Answer\n", ++kag);
    }
}
