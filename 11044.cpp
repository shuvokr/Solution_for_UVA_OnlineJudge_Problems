#include<stdio.h>
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc>0)
    {
        int r,c,res;
        float rr;
        scanf("%d%d",&r,&c);
        rr=(r/3)*(c/3);
        res=(int)rr;
        printf("%d\n",res);

        tc--;
    }
    return 0;
}
