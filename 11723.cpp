#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,z=1;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        if(a == 0 && b == 0) return 0;
        a = a - 1 ;
        a /= b;
        if(a > 26) printf("Case %d: impossible\n",z++);
        else printf("Case %d: %d\n",z++,a);
    }
}
