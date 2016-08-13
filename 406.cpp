#include<stdio.h>
#include<math.h>

int isprime(int n)
{
    int i,lim;
    lim=sqrt(n);
    for(i=2; i<=lim; i++)
    {
        if((n%i)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n=0,c=0;
    while(scanf("%d%d",&n,&c)==2)
    {
        printf("%d %d:",n,c);
        int a[100000],r=0,i=0,k=2,p=1,s=0,j=0,m=0,pp=0;
        a[1]=1;
        for(i=2; i<=n; i++)
        {
            r=isprime(i);
            if(r!=0)
            {
                a[k]=i;
                k++;
                p++;
            }
        }
        pp=p;
        if(p%2==0)
        {
            c=c*2;
            if(p>c)
            {
                p=(p-c);
                m=p/2;
                for(j=m+1; j<=(p+c)-m; j++)
                {
                    printf(" %d",a[j]);
                }
                printf("\n\n");

            }
            else
            {
                for(j=1; j<=pp; j++)
                {
                    printf(" %d",a[j]);
                }
                printf("\n\n");
            }
        }
        else
        {
            c=(c*2)-1;
            if(p>c)
            {
                m=c/2;
                for(j=(pp/2)-(m-1); j<=(pp/2)+(m+1); j++)
                {
                    if(a[j]>0)
                    printf(" %d",a[j]);
                }
                printf("\n\n");

            }
            else
            {
                for(j=1; j<=pp; j++)
                {
                    printf(" %d",a[j]);
                }
                printf("\n\n");
            }
        }
    }
    return 0;
}

