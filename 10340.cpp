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
    char n[100000], x[100000], y = NULL;
    int len = 0, i = 0, j = 0, k = 0, m = 0, lenn = 0, ck = 0;
    while(sf("%s%s",n,x) == 2)
    {
        len = strlen(n);
        lenn = strlen(x);
        if(len > lenn) puts("No");
        else
        {
            for(i = 0; i < len; i++)
            {
                for(j = m; j < lenn; j++)
                {
                    if(n[i] == x[j])
                    {
                        m = j + 1;
                        ck++;
                        break;
                    }
                }
            }
            if(ck == len) puts("Yes");
            else puts("No");
        }
        ck = 0;
        m = 0;
    }
    return 0;
}
