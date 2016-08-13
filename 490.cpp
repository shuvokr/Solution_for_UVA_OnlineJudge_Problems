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

int main()
{
    input();

    return 0;
}
void input()
{
    char in[101][101];
    int len, i = 0, cou = 0, max = 0, j;

    while(gets(in[i++])) cou++;

    fo(i, cou)
    {
        len = strlen(in[i]);
        if(max < len) max = len;
        for(j = len; j < 100; j++) in[i][j] = ' ';
        in[i][100] = NULL;
    }
    fo(i, max)
    {
        of(j, cou)
        {
            if(in[j][i] != NULL) pf("%c", in[j][i]);
        }
        puts("");
    }
}
