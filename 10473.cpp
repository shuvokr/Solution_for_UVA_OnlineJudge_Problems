#include<stdio.h>
#include<string.h>
int main()
{
    long long int N,x;
    char n[1000],e[1000],y;
    while(gets(n))
    {
        if(n[0]=='-') return 0;
        N=0;
        if(n[0]=='0' && n[1]=='x')
        {
            sscanf(n,"%lld%c%llX",&x,&y,&N);
            printf("%lld\n",N);
        }
        else
        {
            sscanf(n,"%lld",&N);
            printf("0x%llX\n",N);
        }
    }
    return 0;
}
