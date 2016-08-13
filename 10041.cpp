#include<stdio.h>
int main()
{
    int strt[30002],dis,i,j,k,r,T,d,min,Q;
        scanf("%d",&T);
        while(T--)
        {
            scanf("%d",&r);
            for(j=1;j<=r;j++)
            {
                scanf("%d",&strt[j]);
            }
            for(j=1;j<=r;j++)
            {
                for(k=1;k<r;k++)
                {
                    if(strt[k]>strt[k+1])
                    {
                        Q=strt[k];
                        strt[k]=strt[k+1];
                        strt[k+1]=Q;
                    }
                }
            }
            for(j=1;j<=r;j++)
            {
                dis=0;
                for(k=1;k<=r;k++)
                {
                    d=strt[k]-strt[j];
                    if(d<0) d*=-1;
                    dis+=d;
                }
                if(j==1) min=dis;
                if(dis<min) min=dis;
            }
            printf("%d\n",min);
        }
    return 0;
}
