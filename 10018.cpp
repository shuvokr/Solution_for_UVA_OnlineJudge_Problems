#include<stdio.h>
int count=0;
int main()
{
    unsigned long int n;
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        count=0;
        scanf("%lu",&n);
        unsigned long int len=0,i,r=0,m=0,stor,c,k,ans;
        stor=n;
        do{
        r=0;
        while(n>0)
        {
            m=n%10;
            r=(r*10)+m;
            n=n/10;
        }
        ans=stor+r;
        r=0;
        c=ans;
        while(c>0)
        {
            m=c%10;
            r=(r*10)+m;
            c=c/10;
        }
        count++;
        n=ans;
        stor=ans;
        }while(r!=ans);

        printf("%d %lu\n",count,r);

        T--;
    }
    return 0;
}
