#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    char c[1000000];
    while(gets(c))
    {
        int len,i,j;
        char b[1000000]={NULL};
        len = strlen(c);
        for(i=0; i<len; i++)
        {
            if(c[i]!=' ')
            {
                b[i] = c[i]-7;
            }
            else
            {
                b[i] =32;
            }
        }
        puts(b);
    }

    return 0;
}
