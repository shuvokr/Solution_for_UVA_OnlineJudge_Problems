#include<stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        int n,r=0,j,c;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&c);
            if(c>r)
                r=c;
        }
        printf("Case %d: %d\n",i,r);
    }
    return 0;
}
