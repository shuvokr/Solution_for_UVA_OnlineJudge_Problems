#include<stdio.h>

int main()
{

	int a,b,c,m,n;
	scanf("%d%d%d",&a,&b,&c);

	while(a!=0 && b!=0 && c!=0)
	{
	    if(a>b && a>c)
	{
        m=c*c+b*b;
        n=a*a;
	}
	else if(b>c && b>a)
	{
	    m=a*a+c*c;
	    n=b*b;
	}
	else
	{
	    m=a*a+b*b;
	    n=c*c;
	}
		if(m==n)
		{
            printf("right\n");
		}
		 else
        {
            printf("wrong\n");
        }
		scanf("%d%d%d",&a,&b,&c);


	}

	return 0;

}
