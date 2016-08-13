#include<stdio.h>
int main()
{
    int n,s;
    while(scanf("%d",&n)==1)
    {
        s=n;
        if(n>=1 && n<=200)
        {
        if(n%2==0)
        {
            n=n/2;
            n=n+s;
        }
        else
        {
            n=n-1;
            n=n/2;
            n=n+s;
        }
        }
        printf("%d\n",n);
    }
    return 0;
}

