#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

#define sf scanf
#define pf prntf
#define LLU unsigned long long
int main()
{
    LLU n = 0, sk = 0;
    while(sf("%llu", &n) != EOF)
    {
        if(n == 0) return 0;
        sk = 1;
        while(sk < n)
        {
            sk *= 2;
            sk++;
        }
        if(sk != n) puts("Alice");
        else puts("Bob");
    }
}
