#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char c[102],ch[102];
    int len = 0, n = 0, i = 0, j = 0, x = 0;
    while(scanf("%d",&n) != EOF)
    {
        getchar();
        if(n == 0) return 0;
        x = 0;
        gets(c);
        len = strlen(c);
        int k = 0, q = 0;
        k = len / n;
        for(i=0; i<len; i+=k)
        {
            for(j=(i+k)-1; j>=i; j--)
            {
                ch[q] = c[j];
                q++;
            }
        }
        ch[len] = NULL;
        puts(ch);
    }
    return 0;
}
