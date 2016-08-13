#include <stdio.h>
int main ()
{
	long long n;
	while ( ~scanf ("%lld", &n) )
	{

		long long p = 1;
		bool stan = true;
		bool ollie = false;

		while ( p < n )
		{

			if ( stan )
			{
				p *= 9;
				stan = false;
				ollie = true;
			}
			else
			{
				p <<= 1;
				ollie = false;
				stan = true;
			}
		}
        puts(!stan ? "Stan wins." : "Ollie wins.");
	}
	return 0;
}

