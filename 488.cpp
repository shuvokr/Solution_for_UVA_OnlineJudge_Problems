#include <stdio.h>

int main()
{   freopen("input.txt", "r", stdin);
    int x,y,cases,i;
    scanf("%d",&cases);
    for(i=0;i<cases;i++)
    {
        if(i>0)
            printf("\n");
        scanf("%d",&x);
        scanf("%d",&y);
        int j=0,k=0,l=0;
        for(l=0;l<y;l++)
        {
            if(l>0)
                printf("\n");
            for(j=1;j<x+1;j++)
            {
                for(k=0;k<j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
            for(j=x-1;j>0;j--)
            {
                for(k=0;k<j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
        }
    }
       return 0;
}
