#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        if(n>=1 && n<=100)
        {
        if(n%2==0)
        {
            n=n/2;
            printf("%d\n",n);
        }
        else
        {
            n=n-1;
            n=n/2;
            printf("%d\n",n);
        }
        scanf("%d",&n);
        }
    }
    return 0;
}
