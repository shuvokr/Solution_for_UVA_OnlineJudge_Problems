    #include <stdio.h>
    int main()
    {
        int T;
        scanf("%d",&T);
        while(T--)
        {
            int x, y, z,res,a,b;
            scanf("%d%d%d", &x, &y, &z);
            a=2*x;
            a=a-y;
            a=z*a;
            b=x+y;
            res =a/b;
            printf("%d\n",res);
        }
        return 0;
    }
