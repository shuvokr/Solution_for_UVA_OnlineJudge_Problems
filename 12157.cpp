#include<stdio.h>
int main()
{
    int T,c=1;
    scanf("%d",&T);
    while(T>0)
    {
        int ck1=0,ck2=0,j,k,i,n,a[21],w=0,z=0,xx,yy;
        float x=0,y=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            ck1=0;ck2=0;
            j=1;k=1;
            while(ck1<a[i])
            {
                w++;
                ck1=(j*30)-1;
                j++;
            }
            while(ck2<a[i])
            {
                z++;
                ck2=(k*60)-1;
                k++;
            }
        }

        w=w*10;
        z=z*15;
        if(w<z)
        {
            printf("Case %d: Mile %d\n",c,w);
        }
        else if(z<w)
        {
            printf("Case %d: Juice %d\n",c,z);
        }
        else
        {
            printf("Case %d: Mile Juice %d\n",c,z);
        }

        c++;
        T--;
    }
    return 0;
}
