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

void input();
void recursion(int num, int chr);

char in[110][300], rule[300];
int cou, n_cou, sol[10];
int i, n, rl, len, j, k, zero;

int main()
{
    input();

    return 0;
}
void input()
{
    while(sf("%d", &n) != EOF)
    {
        puts("--");
        getchar();
        fo(i, n) gets(in[i]);
        cou = 0;
        sf("%d", &rl);
        getchar();
        fo(i, rl)
        {
            gets(rule);
            len = strlen(rule);
            zero = 0;
            fo(j, len) if(rule[j] == '0') zero++;
            fo(j, n) recursion(0, j);
        }
    }
}
void recursion(int num, int chr)
{
    int l;
    if(num == zero)
    {
        int c = 0;
        fo(l, len)
        {
            if(rule[l] == '#') pf("%s", in[chr]);
            else pf("%d", sol[c++]);
        }
        putchar('\n');
    }
    else
    {
        int ff;
        fo(ff, 10)
        {
            sol[num] = ff;
            recursion(num + 1, chr);
        }
    }
}
