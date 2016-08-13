#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    int n = 0, res = 0;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        res = n % 5;
        if(res == 0) puts("0.00");
        else if(res == 1 || res == 4) puts("0.40");
        else puts("0.20");
    }
}
