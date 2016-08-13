#include<stdio.h>
int GCD(int a,int b)
{
    int c;
    if(a > b)
    {
        while(b != 0)
        {
            c = b;
            b = a % b;
            a = c;
        }
    }
    else
    {
        while(a != 0)
        {
            c = a;
            a = b % a;
            b = c;
        }
    }
    return c;
}
int main()
{
    int G,N,i,j;
    scanf("%d",&N);
    printf("%d\n", GCD(10, 32));
    while(N!=0)
    {
    G=0;
    for(i=1;i<N;i++)
    {
        for(j=i+1;j<=N;j++)
        {
            G+=GCD(i,j);
        }
    }
    printf("%d\n",G);
    scanf("%d",&N);
    }
    return 0;
}
