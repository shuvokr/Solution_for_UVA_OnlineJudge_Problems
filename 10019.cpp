#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
            int a,x,m=0,n=0,a1,a2,H=0,len,i,s,re;
            scanf("%d",&a);
            a1=a;a2=a;

        while(a1!=0)
	    {
	    	x=a1%2;
            a1=a1/2;
            m=m+x;
	    }

	    len=log10(a2);
	    for(i=0; i<=len; i++)
        {
            s=a2%10;
            a2=a2/10;
            re=s*(pow(16,i));
            H+=re;
        }

        while(H!=0)
	    {
	    	x=H%2;
            H=H/2;
            n=n+x;
	    }

            printf("%d %d\n",m,n);
        T--;
    }
    return 0;
}
