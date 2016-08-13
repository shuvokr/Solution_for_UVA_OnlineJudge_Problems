#include <cstdio>
const int MAX = 200010;
struct X
{
    int sum;
}stree[MAX * 4], ans;

void init(int node, int b, int e);
void marge(X &p, X &l, X &r);
void update(int node, int b, int e);
void query(int node, int b, int e);

int in[ MAX ], n, a, bb;
char com[ 5 ];

int main()
{
    int kag = 0, i;
    bool space = false;
    while(~scanf("%d", &n) && n)
    {
        if( space ) puts("");
        else space = true;
        printf("Case %d:\n", ++kag);
        for(i = 0; i < n; i++) scanf("%d", &in[ i ]);

        init(1, 0, n - 1);

        while(scanf("%s", com) && com[ 0 ] != 'E')
        {
            scanf("%d %d", &a, &bb); a--;
            if(com[ 0 ] == 'S')
                update(1, 0, n - 1);
            else
            {
                bb--; ans.sum = 0;
                query(1, 0, n - 1);
                printf("%d\n", ans.sum);
            }
        }
    }
    return 0;
}
void init(int node, int b, int e)
{
    if(b == e) { stree[ node ].sum = in[ b ]; return ; }

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    init(left, b, mid);
    init(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void marge(X &p, X &l, X &r)
{
    p.sum = l.sum + r.sum;
}
void update(int node, int b, int e)
{
    if(b > a || e < a) return ;

    if(b == e)
    {
        if(b == a) stree[ node ].sum = bb;
        return ;
    }
    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    update(left, b, mid);
    update(right, mid + 1, e);

    marge(stree[ node ], stree[ left ], stree[ right ]);
}
void query(int node, int b, int e)
{
    if(b > bb || e < a) return ;

    if(b >= a && e <= bb)
    {
        marge(ans, ans, stree[ node ]);
        return;
    }

    int left = node << 1, right = left + 1, mid = (b + e) >> 1;

    query(left, b, mid);
    query(right, mid + 1, e);
}
