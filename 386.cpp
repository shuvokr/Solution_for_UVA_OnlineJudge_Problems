#include <stdio.h>
using namespace std;
#define f(n) n*n*n
#define ff(a, b, c) a*a*a+b*b*b+c*c*c
int main()
{
    int a, b, c, d, resa, resbcd;
    for(a = 6; a < 201; a++)
    {
        resa = f(a);
        for(b = 2; b < 201; b++)
            for(c = b + 1; c < 201; c++)
                for(d = c + 1; d < 201; d++)
                {
                    resbcd = ff(b, c, d);
                    if(resa == resbcd) printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d), d = 201;
                    if(d == c + 1 && resbcd > resa) c = d = 201;
                }
    }
    return 0;
}
