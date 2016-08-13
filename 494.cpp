#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char c[100000];
    int i,j,len;
    while(gets(c))
    {
        j=0;
        len = strlen(c);
        for(i=0 ; i<len ; i++)
        {
            if(isalpha(c[i]))
            {
                while(isalpha(c[i]))
                    i++;
                j++;
            }
        }
        printf("%d\n",j);
    }
    return 0;

}
