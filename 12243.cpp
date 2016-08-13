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
#define fa(i, n) for(i = 1; i < n; i++)
#define oof(i, n) for(i = n - 1; i >= 0; i--)
#define max 100000000000000+1

int input();

int main()
{
    input();

    return 0;
}
int input()
{
    char in[1000000], take, chake;
    int i, len;
    bool ck;
    while(gets(in))
    {
        if(in[0] == '*') return 0;

        take = in[0];
        if(islower(take)) take = toupper(take);
        len = strlen(in);
        ck = true;
        fa(i, len)
        {
            if(isspace(in[i]) && i + 1 < len)
            {
                chake = in[i + 1];
                if(islower(chake)) chake = toupper(chake);
                if(take != chake)
                {
                    ck = false; break;
                }
            }
        }
        if(ck) puts("Y");
        else puts("N");
    }
}
