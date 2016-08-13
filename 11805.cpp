#include<stdio.h>
int main()
{
    int T,n,k,p,r,a=1;
    scanf("%d",&T);
    while(a<=T)
    {
        scanf("%d%d%d",&n,&k,&p);
        if(k<=n)
        {
            r=k+p;
            if(r<=n)
            {
                printf("Case %d: %d\n",a,r);
            }
            else
            {
                while(r>n)
                {
                    r=r-n;
                }
                printf("Case %d: %d\n",a,r);
            }
            a++;
        }
    }
    return 0;
}
