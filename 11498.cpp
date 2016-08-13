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

int main()
{
    int n = 0, m = 0, sk = 0, x = 0, y = 0, i = 0;
    while(1)
    {
        scanf("%d", &sk);
        if(sk == 0) return 0;

        scanf("%d%d", &n, &m);

        for(i = 0; i < sk; i++)
        {
            scanf("%d%d", &x, &y);
            if(n == x || m == y) puts("divisa");
            else if(x > n)
            {
                if(y > m) puts("NE");
                else puts("SE");
            }
            else
            {
                if(y > m) puts("NO");
                else puts("SO");
            }
        }
    }
}
