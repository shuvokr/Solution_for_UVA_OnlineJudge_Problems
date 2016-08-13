#include<stdio.h>
int main()
{
    int a,b,c,d,e,j;
    scanf("%d",&d);
    while(d--)
    {
        scanf("%d:%d",&a,&b);
        c=11-a;
        e=60-b;

        if(c==-1 && b!=0)
            c=11;

        if(b==0)
        {
            c=c+1;
            e=0;
        }

        if(c<0)
            c=c/(-1);

        if(c==0)
            c=12;

        if(c>9)
            printf("%d:",c);
        else
            printf("0%d:",c);

        if(e>9)
            printf("%d\n",e);
        else
            printf("0%d\n",e);
    }
    return 0;
}
