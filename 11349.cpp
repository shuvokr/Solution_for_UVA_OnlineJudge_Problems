#include<stdio.h>

long long int a[200][200];
char x[2],y[2];
int main()
{
    long long int T,z=1;
    scanf("%lld",&T);
    while(T--)
    {
        long long int k=0,ck,r=0,n,i,j,kk,sex=0;
        scanf("%s%s%lld",x,y,&n);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%lld",&a[i][j]);
                if(a[i][j]<0)
                    sex=1;
            }
        }
        if(sex==1) printf("Test #%lld: Non-symmetric.\n",z);
        else {
        k=n;
        for(i=1; i<=n; i++)
        {
            kk=n;
            for(j=1; j<=n; j++)
            {

                ck=a[i][j]-a[k][kk];
                kk--;
                if(ck!=0)
                {
                    r=1;
                    printf("Test #%lld: Non-symmetric.\n",z);
                    break;
                }
            }
                k--;
                if(r==1)
                    break;
            }
            if(r==0)
            printf("Test #%lld: Symmetric.\n",z);
        }
        z++;
    }
    return 0;
}
