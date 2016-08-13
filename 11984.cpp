#include<stdio.h>
int main()
{
    int T,s=1;
    float c,d,F,L;
    scanf("%d",&T);
    while(T>=s)
    {
        scanf("%f%f",&c,&d);
        F=((9*c)/5)+32;
        F=F+d;
        L=(5*(F-32))/9;
        printf("Case %d: %.2f\n",s,L);
        s++;
    }
    return 0;
}
