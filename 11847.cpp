#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(~scanf("%d", &n) && n)
        printf("%d\n", int(log2(n)));
    return 0;
}
