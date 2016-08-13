#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long int n,res;
    scanf("%lu",&n);
    while(n!=0)
    {
        res=(long)sqrt(n);
        if(res*res==n)
            printf("yes\n");
        else
            printf("no\n");
        scanf("%lu",&n);
    }
    return 0;
}
