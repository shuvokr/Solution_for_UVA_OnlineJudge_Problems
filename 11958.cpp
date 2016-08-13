/*
                                    Shuvo
                                    11958
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    int T, z = 0, a , b , val, temp, n, H, M, count, max;
    sf ("%d", &T);
    while(T--)
    {
        max = 9999999;
        sf ("%d%d:%d", &n, &H, &M);
        for(int i = 0; i < n; i++)
        {
                sf ("%d:%d%d", &a, &b, &val);
                if(M > b)
                {
                    temp = H + 1;
                    if(temp == 24) temp = 0;
                    count = 1;
                }
                else
                {
                    temp = H;
                    count = 0;
                }
                while(temp != a)
                {
                    count++;
                    temp++;
                    if(temp == 24) temp = 0;
                }

            count *= 60;
            temp = count + b + val - M;

            if(max > temp) max = temp;

        }
        pf ("Case %d: %d\n", ++z, max);
    }
    return 0;
}
