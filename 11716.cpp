#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
    int T;
    char ch[1];
    scanf("%d",&T);
    gets(ch);
    while(T--)
    {
        char a[10001],ch1[1];
        gets(a);
        int len,i,j,k=0;
        len=strlen(a);
        int w;
        w=sqrt(len);
        if(w*w==len)
        {
            for(i=0; i<w; i++)
            {
                for(j=i; j<len; j+=w)
                {
                    printf("%c",a[j]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}
