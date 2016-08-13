#include<stdio.h>
int soda(int n, int c)
{
    int s=0,r=0,k=0,m=0;
    while(n>=c)
    {
        s=n%c;
        n=n/c;
        r+=n;
        n=n+s;
    }
    if(c-s==1)
    {
        r+=1;
        return r;
    }
    return r;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {

    int n,e,f,c,s=0,r=0,k;
    scanf("%d%d%d",&e,&f,&c);
    n=e+f;
    r=soda(n,c);
    printf("%d\n",r);

    T--;
    }
    return 0;
}
