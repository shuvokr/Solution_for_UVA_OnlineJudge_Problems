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
    int sum, max, tmp, i, len;
    char in[100000];
    while(gets(in))
    {
        len = strlen(in);
        max = -1;
        sum = 0;
        fo(i, len)
        {
            if(isupper(in[i]))
            {
                tmp = in[i] - 55;
                if(max < tmp) max = tmp;
                sum += tmp;
            }
            else if(islower(in[i]))
            {
                tmp = in[i] - 61;
                if(max < tmp) max = tmp;
                sum += tmp;
            }
            else if(isdigit(in[i]))
            {
                tmp = in[i] - 48;
                if(max < tmp) max = tmp;
                sum += tmp;
            }
        }

        if(sum == 0)
        {
            puts("2");
            continue;
        }

        bool ck = false;
        for(i = max; i < 62; i++)
        {
            if(sum % i == 0)
            {
                ck = true;
                break;
            }
        }
        if(ck) pf("%d\n", i + 1);
        else puts("such number is impossible!");
    }
}
