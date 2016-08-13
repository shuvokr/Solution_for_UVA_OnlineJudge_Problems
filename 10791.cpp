/*
                                            Shuvo
                                            12542
*/
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
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf


    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int main()
    {
        int n;
        int t = 1;
        while(~scanf("%d", &n) && n)
        {
            printf("Case %d: ", t++);
            if(n == 1)
            {
                puts("2");
                continue;
            }
            if(n == 2147483647)
            {
                puts("2147483648");
                continue;
            }
            int m = sqrt((float)n);
            int ans = 0;
            int tmpn = n;
            int count = 0;
            for(int i = 2; i <= m; i++)
            {
                if(tmpn % i == 0)
                {
                    count++;
                    int tmp = 1;
                    while(!(tmpn % i))
                    {
                        tmp *= i;
                        tmpn /= i;
                    }
                    ans += tmp;
                }
            }
            if(tmpn == n) printf("%d\n", n + 1);
            else
            {
                if(tmpn != 1) ans += tmpn;
                else if(count == 1) ans++;
                printf("%d\n", ans);
            }
        }
        return 0;
    }
