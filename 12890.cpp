#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    map<int, int> last_pos;
    int T, n, in[ 100010 ];
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &in[ i ]);
        int last = 0;
        long long res = 0;

        last_pos.clear();
        for(int i = 1; i <= n; i++)
        {
            if(last_pos[ in[ i ] ] && last_pos[ in[i] ] > last) last = last_pos[ in[ i ] ];
            res += i - last;
            last_pos[ in[ i ] ] = i;
        }
        printf("%lld\n", res);
    }
    return 0;
}
