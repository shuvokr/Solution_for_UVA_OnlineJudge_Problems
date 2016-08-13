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

void input();

int main()
{
    input();

    return 0;
}
void input()
{
    int T, zero, one, i, len, k;
    char bosta[18];
    sf("%d", &T);

    while(T--)
    {
        k = 0;
        memset(bosta, 0, 18);
        sf("%d%d", &zero, & one);
        zero -= one;

        while(zero--) bosta[k++] = '0';
        while(one--) bosta[k++] = '1';

        do
        {
            puts(bosta);
        }while(next_permutation(bosta, bosta + k));

        if(T) puts("");
    }
}
