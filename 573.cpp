#include <stdio.h>

using namespace std;

int main()
{
	int H,U,D,F,done,day;
	while(scanf("%d %d %d %d",&H,&U,&D,&F) && H)
	{
		done = 0;
		day = 0;
		H = H*100;
		F = U*F;
		U = U*100;
		D = D*100;
		while(done <= H && done >= 0)
		{
			done += U;
			U = U - F;
			if(U < 0)
				U = 0;
			if(done <= H)
				done -= D;
			day++;
		}
		if(done > H)
			printf("success on day %d\n",day);
		else
			printf("failure on day %d\n",day);
	}
	return 0;
}
