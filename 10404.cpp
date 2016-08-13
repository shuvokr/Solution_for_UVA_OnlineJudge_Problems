#include <stdio.h>
using namespace std;
bool mamo[ 1000010 ];
int i, j, n, m, move_number[ 12 ];
int main()
{
    freopen("input.txt", "r", stdin);
    while(~scanf("%d %d", &n, &m))
    {
        for(i = 0; i < m; i++) scanf("%d", move_number + i);
        n++; for(i = 0; i < n; i++) mamo[ i ] = false;
        for(i = 0; i < n; i++)
        {
            if(!mamo[ i ])
            for(j = 0; j < m; j++)
                if(i + move_number[ j ] < n) mamo[i + move_number[ j ]] = true;
        }
        puts(mamo[n - 1] ? "Stan wins" : "Ollie wins");
    }
    return 0;
}
