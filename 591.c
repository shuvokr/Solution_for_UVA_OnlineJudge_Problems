#include<stdio.h>
int main()
{
    int n,k[100000],r=0,i,c=1,m=0,j;
    scanf("%d",&n);
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k[i]);
            if(k[i]>=1 && k[i]<=100)
            {
                r=r+k[i];
            }
        }
                r=r/n;
        for(j=1;j<=n;j++)
        {
            if(k[j]>r)
            {
                m=(k[j]-r)+m;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,m);
        r=0;
        scanf("%d",&n);
        c++;
        m=0;
    }
    return 0;
}
