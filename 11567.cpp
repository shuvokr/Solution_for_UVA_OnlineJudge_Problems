#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    long long n = 0, temp1 = 0, temp2 = 0, temp3 = 0, res = 0, count1 = 0, count2 = 0, co = 0, cou = 0;

    while(sf("%lld", &n) != EOF)
    {
        res = 0;

        while(n >= 1)
        {
            res++;
            if(n % 2 != 0)
            {
                co = n - 1;
                co = n / 2;
                cou = n + 1;
                cou = n / 2;

                if(co % 2 == 0 || co == 1)
                    n = n - 1;
                else n = n + 1;
            }
            else
                n = n / 2;
        }

        pf("%lld\n", res);
    }
    return 0;
}
