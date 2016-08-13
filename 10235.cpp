#include<stdio.h>
#include<math.h>
long isprime(long int n)
{
	long int i,lim=999999999;
	lim=sqrt(n);
	for(i=2; i<=lim; i++)
	{
		if((n%i)==0)
		{
			return 0;
		}
	}
	return 1;
}

long emprime(long int x)
{
	long int y,len,i,z=0,l,c,r,k=x;
	len=log10(x);
	l=len;
	for(i=0;i<=len;i++)
	{
		y=x%10;
		z=z+y*(pow(10,l));
		l--;
		x=x/10;
	}
	if(k==z)
	{
		return 0;
	}
	if(k!=z)
	{
		r=isprime(z);
	}
	return r;
}

int main()
{

	long int a,aa,j=0,m,k,jj,r,c;

		while(scanf("%ld",&a)==1)
		{
			aa=a;
			j=0;
				r=isprime(a);
				if(r==0)
				{
					printf("%ld is not prime.\n",aa);
				}
				else
				{
                    c=emprime(a);
                    j=r+c;
                    if(j==2)
                    {
                        printf("%ld is emirp.\n",aa);
                    }
                    if(j==1)
                    {
                        printf("%ld is prime.\n",aa);
                    }
				}
		}
return 0;

}
