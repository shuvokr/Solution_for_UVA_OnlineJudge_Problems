#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,a6,a7,T,b,c,i,k;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6,&a7);

        if(a5>=a7 && a6>=a7)
        {
            b=a5+a6;
            b=b/2;
        }

        else if(a5>=a6 && a7>=a6)
        {
            b=a5+a7;
            b=b/2;
        }

        else
        {
            b=a6+a7;
            b=b/2;
        }

        c=a1+a2+a3+a4+b;

        if(c>=90)
        {
            printf("Case %d: A\n",i);
        }

        else if(c>=80)
        {
            printf("Case %d: B\n",i);
        }

        else if(c>=70)
        {
            printf("Case %d: C\n",i);
        }

        else if(c>=60)
        {
            printf("Case %d: D\n",i);
        }

        else
        {
            printf("Case %d: F\n",i);
        }
    }
    return 0;
}

