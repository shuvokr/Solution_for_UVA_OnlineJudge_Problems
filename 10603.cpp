/*
    Shuvo
    Problem algorithm: Sortest path find
    Problem ID: 10603
    Problem name: Fill
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 1e9
#define maxn 200+10

#define purAtoB 1
#define purAtoC 2
#define purAtoBC 3
#define purAtoCB 4
#define purBtoA 5
#define purBtoC 6
#define purBtoAC 7
#define purBtoCA 8
#define purCtoA 9
#define purCtoB 10
#define purCtoAB 11
#define purCtoBA 12

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

template <class T>
class Heap
{
    T pq[ maxn ];
    int index;

    void big_top(int pos)
    {
        int parent = pos / 2;
        if(parent < 1) return;
        if(pq[ parent ] < pq[ pos ])
        {
            swap(pq[ pos ], pq[ parent ]);
            big_top( pos );
        }
    }
    void sink(int pos)
    {
        int left = pos * 2, right = left + 1;
        if(right > index) return;
        if(right < index)
        {
            if(pq[ pos ] < pq[ left ])
            {
                swap(pq[ pos ], pq[ left ]);
                sink( left );
            }
            else if(pq[ pos ] < pq[ right ])
            {
                swap(pq[ pos ], pq[ right ]);
                sink( right );
            }
        }
    }
    public:
    Heap() {index = 1;}
    void push(T n)
    {
        pq[ index ] = n;
        big_top( index );
        index++;
    }
    T top() {return pq[ 1 ];}
    void pop()
    {
        pq[ 1 ] = pq[ --index ];
        sink( 1 );
    }
    bool empty() {return (index == 1);}
};

struct node
{
    int nd, wi;
    node() {}
    node(int a, int w):nd(a), wi(w) {}
    bool operator<(const node &x) const
    {
        return (wi < x.wi);
    }
};

//****************************************************************************************

void input();
int BFS(int index1, int index2, int s);
void update(int a, int b, int c, int st);

bool mark[ maxn ][ maxn ][ maxn ];
int total_pour_water, max_res, markp, markr;

int ca, cb, cc, N;
struct state
{
    int a, b, c;
    state() {}
    state(int x, int y, int z):a(x),b(y),c(z) {}
    state(const state &n):a(n.a),b(n.b),c(n.c) {}
};
struct sta
{
    int a, b, c;
    sta() {}
    //sta(int x, int y):a(x),b(y) {}
    //sta(const state &n):a(n.a),b(n.b) {}
    sta(int x, int y)
    {
        a = x; b = y;
    }
};

sta path[ 10000 ];

state pourCtoA(int a, int b, int c)
{
    int aa = a;
    a += c;
    if(a > ca)
    {
        c = a - ca;
        a = ca;
    }
    else c = 0;

    total_pour_water = (a - aa);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}
state pourCtoB(int a, int b, int c)
{
    int bb = b;
    b += c;
    if(b > cb)
    {
        c = b - cb;
        b = cb;
    }
    else c = 0;

    total_pour_water = (b - bb);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}

state pourAtoB(int a, int b, int c)
{
    int bb = b;
    b += a;
    if(b > cb)
    {
        a = b - cb;
        b = cb;
    }
    else a = 0;

    total_pour_water = (b - bb);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}
state pourAtoC(int a, int b, int c)
{
    int ccc = c;
    c += a;
    if(c > cc)
    {
        a = c - cc;
        c = cc;
    }
    else a = 0;

    total_pour_water = (c - ccc);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}

state pourBtoA(int a, int b, int c)
{
    int aa = a;
    a += b;
    if(a > ca)
    {
        b = a - ca;
        a = ca;
    }
    else b = 0;

    total_pour_water = (a - aa);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}
state pourBtoC(int a, int b, int c)
{
    int ccc = c;
    c += b;
    if(c > cc)
    {
        b = c - cc;
        c = cc;
    }
    else b = 0;

    total_pour_water = (c - ccc);
    state xx;
    xx.a = a; xx.b = b; xx.c = c;
    return xx;
}
int stat;
int main()
{
    input();

    return 0;
}
void input()
{
    int res, T;
    int ans = 0;
    sf("%d", &T);
    while(T--)
    {
        total_pour_water = 0; max_res = -1;
        sf("%d %d %d %d", &ca, &cb, &cc, &N);
        markr = -1;
        res = BFS(0, 0, cc);
        ans = 0;

        if(res == N)
        {
            while(stat > 0)
            {
                ans += path[stat].b;
                stat = path[stat].a;
            }

            pf("%d %d\n", ans, res);
        }
        else
        {
            stat = markp;
            while(stat > 0)
            {
                ans += path[stat].b;
                stat = path[stat].a;
            }
            //puts("cheak");
            pf("%d %d\n", ans, markr);
        }
    }
}
int BFS(int index1, int index2, int s)
{
    //pf("Start\n");
    int wa, wb, wc, i, j, k, kk = -1;
    stat = 0;
    state in, var, tmp;
    in.a = index1;
    in.b = index2;
    in.c = s;
    queue <state> Q;
    Q.push( in );
    for(i = 0; i < maxn; i++)
        for(j = 0; j < maxn; j++)
            for(k = 0; k < maxn; k++)
                mark[ i ][ j ][ k ] = true;

    path[ 0 ].a = kk;
    path[ 0 ].b = 0;

    while(!Q.empty())
    {
        //pf("Queue start\n");
        ++kk;
        var = Q.front(); Q.pop();
        wa = var.a;
        wb = var.b;
        wc = var.c;
        if(mark[ wa ][ wb ][ wc ])
        {
            mark[ wa ][ wb ][ wc ] = false;
            if(wc <= cc && wc > 0)
            {
                if(wa < ca)
                {
                    tmp = pourCtoA(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    //pf("%d %d %d\n", tmp.a, tmp.b, tmp.c);
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wb < cb)
                {
                    tmp = pourCtoB(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[ stat ].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wa < ca && wb < cb)
                {
                    tmp = pourCtoA(wa, wb, wc);
                    tmp = pourCtoB(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                    tmp = pourCtoB(wa, wb, wc);
                    tmp = pourCtoA(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
            }

            if(wb <= cb && wb > 0)
            {
                if(wa < ca)
                {
                    tmp = pourBtoA(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wc < cc)
                {
                    tmp = pourBtoC(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wa < ca && wc < cc)
                {
                    tmp = pourBtoA(wa, wb, wc);
                    tmp = pourBtoC(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                    tmp = pourBtoC(wa, wb, wc);
                    tmp = pourBtoA(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
            }

            if(wa <= ca && wa > 0)
            {
                if(wb < cb)
                {
                    tmp = pourAtoB(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wc < cc)
                {
                    tmp = pourAtoC(wa, wb, wc);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
                if(wb < cb && wc < cc)
                {
                    tmp = pourAtoB(wa, wb, wc);
                    tmp = pourAtoC(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;

                    tmp = pourAtoC(wa, wb, wc);
                    tmp = pourAtoB(tmp.a, tmp.b, tmp.c);
                    stat++;
                    update(tmp.a, tmp.b, tmp.c,  stat);
                    path[ stat ].a = kk;
                    path[stat].b = total_pour_water;

                    if(tmp.a == N || tmp.b == N || tmp.c == N) return N;
                    Q.push( tmp );
                    if(tmp.a == N || tmp.b == N || tmp.c == N) return 0;
                }
            }
        }
    }
    //puts("END");
    return 0;
}
void update(int a, int b, int c, int st)
{
    if(a > markr && a < N) markr = a, markp = st;
    if(b > markr && a < N) markr = b, markp = st;
    if(c > markr && c < N) markr = c, markp = st;
}
