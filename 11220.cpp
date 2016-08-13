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

void input();
void procage(char in[]);

int pos;

int main()
{
    input();
    return 0;
}
void input()
{
    int len, i, T, k, cag = 0, save;
    char garbeg[10000];
    sf("%d", &T);
    save = T;
    save--;
    gets(garbeg);
    gets(garbeg);

    while(T--)
    {
        char in[10000], tmp[10000];
        if(T < save) puts("");
        pf("Case #%d:\n", ++cag);
        while(gets(in) && in[0])
        {
            if(in[0] == 0) break;
            pos = 0;
            memset(tmp, 0, 10000);
            k = 0;

            len = strlen(in);
            for(i = 0; i < len; i++)
            {
                if(!isspace(in[i]))
                {
                    tmp[k++] = in[i];
                }
                else
                {
                    if(isspace(in[i]) && isalpha(in[i+1])) procage(tmp), memset(tmp, 0, 10000), k = 0;
                }
                if(i == len - 1) procage(tmp);
            }
            puts("");
        }
    }
}
void procage(char in[])
{
    if(isalpha(in[pos])) pf("%c", in[pos++]);
}
