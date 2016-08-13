#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct data
{
    int ind, p;
}in[ 110 ];

bool cmp(const data &x, const data &y)
{
    if (x.p > y.p || (x.p == y.p && x.ind < y.ind)) return true;
    return false;
}

vector <int > v;

int n, m;

int main()
{
    int T, ans; scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &in[i].p), in[i].ind = i;
            v.push_back( in[i].p );

        }
        sort(in, in + n, cmp);
        ans = 0;
        while(v.size())
        {
            //for(int i = 0; i < n; i++) printf("(%d %d) ", in[i].ind, in[i].p); puts("");
            int xx = m, yy = in[0].ind;
            if(xx == yy) break;

            int fl = 0;
            for(int j = 0; j < in[0].ind; j++)
            {
                if(j == m && !fl) m = n - 1, fl = 1;
                else if( fl ) m--;
                if( v.size() )
                {
                    int x = v[ 0 ];
                    v.erase(v.begin());
                    v.push_back( x );
                }
            }

            if( !fl ) m = xx - yy - 1;
            else m--;
            v.erase(v.begin()); ans++; n--;
            for(int j = 0; j < v.size(); j++) in[j].ind = j, in[j].p = v[ j ];

            if(v.size()) sort(in, in + n, cmp);
            //for(int i = 0; i < v.size(); i++) printf("%d ", v[ i ]); puts("************");
            //printf("%d %d\n", m, in[0].ind);
        }
        ans++;
        printf("%d\n", ans);
        v.clear();
    }
    return 0;
}
