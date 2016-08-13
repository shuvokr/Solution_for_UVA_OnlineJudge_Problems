#include <stdio.h>
#include <math.h>
int a = 0, b = 0, c = 0;
int f(int x)
{
    int k = a*pow(x,2) + b*x + c;
	return k;
}
int main()
{
	int d = 0, l = 0, i = 0, count = 0;
	while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l) != EOF)
	{
	    if (a == 0 && b == 0 && c == 0 && d == 0 && l == 0) return 0;
		count = 0;
		for(i=0;i<=l;i++)
			if(f(i)%d == 0)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
