/*
            uva
            Author: Shuvo
            Problem ID: 11824
            Problem name:  A Minimum Land Price
*/

#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int T,cc=0;
	scanf("%d",&T);
	while(cc<T)
	{
		unsigned int a[41],i,b=-1,m,j,x=10,k=0;
        while(x!=0)
        {
            scanf("%d",&a[k]);
            x=a[k];
            k++;
            b++;
        }
        for(j=0;j<b-1;j++)
        {
            for(i=0;i<b-1;i++)
            {
                while(a[i]<a[i+1])
                {
                    m=a[i];
                    a[i]=a[i+1];
                    a[i+1]=m;
                }
            }
        }
        long int res=0,re=0,kk=0;
        for(i=0;i<b;i++)
        {
            kk=a[i];
            re=pow(kk,i+1);
            re=2*re;
            res=res+re;
            re=0;
            kk=0;
        }

        if(res<=5000000)
        {
            printf("%lld\n",res);
        }

        else if(res>5000000)
        {
            printf("Too expensive\n");
        }
        cc++;
	}

	return 0;
}
