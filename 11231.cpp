#include<stdio.h>
int main()
{
    int m,n,c;
    while(scanf("%d%d%d",&m,&n,&c)==3)
    {
        if(m==0 && n==0 && c==0) break;
        int r=0,k=0;
        k=(m-7)*(n-7);
        r=k/2;
        if(k%2==1 && c==1)
            r++;
        printf("%d\n",r);
    }

    return 0;
}
