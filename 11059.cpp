#include <stdio.h>

int main()
{
    int cases = 0,counter = 0;
    while(scanf("%d",&cases) != EOF)
        {
            int i,j,k,x[cases];
            for(i=0;i<cases;i++)
              scanf("%d",&x[i]);
            long max=0;
            for (i = 0; i < cases; i++)
            {
                    for (j = i; j < cases; j++)
                    {
                        long pro = 1;
                        for (k = i; k <= j; k++)
                        {
                            pro*=x[k];
                        }
                        if(max<pro)
                            max = pro;
                    }
                }
            printf("Case #%d: The maximum product is %ld.\n\n",++counter,max);
    }
    return 0;
}
