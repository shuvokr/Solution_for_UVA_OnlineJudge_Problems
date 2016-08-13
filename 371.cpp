#include<stdio.h>
int main()
{
    unsigned long long int s,a,b,i,n,k,j,kk,h,a1,b1;

    while(scanf("%llu%llu",&a,&b) != EOF)
    {
        if(a == 0 && b == 0) return 0;

        kk = 0;
        if(a > b)
        {
            a1 = b;
            b1 = a;
            n = a;
            s = b;
        }
        else
        {
            a1 = a;
            b1 = b;
            n = b;
            s = a;
        }

        for(i = s; i <= n; i++)
        {
            j = 1;
            k = i;
            do
            {
                if(k%2 == 0)
                {
                    k=k/2;
                }
                else
                {
                    k=3*k+1;
                }
                j++;
            }
            while(k != 1);

            if(kk < j)
            {
                kk = j;
                h = i;
            }
        }
         printf("Between %llu and %llu, %llu generates the longest sequence of %llu values.\n", a1, b1, h, kk - 1);
    }
    return 0;
}

