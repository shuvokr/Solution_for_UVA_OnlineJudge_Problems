#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    unsigned long long T, a[4], max;
    sf("%llu", &T);
    while(T--)
    {
        max = 0;
        sf("%llu%llu%llu%llu", &a[0], &a[1], &a[2], &a[3]);
        if(max < a[0]) max = a[0];
        if(max < a[1]) max = a[1];
        if(max < a[2]) max = a[2];
        if(max < a[3]) max = a[3];
        sort(a, a+4);
        if(a[0] + a[1] + a[2] + a[3] < 2 * max) puts("banana");
        else if(a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) puts("square");
        else if(a[0] == a[1] && a[2] == a[3]) puts("rectangle");
        else puts("quadrangle");
    }
    return 0;
}
