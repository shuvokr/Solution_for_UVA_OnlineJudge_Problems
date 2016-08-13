#include <stdio.h>
#include <algorithm>

using namespace std;

int in[ 1010 ], n;

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]);
        sort(in, in + n);
        reverse(in, in + n);
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n && in[ i ] != 0; j++)
            {
                if(in[ j ] == 0) continue;
                in[ j ]--;
                in[ i ]--;
            }
            sort(in + i + 1, in + n);
            reverse(in + i + 1, in + n);
        }
        for(int i = 0; i < n; i++)
            if(in[ i ] != 0) flag = false, i = n;
        puts(flag ? "1" : "0");
    }
    return 0;
}


