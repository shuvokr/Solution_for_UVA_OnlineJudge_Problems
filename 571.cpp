/*
        Shuvo
        uva 571: Problem name >> Jugs
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
#define maxn 10000+10

#define filA 1
#define filB 2
#define emtA 3
#define emtB 4
#define purAB 5
#define purBA 6

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

bool mark[ maxn ][ maxn ];
int stat;

int ca, cb, N;
struct state
{
    int a, b, c;
    state() {}
    state(int x, int y, int z):a(x),b(y),c(z) {}
    state(const state &n):a(n.a),b(n.b),c(n.c) {}
};

struct sta
{
    int a, b;
    sta() {}
    sta(int x, int y):a(x),b(y) {}
    sta(const state &n):a(n.a),b(n.b) {}
};

int fillA() { return ca; }
int fillB() { return cb; }
sta pourAtoB(int na, int mb)
{
    state sk;
    mb += na;
    if(mb > cb)
    {
        sk.b = cb;
        sk.a = mb - cb;
    }
    else
    {
        sk.a = 0;
        sk.b = mb;
    }
    return sk;
}

sta path[ maxn ];

sta pourBtoA(int na, int mb)
{
    state sk;
    na += mb;
    if(na > ca)
    {
        sk.a = ca;
        sk.b = na - ca;
    }
    else
    {
        sk.a = na;
        sk.b = 0;
    }
    return sk;
}
int emptyA() { return 0; }
int emptyB() { return 0; }

int main()
{
    input();

    return 0;
}
void input()
{
    int res, i, ans[ maxn ], cou;
    while(sf("%d %d %d", &ca, &cb, &N) != EOF)
    {
        res = BFS(0, 0, 0);
        cou = 0;
        while(stat > 0)
        {
            ans[ cou++ ] = path[stat].b;
            stat = path[stat].a;
        }
        for(i = cou - 1; i >= 0; i--)
        {
            if(ans[ i ] == filA) puts("fill A");
            if(ans[ i ] == filB) puts("fill B");
            if(ans[ i ] == emtA) puts("empty A");
            if(ans[ i ] == emtB) puts("empty B");
            if(ans[ i ] == purAB) puts("pour A B");
            if(ans[ i ] == purBA) puts("pour B A");
        }
        puts("success");
    }
}
int BFS(int index1, int index2, int s)
{
    stat = s;
    int wa, wb, i, j, a, b, k = -1;
    state in, var;
    sta xxx;
    in.a = index1;
    in.b = index2;
    in.c = stat++;
    queue <state> Q;
    Q.push( in );
    for(i = 0; i < 1001; i++)
        for(j = 0; j < 1001; j++)
            mark[ i ][ j ] = true;

    path[ 0 ].a = k;
    path[ 0 ].b = 0;

    while(!Q.empty())
    {
        ++k;
        var = Q.front(); Q.pop();
        wa = var.a;
        wb = var.b;
        if(wb == N) return wb;
        if(mark[ wa ][ wb ])
        {
            mark[ wa ][ wb ] = false;

            if(wa > 0)
            {
                a = emptyA();
                path[ stat ].a = k;
                path[stat].b = emtA;
                in.a = a; in.b = wb; in.c = stat++; Q.push( in );
            }
            if(wb > 0)
            {
                b = emptyB();
                path[stat].a = k;
                path[stat].b = emtB;
                if(b == N) return b;
                in.a = wa; in.b = b; in.c = stat++; Q.push( in );
            }
            if(wa < ca)
            {
                a = fillA();
                path[stat].a = k;
                path[stat].b = filA;
                in.a = a; in.b = wb; in.c = stat++; Q.push( in );
            }
            if(wb < cb)
            {
                b = fillB();
                path[stat].a = k;
                path[stat].b = filB;
                if(b == N) return b;
                in.a = wa; in.b = b; in.c = stat++; Q.push( in );
            }
            if(wa > 0 && wb < cb)
            {
                xxx = pourAtoB(wa, wb);
                path[stat].a = k;
                path[stat].b = purAB;
                if(xxx.b == N) return xxx.b;
                in.a = xxx.a; in.b = xxx.b; in.c = stat++;
                Q.push( in );
            }
            if(wb > 0 && wa < ca)
            {
                xxx = pourBtoA(wa, wb);
                path[stat].a = k;
                path[stat].b = purBA;
                if(xxx.b == N) return xxx.b;
                in.a = xxx.a; in.b = xxx.b; in.c = stat++;
                Q.push( in );
            }
        }
    }
    return 0;
}
