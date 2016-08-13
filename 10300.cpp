#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long int f,a,b,c,sum=0,i;
        scanf("%lu",&f);
        while(f--)
        {
            scanf("%lu%lu%lu",&a,&b,&c);
            sum+=a*c;
        }
        printf("%lu\n",sum);
    }
    return 0;
}
