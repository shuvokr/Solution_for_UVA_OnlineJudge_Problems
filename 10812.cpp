#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long int s,d,m,big,small;
        scanf("%ld%ld",&s,&d);
        if(d>s || (s-d)%2!=0)
        {
            printf("impossible\n");
        }
        else
        {
            m=s-d;
            big=(m/2)+d;
            small=big-d;
            printf("%ld %ld\n",big,small);
        }
    }
    return 0;
}
