#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    int L, N, i, j;
    while(sf("%d %d", &L, &N) != EOF)
    {
        char irra[22][22], plu[22][22], inp[22];
        memset(irra, 0, sizeof(irra));
        memset(plu, 0, sizeof(plu));
        for(i = 0; i < L; i++)
        {
            sf("%s%s", irra[i], plu[i]);
        }
        getchar();
        for(i = 0; i < N; i++)
        {
            bool ck = false;
            memset(inp, 0, sizeof(inp));
            gets(inp);
            for(j = 0; j < L; j++)
            {
                if(strcmp(irra[j], inp) == 0)
                {
                    puts(plu[j]);
                    ck = true;
                    break;
                }
                if(ck) break;
            }
            if(!ck)
            {
                int len = strlen(inp);
                if(inp[len - 1] == 'y' && (inp[len - 2] != 'a' && inp[len - 2] != 'e' && inp[len - 2] != 'i' && inp[len - 2] != 'o' && inp[len - 2] != 'u'))
                {
                    for(j = 0; j < len - 1; j++)
                        pf("%c", inp[j]);
                    puts("ies");
                }
                else if(inp[len - 1] == 'o' || inp[len - 1] == 's' || (inp[len - 1] == 'h' && inp[len - 2] == 'c') || (inp[len - 1] == 'h' && inp[len - 2] == 's') || inp[len - 1] == 'x')
                {
                    for(j = 0; j < len; j++)
                        pf("%c", inp[j]);
                    puts("es");
                }
                else
                {
                    for(j = 0; j < len; j++)
                        pf("%c", inp[j]);
                    puts("s");
                }
            }
        }
    }

    return 0;
}
