#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
#define N 1000
int main()
{
    int T, len, i, j;
    char k;
    sf("%d",&T);
    getchar();
    while(T--)
    {
        char ch[N];
        gets(ch);
        len = strlen(ch);
        for(i = 0; i < len; i++)
        {
            if(ch[i] > 64 && ch[i] < 91)
                ch[i] += 32;
        }
        len--;
        for(i = 0; i < len; i++)
            for(j = 0; j < len; j++)
                if(ch[j] > ch[j+1])
                {
                    k = ch[j];
                    ch[j] = ch[j+1];
                    ch[j+1] = k;
                }
                j = 0;
        char ck = ch[0], c[N];
        lu ans[N], count = 0, magic = 0;
        for(i = 0; i <= len; i++)
        {
            if(ch[i] > 96 && ch[i] < 123)
            {
                while(ck == ch[i])
                {
                    count++;
                    i++;
                }
                if(magic < count) magic = count;
                ans[j] = count;
                count = 0;
                c[j] = ck;
                ck = ch[i];
                j++;
                i--;
            }
        }
        for(i = 0; i < j; i++)
        {
            if(ans[i] == magic)
                pf("%c",c[i]);
        }
        pf("\n");
    }
    return 0;
}
