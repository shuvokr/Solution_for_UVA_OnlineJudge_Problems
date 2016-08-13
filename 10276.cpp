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
#define foo(i, n) for(i = 1; i <= n; i++)
#define fa(i, n) for(i = 0; i < n - 1; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long res[] = {1, 3, 7, 11, 17, 23, 31, 39, 49, 59, 71, 83, 97, 111, 127, 143, 161, 179, 199, 219, 241, 263, 287, 311, 337, 363, 391, 419, 449, 479, 511, 543, 577, 611, 647, 683, 721, 759, 799, 839, 881, 923, 967, 1011, 1057, 1103, 1151, 1199, 1249, 1299};
    long T, stick;
    scanf("%ld", &T);
    while(T--)
    {
        scanf("%ld", &stick);
        stick--;
        printf("%ld\n", res[stick]);
    }
    return 0;
}
/*void input();
void save_sqr();
void save_res(int boll);

int res[51], top[51], b_val = 0;
bool isSquare[2600];

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    memset(res, 0, sizeof res), memset(top, 0,sizeof top);

    save_sqr();
    input();
}
void save_sqr()
{
    int i, tmp = 0;

    fo(i, 2600) isSquare[i] = false;

    i = 1;
    while(tmp < 2600)
    {
        tmp = i * i;
        isSquare[tmp] = true;
        i++;
    }
}
void input()
{
    save_res(1);

    int T, stick, kag = 0;
    sf("%d", &T);

    while(T--)
    {
        sf("%d", &stick);
        if(stick > 50)
        {
            pf("Case %d: ", ++kag);
            puts("0"); continue;
        }
        pf("Case %d: %d\n", ++kag, res[stick]);
    }
}
void save_res(int boll)
{
    if(b_val > 50) return;

    int i;
    bool ck = true;

    foo(i, b_val)
        if(isSquare[boll + top[i]])
        {
            res[b_val]++, top[i] = boll; ck = false;
        }

    if(ck) top[++b_val] = boll, res[b_val] = res[b_val - 1] + 1;
    save_res(boll + 1);
}

*/
