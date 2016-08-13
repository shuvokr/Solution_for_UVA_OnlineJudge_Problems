/*
        Shuvo
        Problem algorithm: Sortest path find
        Problem ID: 10986
        Problem name: Sending email
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

#define maxn 20000+10
#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 500000009

typedef pair<int, int> pii;
typedef  vector<int> vi;
typedef vector<pii> vii;

void input();
void Dijkstra( int sorce );

template <class T>
class Heap
{
    T pq[ maxn ];
    int index;

    void sink(int pos)
    {
        int right, left;
        left = pos * 2;
        right = left + 1;
        if( right > index) return;

        if(right < index)
        {
            if(pq[ left ] > pq[ pos ])
            {
                swap(pq[ left ], pq[ pos ]);
                sink( left );
            }
            else if(pq[ right ] > pq[ pos ])
            {
                swap(pq[ right ], pq[ pos ]);
                sink( right );
            }
        }
    }
    void big_top(int pos)
    {
        int parent = pos / 2;
        if(parent < 1) return;
        if(pq[ pos ] > pq[ parent ])
        {
            swap(pq[ parent ], pq[ pos ]);
            big_top( parent );
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
    T top() { return pq[ 1 ]; }
    void pop()
    {
        pq[ 1 ] = pq[ --index ];
        sink( 1 );
    }
    bool empty() { return (index == 1); }
};

struct node
{
    int from, wait;
    node() {}
    node(int a, int wai):from(a), wait(wai) {}
    bool operator<(const node &x) const
    {
        return (wait > x.wait);
    }
    bool operator>(const node &x) const
    {
        return (wait < x.wait);
    }
};

vector <vii> graph;
vi cost;
int row_col, edge, Sor, End;
Heap <node> Q;

int main()
{
    input();

    return 0;
}
void input()
{
    int T, i, j, r, a, b, wai, kag = 0;

    sf("%d", &T);
    while(T--)
    {
        sf("%d %d %d %d", &row_col, &edge, &Sor, &End);
        graph.assign(row_col, vii());

        fo(i, edge)
        {
            sf("%d %d %d", &a, &b, &wai);
            graph[a].push_back(pii(b, wai));
            graph[b].push_back(pii(a, wai));
        }
        Dijkstra( Sor );
        pf("Case #%d: ", ++kag);
        if(cost[ End ] == 500000009) puts("unreachable");
        else pf("%d\n", cost[ End ]);
    }
}
void Dijkstra( int sorce )
{
    int u, v, ww, i;
    cost.assign(row_col, INF);
    cost[ sorce ] = 0;
    Heap <node> Q;
    node ver;
    Q.push(node(sorce, 0));
    while(!Q.empty())
    {
        ver = Q.top();
        Q.pop();
        u = ver.from;
        ww = ver.wait;
        if(cost[ u ] == ww)
        {
            fo(i, graph[u].size())
            {
                pii pr = graph[ u ][ i ];
                //printf("%d %d %d\n", u, pr.first, pr.second);
                if(cost[ u ] + pr.second < cost[ pr.first ])
                {
                    cost[ pr.first ] = cost[ u ] + pr.second;
                    Q.push(node(pr.first, cost[ pr.first ]));
                }
            }
        }
    }
}

