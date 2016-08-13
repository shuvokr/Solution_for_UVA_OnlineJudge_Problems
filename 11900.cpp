#include<stdio.h>
int main()
{
    int T,c=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,p,q;
        scanf("%d%d%d",&n,&p,&q);
        int i,ar[40];
        for(i=0; i<n; i++)
        {
            scanf("%d",&ar[i]);
        }
        int k=0,sum=0,cou=0;
        for(i=0; i<n && i<p;)
        {
            sum+=ar[i];
            if(sum>q) break;
            i++;
        }
        printf("Case %d: %d\n",c,i);
        c++;
    }
    return 0;
}
