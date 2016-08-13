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

long long procage(ll n);
void isprime();
void save();

long long res[1000001];
long long prime[168];
const int N = 1000;
bool ck[1001];

int main()
{
    isprime();
    save();

    int n;
    while(sf("%d", &n) != EOF)
        pf("%lld\n", res[n]);

    return 0;
}

void save()
{
    long long i;
    res[1] = 0;
    for(i = 2; i < 1000001; i++)
        res[i] = res[i - 1] + procage(i);
}
long long procage(ll n)
{
    ll cou = 0, i = 0;
    while(n > 1)
    {
        while(n % prime[i] == 0)
        {
            cou++;
            n /= prime[i];
        }
        i++;
        if(i == 168) break;
    }
    if(n > 1) cou++;
    return cou;
}
void isprime()
{
    int i, j, k, sq = sqrt(N);
    for(i = 2; i < N; i++) ck[i] = true;

    for(i = 2; i <= sq; i++)
        for(j = i * i; j < N; j += i)
            if(ck[j]) ck[j] = false;

    k = 0; int cou = 0;
    prime[k++] = 2;
    for(i = 3; i < N; i += 2)
        if(ck[i]) prime[k++] = i, cou++;
    //pf("%d\n", cou);
}
