#include<stdio.h>
int main()
{
    int t,n,a[100000],i,j,h,l,c=1;
    scanf("%d",&t);
    while(t>0)
    {
        h=0;
        l=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                l++;
            }
            if(a[j]<a[j+1])
            {
                h++;
            }
        }
        printf("Case %d: %d %d\n",c,h,l);
        c++;
        t--;
    }
    return 0;
}
