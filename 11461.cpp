#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,i;
    scanf("%d%d",&a,&b);
    while(a!=0 && b!=0)
    {
        if(a<b)
        {
        d=1;
        e=0;
        for(i=a;i<=b;i++)
        {
            c=d*d;
            while(c<=i)
            {
                if(c==i)
                {
                    e++;
                }
                d++;
                c=d*d;
            }
        }
        }
        else
        {
            d=1;
            e=0;
            for(i=b;i<=a;i++)
            {
                c=d*d;
                while(c<=i)
                {
                    if(c==i)
                    {
                        e++;
                    }
                    d++;
                    c=d*d;
                }
            }
        }
        printf("%d\n",e);

        scanf("%d%d",&a,&b);
    }
    return 0;
}
