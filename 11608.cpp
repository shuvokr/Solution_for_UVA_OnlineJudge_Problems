#include<stdio.h>
int main()
{
    int c=1,s;
    scanf("%d",&s);
    while(s>=0)
    {
        int a[12],b[12],i,sum=0;
        for(i=0; i<12; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<12; i++)
        {
            scanf("%d",&b[i]);
        }
        printf("Case %d:\n",c);
        for(i=0; i<12; i++)
        {
            if(s>=b[i])
            {
                printf("No problem! :D\n");
                s=s-b[i];
                s+=a[i];
            }
            else
            {
                printf("No problem. :(\n");
                s+=a[i];
            }
        }
        scanf("%d",&s);
        c++;
    }
    return 0;
}

