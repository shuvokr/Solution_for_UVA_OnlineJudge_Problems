#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i, T = 0, z = 0, ck = 0, n = 0, t = 0;
    scanf("%d",&T);
    while(T--)
    {
        int i, len = 0, j = 0, k = 0, x = 0, ent[100000], xx = 0, cou = 0;
        char c[100000];
        if(t == 1)
        {
            scanf("%d",&n);
            printf("\nCase %d:\n",++z);
        }
        else
        {
            scanf("%d",&n);
            printf("Case %d:\n",++z);
            t = 1;
        }
        getchar();
        for(i = 0; i < n; i++)
        {
            x = 0;
            gets(c);
            char ch[100000] = {0};
            len = strlen(c);
            for(j = 0; j < len; j++)
            {
                if(c[j] != 32)
                {
                    printf("%c",c[j]);
                }
                if(c[j] == 32 && c[j+1] !=32)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

