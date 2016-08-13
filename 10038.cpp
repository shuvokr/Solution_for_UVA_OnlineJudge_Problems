#include<stdio.h>
#include<stdlib.h>
int a[3002];
int main()
{
    int i = 0, k = 0, ck = 0, n = 0;
    while(scanf("%d",&n) != EOF)
    {
        ck = 0;
        int b[3002] = {0};
        scanf("%d",&a[1]);
        for(i=2; i<=n; i++)
        {
            scanf("%d",&a[i]);
            k = a[i] - a[i-1];
            if(k<0)
                k=abs(k);
            b[k]=1;
        }
        for(i=1; i<n; i++)
        if(b[i] != 1)
        {
            ck = 1; break;
        }
        if(ck == 0)
            puts("Jolly");
        else
            puts("Not jolly");
    }
    return 0;
}
