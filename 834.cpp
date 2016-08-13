#include<stdio.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        int a[100000],i=1,s;
        if(m%n!=0)
        {

        while(n!=0)
        {
            a[i]=m/n;
            s=n;
            n=m%n;
            m=s;
            i++;
        }
        int j=2;
        printf("[%d",a[1]);
        if(a[2]!=0)
        {
            printf(";");
        }
        i=i-1;
        for(j=2; j<i; j++)
        {
            printf("%d,",a[j]);
        }
        if(a[i]!=0)
        {
            printf("%d",a[i]);
        }
        printf("]\n");

        }
        else
        {
            int r;
            r=m/n;
            printf("[%d]\n",r);
        }
    }
    return 0;
}
