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
void back_tracking(int index, int tot);

int in[13], res[13], k;
bool ck[13];

int main()
{
    input();

    return 0;
}
int input()
{
    int i;
    bool sk = false;
    fo(i, 13) ck[i] = true;
    while(sf("%d", &k) != EOF)
    {
        if(k == 0) return 0;

        if(sk) puts("");
        sk = true;

        memset(in, 0, 13);
        fo(i, k) sf("%d", in + i);

        back_tracking(0, 0);
    }
}
void back_tracking(int index, int tot)
{
    int i;
    if(tot == 6)
    {
        fo(i, 5) pf("%d ", res[i]);
        pf("%d\n", res[5]); return;
    }

    for(i = index; i < k; i++)
    {
        if(ck[i])
        {
            ck[i] = false;
            res[tot] = in[i];
            back_tracking(i + 1, tot + 1);
            ck[i] = true;
        }
    }
}
