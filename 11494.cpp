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
    int ans1, ans2, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    while(sf("%d%d%d%d",&x1,&y1,&x2,&y2) != EOF)
    {
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) return 0;
        if(x1 == x2 && y1 == y2) puts("0");
        else if(x1 == x2) puts("1");
        else if(y1 == y2) puts("1");
        else
        {
            ans1 = abs(x1 - x2);
            ans2 = abs(y1 - y2);
            if(ans1 == ans2) puts("1");
            else puts("2");
        }
    }
    return 0;
}
