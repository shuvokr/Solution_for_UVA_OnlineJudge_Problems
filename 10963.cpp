#include <stdio.h>

using namespace std;

int main()
{
    int T, a, b, n, tmp, i;
    scanf("%d", &T);
    bool ck;
    while(T--)
    {
        scanf("%d", &n); n--;
        scanf("%d %d", &a, &b);
        tmp = a - b;
        ck = true;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            a -= b;
            if(tmp != a) ck = false;
        }
        if( ck ) puts("yes");
        else puts("no");
        if( T ) puts("");
    }
    return 0;
}
