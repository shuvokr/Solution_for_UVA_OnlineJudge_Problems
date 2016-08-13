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
#define ll long long

void procage(int n);
int res[25];
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int n, i, tmp, cou;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;

        tmp = n;
        for(i = 0; i < 25; i++) res[i] = 0;
        while(n > 1)
        {
            procage(n--);
        }
        pf("%3d! =", tmp);
        cou = 0;

        for(i = 0; i < 25; i++)
        {
            if(res[i] == 0) break;
            pf(" %2d", res[i]);
            cou++;
            if(cou == 15) break;
        }
        if(cou == 15)
        {
            if(res[i + 1] != 0)
            {
                pf("\n      ");
                for(i = i + 1; i < 25; i++)
                {
                    if(res[i] == 0) break;
                    pf(" %2d", res[i]);
                }
            }
        }
        puts("");
    }
}
void procage(int n)
{
    int k = 0, cou = 0;
    while(n > 1)
    {
        while(n % prime[k] == 0)
        {
            //res.push_back(prime[k]);
            cou++;
            n /= prime[k];
        }

        res[k] += cou;
        cou = 0;

        k++;
        if(k > 24) break;
    }
}
