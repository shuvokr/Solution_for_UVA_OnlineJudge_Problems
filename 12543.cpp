#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    char ch[102], res[102], ck[] = "E-N-D";
    memset(ch, 0, sizeof(ch));
    memset(res, 0, sizeof(res));
    int max = 0, len = 0, shuvo = 0, i = 0;
    while(sf("%s", ch) && strcmp(ck, ch))
    {
        shuvo = 0;
        len = strlen(ch);
        for(i = 0; i < len; i++)
            if(isalpha(ch[i]) || ch[i] == '-')
                shuvo++;

        if(max < shuvo)
        {
            max = shuvo;
            strcpy(res, ch);
        }
    }

    len = strlen(res);
    for(i = 0; i < len; i++)
        if(isalpha(res[i]) || res[i] == '-')
            pf("%c", tolower(res[i]));
    puts("");

    return 0;
}
