#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char in[ 1000010 ], ch[ 20 ];
map <string, int> mp;
int main()
{
    int n, m, i, tmp, res;
    while(~scanf("%d %d", &n, &m))
    {
        mp.clear();
        for(i = 0; i < n; i++) scanf("%s %d", ch, &tmp), mp[ ch ] = tmp;
        getchar();
        for(i = 0; i < m; i++)
        {
            res = 0;
            while( gets(in) )
            {
                if(in[ 0 ] == '.' && in[ 1 ] == NULL) break;
                char *tok;
                tok = strtok(in, " .,");
                while(tok != NULL)
                {
                    res += mp[ tok ];
                    tok = strtok(NULL, " .,");
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
