#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    int p, budg, H, W, rent, i, j, k, min;
    long long ck;
    while(sf("%d%d%d%d", &p, &budg, &H, &W) == 4)
    {
        min = 5000000;

        for(i = 0; i < H; i++)
        {
            sf("%d", &rent);
            ck = p * rent;
            if(ck <= budg)
            {
                for(j = 0; j < W; j++)
                {
                    sf("%d", &k);
                    if(k >= p && min > ck)
                        min = ck;
                }
            }
            else
            {
                for(j = 0; j < W; j++)
                    sf("%d", &k);
            }
        }
        if(min <= budg) pf("%d\n", min);
        else puts("stay home");
    }
    return 0;
}
/*#include <stdio.h>
#include <limits.h>

int main()
{
    int participants,budget,hotels,weeks;
    while(scanf("%d %d %d %d",&participants,&budget,&hotels,&weeks)==4)
    {
        int i,min=INT_MAX;
        for(i=0;i<hotels;i++)
        {
            int price=0,places=0,j=0;
            scanf("%d",&price);
            int cost=price*participants;
            if(cost<=budget)
            {
                for(j=0;j<weeks;j++)
                {
                    scanf("%d",&places);
                    if(places>=participants&& min>cost)
                        min=cost;
                }
            }
            else
            {
                for(j=0;j<weeks;j++)
                {
                    scanf("%d",&places);
                }
            }
        }
        if(min==INT_MAX)
        {
            printf("stay home\n");
        }
        else
        {
            printf("%d\n",min);
        }
     }
    return 0;
}
*/
