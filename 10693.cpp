#include<stdio.h>
#include<math.h>

int main()
{
    double V,volume,L,f;
    while((scanf("%lf%lf",&L,&f))==2)
    {
        if(L==0 && f==0)
        {
            break;
        }
        V = sqrt(L*f*2.0);
        volume = (V*3600)/(2*L);
        printf("%.8lf %.8lf\n",V,volume);
    }
    return 0;
}
