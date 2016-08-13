#include<stdio.h>
int main()
{
    int s,a,b,i,n,k,j,kk;
    while(scanf("%d%d",&a,&b)==2)
    {
        kk=-1;
        if(a>b)
        {
            n=(a-b)+b;
            s=b;
        }
        else
        {
            n=(b-a)+a;
            s=a;
        }
        for(i=s;i<=n;i++)
        {
            j=1;
            k=i;
            while(k!=1)
            {
            if(k%2==0)
            {
                k=k/2;
            }
            else
            {
                k=3*k+1;
            }
            j++;
            }
            if(kk<j)
            {
                kk = j;
            }
        }
        printf("%d %d %d\n",a,b,kk);
    }
    return 0;
}

