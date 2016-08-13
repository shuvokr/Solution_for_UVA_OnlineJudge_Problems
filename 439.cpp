/*
        Shuvo
        Problem algo: BFS
        Problem ID: 439
        Problem name: Knight move
*/
//Templet start
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
#define INF 5000
#define pb push_back
#define maxn 200000+2

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
int DFS(int index1, int index2);
bool isvalid(int a, int b);

int x, y, fx, fy, cost[ 8 ][ 8 ];
bool ck, mark[ 8 ][ 8 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j;
    char in1[ 3 ], in2[ 3 ];
    while(sf("%s %s", in1, in2) != EOF)
    {
        x = in1[ 0 ] - 97;
        y = (in1[ 1 ] - '0') - 1;
        fx = in2[ 0 ] - 97;
        fy = (in2[ 1 ] - '0') - 1;
        mem(mark, true);
        ck = true;
        pf("To get from %s to %s takes %d knight moves.\n", in1, in2, DFS(x, y));
    }
}
int DFS(int index1, int index2)
{
    int i, j, tmp1, tmp2;
    queue <int> Q;
    Q.push( index1 ); Q.push( index2 );
    mark[ index1 ][ index2 ] = false;
    cost[ index1 ][ index2 ] = 0;
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop();
        tmp2 = Q.front(); Q.pop();
        fo(i, 8)
        {
            index1 = tmp1 + horsed1[ i ];
            index2 = tmp2 + horsed2[ i ];
            if(isvalid(index1, index2))
            {
                mark[ index1 ][ index2 ] = false;
                cost[ index1 ][ index2 ] = cost[ tmp1 ][ tmp2 ] + 1;
                if(index1 == fx && index2 == fy) return cost[ index1 ][ index2 ];
                Q.push( index1 ); Q.push( index2 );
            }
        }
    }
    return 0;
}
bool isvalid(int a, int b)
{
    if(a > 7 || b > 7 || a < 0 || b < 0 || !mark[ a ][ b ]) return false;
    return true;
}
