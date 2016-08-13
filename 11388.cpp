#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(y%x==0)
        {
            printf("%d %d\n",x,y);
        }
       else
       {
            printf("-1\n");
       }

    }
       return 0;
}
