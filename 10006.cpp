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
#define ll long long
#define l long

int main()
{
    bool res[65000];
    for(int i = 2; i < 65000; i++) res[i] = false;
    res[561] = true;
    res[1105] = true;
    res[1729] = true;
    res[2465] = true;
    res[2821] = true;
    res[6601] = true;
    res[8911] = true;
    res[10585] = true;
    res[15841] = true;
    res[29341] = true;
    res[41041] = true;
    res[46657] = true;
    res[52633] = true;
    res[62745] = true;
    res[63973] = true;

    int n;
    while(scanf("%d", &n) && n != 0)
        if(res[n])
            printf("The number %d is a Carmichael number.\n", n);
        else printf("%d is normal.\n", n);
    return 0;
}

/*void isprime();
bool BigMod(ll n, ll nm, ll mod);

bool ck[65000], Carmichael_number[65000];
const int N = 65000;

int main()
{
    for(ll i = 2; i < N; i++) Carmichael_number[i] = false;

    isprime();

    ll n;
    while(sf("%lld", &n) != 0)
    {
        if(n == 0) return 0;
        if(Carmichael_number[n])
            pf("The number %lld is a Carmichael number.\n", n);
        else pf("%lld is normal.\n", n);
    }
}

void isprime()
{
    ll cou, sqrtN = sqrt(N), i, j;

    for(i = 2; i < N; i++) ck[i] = true;

    for(i = 2; i <= sqrtN; i++)
        for(j = i * i; j <= N; j += i)
            if(ck[j]) ck[j] = false;
    // in above i find all prime

    // in this part i just calculat Carmichael_number for without prime
    // and i got 11 Carmichael_number.
    for(i = 2; i < N; i++)
    {
        if(!ck[i])
        {
            cou = 0;
            bool res;
            for(j = 2; j < i; j++)
            {
                res = BigMod(j, i, i);
                if(res) break;
                cou++;
                if(cou == i - 2) Carmichael_number[i] = true; //pf("%d ", i);
            }
        }
    }
    //**************************************************
}
bool BigMod(ll nm, ll n, ll mod)
{
    ll res = 1, num = nm;
    while(n > 0)
    {
        if(n % 2 != 0)
        {
            res = (res * num) % mod;
        }
        n = n >> 1;
        num = ((num % mod) * (num % mod)) % mod;
    }

    if(nm == res) return false;
    else return true;
}
*/
