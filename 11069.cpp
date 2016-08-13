#include<stdio.h>
int main()
{
    int i,a[77];
    a[1]=1; a[2]=a[3]=2;
    for(i=4; i<77; i++)
        a[i] = a[i-2] + a[i-3];
    int n;
    while(scanf("%d",&n)==1)
        printf("%d\n",a[n]);
    return 0;
}
