#include<stdio.h>
#include<string.h>
int main()
{
    int T,r=0;
    scanf("%d",&T);
    while(T>0)
    {
        char c[100];
        int k;
        scanf("%s",c);
        if(strcmp(c,"donate")==0)
        {
            scanf("%d",&k);
            r+=k;
        }
        else
        {
            printf("%d\n",r);
        }
        T--;
    }
    return 0;
}
