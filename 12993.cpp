#include <stdio.h>
#include <queue>
using namespace std;
int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};

void BFS(int x, int y);

struct data
{
    int a, b;
}p[ 4005 ];

int r, c, cost[ 105 ][ 105 ], k1, k2;
char in[ 105 ][ 105 ], s[ 105 ][ 105 ];

int main()
{
    int kag = 0, ans, ind;
    while(scanf("%d %d", &r, &c) && (r || c))
    {
        getchar(); k1 = k2 = 0;
        for(int i = 0; i < r; i++)
        {
            gets( s[ i ] );
            for(int j = 0; j < c; j++) k1 += (s[ i ][ j ] == '#');
        }
        ind = 0;
        for(int i = 0; i < r; i++)
        {
            gets( in[ i ] );
            for(int j = 0; j < c; j++)
            {
                cost[ i ][ j ] = 1000000007;
                if(in[ i ][ j ] == '#') k2++, p[ind].a = i, p[ind].b = j, ind++;
            }
        }
        ans = k1 != k2 ? 1 : 0;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(s[ i ][ j ] == '#')
                {
                    k1++; BFS(i, j);
                    i = r; j = c;
                }
        for(int i = 0; i < ind; i++) ans = ans < cost[ p[i].a ][ p[i].b ] ? cost[ p[i].a ][ p[i].b ] : ans;
        printf("Case %d: %d\n", ++kag, ans);
    }
    return 0;
}
void BFS(int x, int y)
{
    s[ x ][ y ] = '.';
    cost[ x ][ y ] = 0;
    queue <int> Q;
    Q.push( x ); Q.push( y );
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        y = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int a = x + diraction1[ i ];
            int b = y + diraction2[ i ];
            if(a < 0 || a >= r || b < 0 || b >= c) continue;
            if(s[ a ][ b ] == '#')
            {
                k1++;
                cost[ a ][ b ] = 0;
                s[ a ][ b ] = '.';
                Q.push( a ); Q.push( b );
            }
            else if(cost[ a ][ b ] > cost[ x ][ y ] + 1)
            {
                cost[ a ][ b ] = cost[ x ][ y ] + 1;
                Q.push( a ); Q.push( b );
            }
        }
    }
}

