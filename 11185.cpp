#include <stdio.h>
#include <string.h>

int main ()

{
    char str [50];
    int n,i,k=1;
    scanf ("%d",&n);

    while (n>=0)
    {
        i=0;
        if (n==0)
        {
            str[i]=0;
            str[i++]+=48;
        }

    while (n!=0)
    {
        str[i]=n%3;
        str[i++]+=48;
        n/=3;
    }
    str[i]='\0';

    for(k=i-1; k>=0; k--)
    {
        printf("%c",str[k]);
    }
    printf("\n");

    scanf ("%d",&n);

    }
return 0;
}
