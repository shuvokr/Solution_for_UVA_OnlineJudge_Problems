/*
        Shuvo
        Problem algo: Ad hoc
        Problem ID: 12398
        Problem name: NumPuzz I
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
void reset();
void print();
void valu_fix(char c);
bool isvalid(int x, int y);

int graph[ 3 ][ 3 ], u, v;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, len, kag = 0, a, b;
    char in[ 2002 ];
    bool ck;
    while(gets( in ))
    {
        reset(); ck = true;
        len = strlen( in );
        pf("Case #%d:\n", ++kag);

        fo(i, len)
        {
            if(islower(in[ i ]))
            {
                u = v = - 1;
                valu_fix(in[ i ]);
                if(isvalid(u, v))
                    graph[ u ][ v ] = (graph[ u ][ v ] + 1) % 10;
                fo(j, 4)
                {
                    a = u + diraction1[ j ];
                    b = v + diraction2[ j ];
                    if(isvalid(a, b))
                    {
                        graph[ a ][ b ] = (graph[ a ][ b ] + 1) % 10;
                    }
                }
            }
        }
        print();
    }
}

void reset()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            graph[ i ][ j ] = 0;
}

void print()
{
    for(int i = 0; i < 3; i++)
    {
        pf("%d", graph[ i ][ 0 ]);
        for(int j = 1; j < 3; j++)
        {
            pf(" %d", graph[ i ][ j ]);
        }
        puts("");
    }
}

void valu_fix(char c)
{
    if(c == 'a') u = v = 0;
    else if(c == 'b') u = 0, v = 1;
    else if(c == 'c') u = 0, v = 2;
    else if(c == 'd') u = 1, v = 0;
    else if(c == 'e') u = v = 1;
    else if(c == 'f') u = 1, v = 2;
    else if(c == 'g') u = 2, v = 0;
    else if(c == 'h') u = 2, v = 1;
    else if(c == 'i') u = v = 2;
}

bool isvalid(int x, int y)
{
    if(x == 3 || x < 0 || y == 3 || y < 0) return false;
    return true;
}
