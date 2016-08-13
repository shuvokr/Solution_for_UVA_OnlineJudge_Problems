#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

#define sf scanf
#define pf printf
#define LL unsigned long long
#define L long long

int main()
{
    int value = 500002;
    LL array[500002];
    array[0] = 0;
    for(int i = 1; i < value; i++)
        array[i] = array[i-1] + i;

    int n;
    while(sf("%d", &n) != EOF)
    {
        if(n == 0 || n == 1) puts("1");
        else{

            n = n / 2 + 1;
            pf("%llu\n" , array[n]);
        }
    }
    return 0;
}
