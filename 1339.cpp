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

int main()
{
    bool ck;
    char x[101] = {0}, y[101] = {0};
    int len, i, ar1[26] = {0}, ar2[26] {0};

    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));

    while(gets(x))
    {
        gets(y);
        for(i = 0; i < 26; i++) ar1[i] = ar2[i] = 0;
        len = strlen(x);
        for(i = 0; i < len; i++)
        {
            ar1[x[i] - 65]++;
            ar2[y[i] - 65]++;
        }
        ck = true;
        sort(ar1, ar1 + sizeof(ar1) / sizeof(ar1[0]));
        sort(ar2, ar2 + sizeof(ar2) / sizeof(ar2[0]));
        for(i = 0; i < 26; i++)
            if(ar1[i] != ar2[i])
            {
                ck = false; break;
            }
        if(ck) puts("YES");
        else puts("NO");
    }
    return 0;
}

