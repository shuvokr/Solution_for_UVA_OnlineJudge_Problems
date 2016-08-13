#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define sf scanf
#define pf printf

void procage();
char num[33];

int main()
{
    while(gets(num)) procage();
    return 0;
}
void procage()
{
    char ch[33], c;
    memset(ch, 0, 33);
    long long len = strlen(num), nmax, nmin, k, tmp, sk, i;
    sort(num, num + len);
    strcpy(ch, num);

    if(num[0] != '0')
        sscanf(num, "%lld", &nmin);
    else
    {
        for(i = 0; i < len; i++)
        {
            if(num[i] != '0')
            {
                if(i + 1 == len)
                {
                    reverse(num, num + len);
                    sscanf(num, "%lld", &nmin);
                    break;
                }
                else
                {
                    c = num[i];
                    num[i] = '0';
                    num[0] = c;
                    sscanf(num, "%lld", &nmin);
                    break;
                }
            }
            if(num[i] != '0') break;
        }
    }
    reverse(ch, ch + len);
    sscanf(ch, "%lld", &nmax);
    tmp = nmax - nmin;
    sk = tmp / 9;
    pf("%lld - %lld = %lld = 9 * %lld\n", nmax, nmin, tmp, sk);
}
