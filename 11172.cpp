#include<stdio.h>
int main()
{
    int T,s=1;
    long long int a,b;
    scanf("%d",&T);

    while(T>=s)
    {
        scanf("%lld%lld",&a,&b);
        if(a<b)
        {
            printf("<\n");
        }
        else if(a>b)
        {
            printf(">\n");
        }
        else
        {
            printf("=\n");
        }
        s++;
    }
    return 0;
}
