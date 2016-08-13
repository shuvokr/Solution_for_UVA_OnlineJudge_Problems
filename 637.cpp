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
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define lld long long
#define ld long
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

int input();
void print_res(int first, int second, int n, int cou);

int main()
{
    input();

    return 0;
}
int input()
{
    int i, n, first, second, cou, ck;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;

        ck = 0;
        while(ck < n) ck += 4;
        first = 1;
        second = ck;
        cou = ck / 4;
        pf("Printing order for %d pages:\n", n);
        print_res(first, second, n, cou);
    }
}
void print_res(int first, int second, int n, int cou)
{
    int i;
    fo(i, cou)
    {
        if(second <= n)
        {
            pf("Sheet %d, front: %d, %d\n", i, second, first), second--, first++;
            if(first > n) break;
            pf("Sheet %d, back : %d, %d\n", i, first, second), first++, second--;
        }
        else
        {
            pf("Sheet %d, front: Blank, %d\n", i, first), second--, first++;
            if(first > n) break;
            if(second <= n) pf("Sheet %d, back : %d, %d\n", i, first, second), first++, second--;
            else pf("Sheet %d, back : %d, Blank\n", i, first), second--, first++;
        }
    }
}
