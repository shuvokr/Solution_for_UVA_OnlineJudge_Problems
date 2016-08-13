#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#define lu unsigned long int
#define llu unsigned long long int
#define sf scanf
#define pf printf
#define N 120

int main()
{
    lu len, i, j = 0,ck = 0, k = 0, flag = 0, s = 0;
    char ar[150], n;
    while(sf("%c %s",&n,ar) != EOF)
    {
        getchar();
        len = strlen(ar);
        if(len == 1 && n == '0' && ar[0] == '0') return 0;
        char res[150] = {0};
        k = 0;
        for(i = 0; i < len; i++)
        {
            if(n != ar[i])
            {
                res[j] = ar[i];
                k += (res[j] - 48);
                if(k != 0 && s == 0)
                {
                    flag = j; s == 1;
                }
                j++;
                ck = 1;
            }
        }
        if(ck == 0) puts("0");
        else if(k == 0) puts("0");
        else if(res[0] != '0') puts(res);
        else
        {
            k = 0;
            j = 0;
            len = strlen(res);
            for(i = 0; i < len; i++)
            {
                k += res[i] - 48;
                if(k != 0){ j = i; break;}
            }
            ck = 0;
            for(i = j; i < len; i++)
            {
                pf("%c",res[i]);
            }
            pf("\n");
        }

        j = 0;
        ck = 0;
        s = 0;
    }
    return 0;
}
