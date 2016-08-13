#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        int a[100000],i,j=0;
        float s,h,u,sum=0,n;
        scanf("%f",&n);
        for (i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }

        s = sum/n;

        for (i=0; i<n; i++)
        {
            if(s<a[i])
            {
                j++;
            }
        }

        h=(j/n)*100;

        printf("%.3f%%\n",h);

        T--;
    }
    return 0;
}
