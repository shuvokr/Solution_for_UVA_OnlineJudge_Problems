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

int input();
void numtoint(int len);

char in[1000000 + 10], in_len[1000000 + 10];

int main()
{
    input();

    return 0;
}
int input()
{
    int n, len, tmp, i, cou;
    while(gets(in))
    {
        if(in[0] == 'E') return 0;

        len = strlen(in);
        cou = 1;
        numtoint(len);
        while(strcmp(in, in_len) != 0)
        {
            cou++;
            strcpy(in, in_len);
            len = strlen(in);
            numtoint(len);
        }
        pf("%d\n", cou);
    }
}
void numtoint(int len)
{
    int i = 0, tmp;
    memset(in_len, 0, 1000010);
    while(len != 0)
    {
        tmp = len % 10;
        len /= 10;
        in_len[i++] = tmp + 48;
    }
}
