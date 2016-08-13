#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char c[1000];
        gets(c);
        int len=strlen(c),i,m=0,f=0;
        if(len==2)
            printf("NO LOOP\n");
        else
        {
            for(i=0; i<len; i++)
            {
                if(c[i]=='M')
                    m++;
                if(c[i]=='F')
                    f++;
            }
            if(m==f)
                printf("LOOP\n");
            else
                printf("NO LOOP\n");
        }
    }
    return 0;
}
