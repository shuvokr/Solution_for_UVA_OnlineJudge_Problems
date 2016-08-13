#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n, m, cou, i, res, b, j, mark;
    map <string, bool> mp;
    while(~scanf("%d", &n))
    {
        if(n == 0) return 0;
        mp.clear();
        scanf("%d", &m);
        for(i = 0; i < n; i++)
        {
            char tmp[10];
            scanf("%s", tmp);
            mp[ tmp ] = true;
        }
        mark = 1;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &b, &cou);
            for(j = 0; j < b; j++)
            {
                char tmp[10];
                scanf("%s", tmp);
                if( mp[ tmp ] ) cou--;
            }
            if(cou > 0) mark = 0;
        }
        if(mark) puts("yes");
        else puts("no");
    }
    return 0;
}

