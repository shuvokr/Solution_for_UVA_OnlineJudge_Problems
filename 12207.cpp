#include <cstdio>
#include <deque>
using namespace std;
int main()
{
    int kag = 0, p, q, n, l, h;
    deque <int> dq;
    char ch[ 9 ];
    while(~scanf("%d %d", &p, &q) && p)
    {
        p++; dq.clear();
        if (p < 2000)
            for (int i = 1; i < p; i++) dq.push_back(i);
        else
        {
            for (int i = 1; i < 1001; i++) dq.push_back(i);
            for (int i = p - 1000; i < p; i++) dq.push_back(i);
        }
        printf("Case %d:\n", ++kag);
        while(q--)
        {
            scanf("%s", ch);
            if(ch[ 0 ] == 'N')
            {
                int fr = dq.front();
                while(!fr)
                {
                    dq.pop_front();
                    fr = dq.front();
                }
                printf("%d\n", fr);
                dq.pop_front();
                dq.push_back( fr );
            }
            else
            {
                scanf("%d", &n);
                h = dq.size();
                for(int i = 0; i < h; i++)
                    if(dq[ i ] == n) dq[ i ] = 0;
                dq.push_front( n );
            }
        }
    }
    return 0;
}
