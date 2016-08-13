#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
    int shu,i,b,m,j;
    int a[51];

    scanf("%d",&b);

    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }

    shu=0;

    for(j=0;j<b-1;j++)
    {
        for(i=0;i<b-1;i++)
        {
            if(a[i]>a[i+1])
            {
                m=a[i];
                a[i]=a[i+1];
                a[i+1]=m;
                shu++;
            }
        }
    }

    printf("Optimal train swapping takes %d swaps.\n",shu);
        T--;
    }
    return 0;
}
