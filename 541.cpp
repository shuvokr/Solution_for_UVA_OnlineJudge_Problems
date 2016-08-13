#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int i,j,a[500][500],s=0,k=0,m=0,mm=0,z=0,zz=0;;
        for(i=1; i<=n; i++)
        {
            s=0;
            for(j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                s+=a[i][j];
            }
            if(s%2!=0)
            {
                m++;
                z=i;
            }
        }
        for(i=1; i<=n; i++){
            s=0;
            for(j=1; j<=n; j++)
            {
                s+=a[j][i];
            }
            if(s%2!=0)
            {
                mm++;
                zz=i;
            }
        }
        if(m==0 && mm==0)
            printf("OK\n");
        else if(m>1 || mm>1)
            printf("Corrupt\n");
        else
            printf("Change bit (%d,%d)\n",z,zz);

        scanf("%d",&n);
    }
    return 0;
}
