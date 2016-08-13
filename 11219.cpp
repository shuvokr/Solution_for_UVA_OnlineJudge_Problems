#include <stdio.h>
int main()
{
    int t,i=1;
    scanf("%d",&t);
    while(t--)
    {
            int a,b,c,e,f,g,k;
            scanf("%d/%d/%d",&a, &b, &c);
            scanf( "%d/%d/%d",&e, &f, &g);
            k=(c-g);
            if(b<f)
            {
                k--;
            }
            else if(b==f)
            {
                if(a<e)
                {
                    k--;
                }
            }
            if(k<0)
            {
                printf("Case #%d: Invalid birth date\n", i );
            }
            else if(k>130)
            {
                printf("Case #%d: Check birth date\n", i);
            }
            else
            {
                printf("Case #%d: %d\n",i,k);
            }
            i++;
    }
return(0);
}
