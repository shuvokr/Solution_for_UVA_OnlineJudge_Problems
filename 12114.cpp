#include<stdio.h>
int main()
{
    unsigned long int z=1,b,s;
    while(scanf("%lu%lu",&b,&s)==2)
    {
        if(b==0 && s==0) break;
        printf("Case %lu: ",z);
        if(b==0 || b==1)
            printf(":-\\\n");
        else if(b<=s)
            printf(":-|\n");
        else
            printf(":-(\n");
            z++;
    }
    return 0;
}
