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
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long

struct data
{
    int val;
}res[200];

int main()
{
    char ch[100000];
    int len, i, max;
    while(gets(ch))
    {
        for(i = 0; i < 200; i++) res[i].val = 0;
        len = strlen(ch);
        sort(ch, ch + len);
        for(i = 0; i < len; i++)
        {
            if(isalpha(ch[i]))
            {
                res[ch[i]].val++;
            }
        }
        max = 0;
        for(i = 0; i < 200; i++)
        {
            if(res[i].val != 0) if(max < res[i].val) max = res[i].val;
        }
        for(i = 0; i < 200; i++)
        {
            if(res[i].val == max) pf("%c", i);
        }
        pf(" %d\n", max);
    }
}
