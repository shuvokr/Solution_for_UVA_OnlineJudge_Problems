#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char ch[21],c[21];
        int i, j, ck = 1;
        scanf("%s%s",ch,c);
        i = strlen(ch);
        j = strlen(c);
        if(i != j) puts("No");
        else
        {
            for(i = 0; i < j; i++)
            {
                if(ch[i] != 'a' && ch[i] != 'e' && ch[i] != 'i' && ch[i] != 'o' && ch[i] != 'u')
                {
                    if(ch[i] != c[i])
                    {
                        ck = 0;
                        break;
                    }
                    else ck = 1;
                }
                else if((ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') && (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'))
                {
                    ck = 1;
                }
                else
                {
                    ck = 0; break;
                }
            }
            if(ck == 1) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
