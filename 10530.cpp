#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    int n, high = 11, low = 0;
    char c[15];
    while(sf("%d", &n) != 0)
    {
        if(n == 0) return 0;
        getchar();
        memset(c, 0, sizeof(c));
        gets(c);

        if(strcmp(c, "too high") == 0)
            if(high > n)
                high = n;
        if(strcmp(c, "too low") == 0)
            if(low < n)
                low = n;

        if(strcmp(c, "right on") == 0)
            if(n > low && n < high)
            {
                //pf("%d %d\n", high, low);
                puts("Stan may be honest");
                high = 11;
                low = 0;
            }
            else
            {
                //pf("%d %d\n", high, low);
                puts("Stan is dishonest");
                high = 11;
                low = 0;
            }
    }
}
