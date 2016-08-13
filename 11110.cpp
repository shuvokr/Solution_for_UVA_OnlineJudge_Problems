/*
        Shuvo
        Problen algo: DFS
        Problem ID: 11110
        Problem name: Equidivisions
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
#define fo(i, n) for(i = 1; i <= n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 100+2
#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void DFS(int x, int y);
bool isvalid(int x, int y);
void print();
void call_DFS();
void cheak_result();
void make_graph(char in[], int i);

int graph[ maxn ][ maxn ], node, mark, cou;
bool ck;

int main()
{
    input();

    return 0;
}

void input()
{
    int i, j, k;
    char in[ 1000 ];
    while(sf("%d", &node) != EOF)
    {
        if(node == 0) break;
        fo(i, node)
            fo(j, node) graph[ i ][ j ] = node;
        getchar();
        fo(i, node - 1)
        {
            gets(in);
            make_graph(in, i);
        }
        //print();
        if(node == 1)
        {
            puts("good");
            continue;
        }
        call_DFS();
        if(!ck) puts("wrong");
        else
        {
            cheak_result();
            if(ck) puts("good");
            else puts("wrong");
        }
    }
}

void DFS(int x, int y)
{
    graph[ x ][ y ] = -1;
    for(int i = 0; i < 4; i++)
    {
        int tmp1, tmp2;
        tmp1 = x + diraction1[ i ];
        tmp2 = y + diraction2[ i ];
        if(isvalid(tmp1, tmp2))
        if(graph[ tmp1 ][ tmp2 ] == mark) DFS( tmp1, tmp2 ), cou++;
    }
}

bool isvalid(int x, int y)
{
    if(x == node + 1 || x == 0 || y == node + 1 || y == 0 || graph[ x ][ y ] != mark) return false;
    return true;
}

void print()
{
    int i, j;
    fo(i, node)
    {
        fo(j, node)
        {
            pf("%d ", graph[ i ][ j ]);
        }
        puts("");
    }
}

void call_DFS()
{
    int i, j, k;
    ck = true;
    fo(i, node)
    {
        fo(j, node)
        {
            fo(k, node)
            {
                if(graph[ j ][ k ] == i)
                {
                    mark = i;
                    cou = 1;
                    DFS(j, k);
                    j = k = node + 1;
                    if(cou == 1)
                    {
                        ck = false;
                        i = j = k = node + 1;
                    }
                }
            }
        }
    }
}

void cheak_result()
{
    int i, j;
    ck = true;
    fo(i, node)
    {
        fo(j, node)
        {
            if(graph[ i ][ j ] != -1)
            {
                ck = false;
                i = j = node + 1;
            }
        }
    }
}

void make_graph(char in[], int i)
{
    int j, u, v, k, len;
    char ch[ 5 ];
    len = strlen( in );
    for(j = 0; j < len ; )
    {
        mem(ch, 0); k = 0;
        while(isdigit(in[ j ]))
        {
            ch[ k++ ] = in[ j++ ];
        }
        sscanf(ch, "%d", &u);
        j++;
        mem(ch, 0); k = 0;
        while(isdigit(in[ j ]))
        {
            ch[ k++ ] = in[ j++ ];
        }
        sscanf(ch, "%d", &v);
        j++;
        graph[ u ][ v ] = i;
    }
}
