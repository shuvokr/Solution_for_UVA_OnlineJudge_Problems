#include<stdio.h>
int main()
{
    int a,b,c,z=1;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {

        if(a==0 && b==0 && c==0) break;
        int i,j,k,l,m,n,o,d,p;
        d=(a*c)+(b*(c+1));
        printf("Case %d:\n",z);
        for(i=1; i<=c; i++)
        {
            for(j=1; j<=b; j++)
            {
                for(k=1; k<=d; k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            for(p=1; p<=a; p++){
            for(l=1; l<=c; l++)
            {
                for(m=1; m<=b; m++)
                {
                    printf("*");
                }
                for(n=1; n<=a; n++)
                {
                    printf(".");
                }
            }
            for(m=1; m<=b; m++)
            {
                printf("*");
            }
            printf("\n");}
        }
        for(j=1; j<=b; j++)
            {
                for(k=1; k<=d; k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            printf("\n");

        z++;
    }
    return 0;
}
