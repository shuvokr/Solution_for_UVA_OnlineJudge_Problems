#include<stdio.h>
int main()
{
    int s,n,i;
    scanf("%d",&n);
    while(n!=0)
    {
        if(n>=1 && n<=100)
        {
        s=0;
    for(i=1;i<=n;i++)
    {
        s=s+(i*i);
    }
    printf("%d\n",s);

        }
    scanf("%d",&n);
    }
    return 0;
}
