#include <stdio.h>
int main()
{
    int T, n, x, kag = 0;
    double p, probality, expected;
    scanf("%d", &T);
    while ( T-- )
    {
        scanf("%d", &n);
        probality = 1.0; expected = 0.0;
        while ( n-- )
        {
            scanf("%d %lf", &x, &p);
            if( x > 0 ) expected += (x*p);
            else expected += ((-x)*p), probality -= p;
        }
        probality > 0.0 ? printf("Case %d: %.2lf\n", ++kag, expected/probality):printf("Case %d: God! Save me\n", ++kag);
    }
    return 0;
}
