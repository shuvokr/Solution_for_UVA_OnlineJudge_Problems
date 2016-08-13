#include<stdio.h>
int main()
{
    int T,j,k=0,r=0,i;
    scanf("%d",&T);
    for(j=1; j<=T; j++)
    {
        int a[50];
        for(i=1; i<=10; i++)
        {
            scanf("%d",&a[i]);
        }

        if(a[1]>a[2])
        {
            for(i=1; i<10; i++)
            {
                if(a[i]>a[i+1])
                {
                    r+=1;
                }
            }
        }
        else
        {
            for(i=1; i<10; i++)
            {
                if(a[i]<a[i+1])
                {
                    r+=1;
                }
            }
        }
        if(k==0)
        {
            printf("Lumberjacks:\n");
        }
        k=1;
        if(r==9)
        {
            printf("Ordered\n");
        }
        else
        {
            printf("Unordered\n");
        }
        r=0;
    }
    return 0;
}
