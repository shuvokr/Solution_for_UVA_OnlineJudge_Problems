#include<stdio.h>
int main()
{
    int a[20001] = {0},i,l,r,pv,h,max,f;
    max=0;
    while(~scanf("%d%d%d",&l,&h,&r))
    {
        for(i=l;i<r;i++)
        {
            a[i]=a[i]<h?h:a[i];
            max=r>max?r:max;
        }
    }
    max+=2;
    for(i=0,pv=0,f=1;i<max;i++)
    {
        if(pv!=a[i])
        {
            pv=a[i];
            ( f )?printf("%d %d",i,pv),f=0:printf(" %d %d",i, pv);
        }
    }
    puts("");


 return 0;
}

