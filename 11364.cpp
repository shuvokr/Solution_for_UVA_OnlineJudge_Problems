#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,d,r,min=100,max=-1;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&d);
            if(d>max)
            {
                max=d;
            }
            if(d<min)
            {
                min=d;
            }
        }
        r=max-min;
        r=r*2;
        printf("%d\n",r);
    }
    return 0;
}
