#include<stdio.h>

int main()
{
    int l=1000,op=0;
    int a[l];
    int i,b,m,j;
    while(scanf("%d",&b)==1)
    {
        op=0;
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<b-1;j++)
    {
        for(i=0;i<b-1;i++)
        {
            if(a[i]>a[i+1])
            {
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
                op++;
            }
        }
    }
    printf("Minimum exchange operations : %d\n",op);
    }
    return 0;
}

