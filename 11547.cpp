#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        int n;
        scanf("%d",&n);
        n=((((((n*567)/9)+7492)*235)/47)-498);
        n=n/10;
        n=n%10;
        if(n>=0)
        {
            printf("%d\n",n);
        }
        else
        {
            n=n*-1;
            printf("%d\n",n);
        }
        T--;
    }
    return 0;

}
