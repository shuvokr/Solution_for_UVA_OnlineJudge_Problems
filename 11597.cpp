#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)

int main()
{
    int n, z = 0;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        n = n / 2;
        pf("Case %d: %d\n", ++z, n);
    }
}
