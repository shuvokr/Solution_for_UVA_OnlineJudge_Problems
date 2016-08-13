#include<stdio.h>

int main()
{
    int a[99999];
    int t,i,b,m,j,c=1;
    scanf("%d",&t);
    while(t>0)
    {
    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<b-1;j++)
    {
        for(i=0;i<b-1;i++)
        {
            if(a[i]>a[i+1])
            {
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
            }
        }
    }
    b=(b-1)/2;
    printf("Case %d: %d\n",c,a[b]);
    c++;
    t--;
    }
    return 0;
}

