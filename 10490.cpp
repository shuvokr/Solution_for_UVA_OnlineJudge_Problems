#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
int main()
{
    int n;
    while(sf("%d",&n) != EOF)
    {
        if(n == 0) return 0;
        if(n == 2) puts("Perfect: 6!");
        else if(n == 3) puts("Perfect: 28!");
        else if(n == 5) puts("Perfect: 496!");
        else if(n == 7) puts("Perfect: 8128!");
        else if(n == 13) puts("Perfect: 33550336!");
        else if(n == 17) puts("Perfect: 8589869056!");
        else if(n == 19) puts("Perfect: 137438691328!");
        else if(n == 31) puts("Perfect: 2305843008139952128!");
        else if(n == 11 || n == 23 || n == 29) puts("Given number is prime. But, NO perfect number is available.");
        else puts("Given number is NOT prime! NO perfect number is available.");
    }
    return 0;
}
