/*
        Shuvo
        uva 10946: Problem name >> You want what filled?
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
#define maxn 50+1

struct aaa
{
    int a;
    char c;
    aaa() {}
    aaa(int x, char z)
    {
        a = x;
        c = z;
    }
};

int row, col, cou;
char graph[ maxn ][ maxn ];

int input();
void DFS(int i, int j, char ch);
bool comper_function(aaa x, aaa y);

int main()
{
    input();

    return 0;
}
int input()
{
    int i, j, k, pro = 0;
    char ch;
    aaa ans[ 2501 ];
    while(sf("%d %d", &row, &col) != EOF)
    {
        if(row + col == 0) return 0;
        getchar(); k = 0;
        fo(i, row) gets( graph[ i ] );

        fo(i, row)
        {
            fo(j, col)
            {
                if(graph[ i ][ j ] != '.')
                {
                    cou = 0;
                    ch = graph[ i ][ j ];
                    DFS(i, j, ch);
                    ans[ k ].a = cou;
                    ans[ k ].c = ch;
                    k++;
                }
            }
        }
        sort(ans, ans + k, comper_function);
        pf("Problem %d:\n", ++pro);
        fo(i, k) pf("%c %d\n", ans[ i ].c, ans[ i ].a );
    }
}
void DFS(int i, int j, char ch)
{
    if(i == row || j == col || i < 0 || j < 0 || graph[ i ][ j ] != ch) return;
    cou++;
    graph[ i ][ j ] = '.';
    DFS(i + 1, j, ch);
    DFS(i - 1, j, ch);
    DFS(i, j + 1, ch);
    DFS(i, j - 1, ch);
}
bool comper_function(aaa x, aaa y)
{
    if(x.a > y.a) return true;
    if(x.a == y.a && x.c < y.c) return true;

    return false;
}
