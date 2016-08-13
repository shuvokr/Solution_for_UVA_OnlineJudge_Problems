#include<stdio.h>
int oddsum(int a,int b)
{
    int k,i;
    i=0;
    for(k=a ; k<=b ; k=k+2)
    {
        i=k+i;
    }
    return i;

}
int main()
{
    int T,a,b,r,c=0;
    scanf("%d",&T);
    while(T!=c)
    {
        c++;
        scanf("%d%d",&a,&b);
        if(a<b && a%2!=0 && b%2!=0)
        {
            r=oddsum(a,b);
            printf("Case %d: %d\n",c,r);
        }
        else if(b<a && a%2!=0 && b%2!=0)
        {
            r=oddsum(b,a);
            printf("Case %d: %d\n",c,r);
        }
        else if(a<b && a%2==0 && b%2!=0)
        {
            a=a+1;
            r=oddsum(a,b);
            printf("Case %d: %d\n",c,r);
        }
        else if(a<b && a%2!=0 && b%2==0)
        {
            b=b-1;
            r=oddsum(a,b);
            printf("Case %d: %d\n",c,r);
        }
        else if(a>b && a%2==0 && b%2!=0)
        {
            a=a-1;
            r=oddsum(b,a);
            printf("Case %d: %d\n",c,r);
        }
        else if(a>b && a%2!=0 && b%2==0)
        {
            b=b+1;
            r=oddsum(b,a);
            printf("Case %d: %d\n",c,r);
        }
        else if(a<b && a%2==0 && b%2==0)
        {
            a=a+1;
            b=b-1;
            r=oddsum(a,b);
            printf("Case %d: %d\n",c,r);
        }
        else
        {
            a=a-1;
            b=b+1;
            r=oddsum(b,a);
            printf("Case %d: %d\n",c,r);
        }
    }
    return 0;

}
