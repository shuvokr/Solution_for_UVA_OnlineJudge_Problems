#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
 {
    int T, z = 0, j = 0, k = 0, len, i;
    char Inpch[1000], c;
    sf("%d", &T);
    getchar();
    while(T--)
    {
        gets(Inpch);
        len = strlen(Inpch);
        char res[1000] = {0};
        pf("Case %d: ", ++z);
        for(i = 0; i < len; i++)
        {
            int p=0;
                if(isalpha(Inpch[i]))
                    c = Inpch[i];
                else if(!isalpha(Inpch[i]))
                {
                    p += Inpch[i] - '0';
                    i++;
                    while(Inpch[i] >= '0' && Inpch[i] <= '9')
                    {
                        p = p * 10 + Inpch[i] - '0';
                        i++;
                    }
                    i--;
                    for(j = 0; j < p; j++)
                    {
                        res[k] = c;
                        k++;
                    }
                }
        }
        puts(res);
        k = 0;
    }
    return 0;
}

