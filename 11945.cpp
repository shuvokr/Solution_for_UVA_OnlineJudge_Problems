#include<stdio.h>
#include<math.h>
int main()
{
    int T,z=1;
    scanf("%d",&T);
    while(T--)
    {
        float k,a[13],s=0;
        long int n,i;
        for(i=1; i<=12; i++)
        {
            scanf("%f",&a[i]);
            s+=a[i];
        }
        s=s/12;
        if(s<=999.99)
            printf("%d $%.2f\n",z,s);
        else
        {
            n= (long)(s/1000.0);
            k=fmod(s,1000.0);
            printf("%d $%ld,%.2f\n",z,n,k);
        }
        z++;
    }
    return 0;
}
