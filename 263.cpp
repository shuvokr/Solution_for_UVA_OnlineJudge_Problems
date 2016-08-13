#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define sf scanf
#define pf printf

void convert(long n);

char allres[1002][11];
int cou;

int main()
{
    long n, res;
    while(sf("%ld", &n) != EOF)
    {
        if(n == 0) return 0;
        memset(allres, 0, sizeof(allres));
        cou = 0;
        pf("Original number was %ld\n", n);
        convert(n);
        puts("");
    }
}
void convert(long n)
{
    char ch[11], tmp[11];
    long len = log10(n) + 1, i, k, num, res, max, min;
    memset(ch, 0, 11);
    k = 0;
    for(i = 0; i < len; i++)
    {
        num = n % 10;
        ch[k++] = num + 48;
        n /= 10;
    }
    sort(ch, ch + len);
    sscanf(ch, "%ld", &min);
    reverse(ch, ch + len);
    sscanf(ch, "%ld", &max);
    res = max - min;
    pf("%ld - %ld = %ld\n", max, min, res);
    if(res == 0)
    {
        pf("0 - 0 = 0\n");
        pf("Chain length %d\n", cou + 2);
    }
    else
    {
        // Save all result
        len = log10(res) + 1;
        num = res;
        for(i = 0; i < len; i++)
        {
            k = num % 10;
            allres[cou][i] = k + 48;
            num /= 10;
        }
        cou++;
        // Cheak previous all result
        bool ck = true;
        for(i = cou - 2; i >= 0; i--)
        {
            if(strcmp(allres[cou-1], allres[i]) == 0)
            {
                ck = false;
                break;
            }
        }
        if(ck)
            convert(res);
        else
            pf("Chain length %d\n", cou);
    }
}
