#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char c[10000];
    int i=0, j=0, k=0, n=0, m=0 , len=0;
    while(gets(c))
    {
        k = 0;
        len = strlen(c);
        for(i=0; i<len; i++)
        {
            if(isupper(c[i]) || c[i]=='*' || c[i]==32)
                {
                    j = i-1;
                    while(isdigit(c[j]))
                    {
                        k++;
                        j--;
                    }
                    j = i - k;
                    for(k=j; k<i; k++)
                        for(n=c[k]-48; n>0; n--)
                            printf("%c",c[i]);
                }
                k = 0;
            if(c[i] == 'b')
            {
                j = i - 1;
                while(isdigit(c[j]))
                {
                    k++;
                    j--;
                }
                j = i - k;
                for(k=j; k<i; k++)
                    for(n=c[k]-48; n>0; n--)
                        printf(" ");
            }
            if(c[i] == '!')
                printf("\n");
        }
        printf("\n");
    }
    return 0;
}
