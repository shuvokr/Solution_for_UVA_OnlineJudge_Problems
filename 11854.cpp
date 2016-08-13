#include <stdio.h>
#include <math.h>

int main ()
{
    long long int x,y,z,a,b,m,n,o;
    scanf ("%lld%lld%lld", &x, &y, &z);
    while (x!= 0 && y!= 0 && z!= 0)
    {
        if(x>y && x>z)
        {
            m=x;
            n=y;
            o=z;
        }
        else if(y>x && y>z)
        {
            m=y;
            n=x;
            o=z;
        }
        else
        {
            m=z;
            n=x;
            o=y;
        }
        a = pow (m, 2);
        b = pow (n, 2) + pow (o, 2);
        if (a == b)
        {
            printf ("right\n");
        }
        else
        {
            printf ("wrong\n");
        }
    scanf ("%lld%lld%lld",&x,&y,&z);
    }
    return 0;
}


