#include<stdio.h>
int main()
{
    int T,a,b,c,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
          scanf("%d%d%d",&a,&b,&c);
    if(a>=1000 && a<=10000 && b>=1000 && b<=10000 && c>=1000 && c<=10000)
    {
        if(a>b && a<c)
        {
            printf("Case %d: %d\n",i,a);
        }
        else if(a<b && a>c)
        {
            printf("Case %d: %d\n",i,a);
        }
        else if(b<a && b>c)
        {
            printf("Case %d: %d\n",i,b);
        }
        else if(b>a && b<c)
        {
            printf("Case %d: %d\n",i,b);
        }
        else
        {
            printf("Case %d: %d\n",i,c);
        }


    }

    }
    return 0;
}
