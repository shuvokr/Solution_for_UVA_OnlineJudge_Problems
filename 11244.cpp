#include <stdio.h>
#include <stdlib.h>
/*
        Shuvo
        uva 11244, Problem name : Counting Stars (Add hq)
*/
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
#define maxn 100+2

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int d1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int d2[] = {0, -1, 1, 0, 1, -1, 1, -1};

int input();
bool isvalid(int i, int j);

int col, row;

int main()
{
    input();

    return 0;
}
int input()
{
    int i, j, cou, k;
    char sky[ maxn ][ maxn ];
    bool ck;
    while(sf("%d %d", &row, &col) != EOF)
    {
        if(row + col == 0) return 0;
        getchar();
        fo(i, row) gets( sky[ i ] );
        cou = 0;
        fo(i, row)
        {
            fo(j, col)
            {
                if(sky[ i ][ j ] == '*')
                {
                    ck = true;
                    fo(k, 8)
                    {
                        if(isvalid(i + d1[k], j + d2[k]))
                        if(sky[ i + d1[k] ][ j + d2[k] ] == '*')
                        {
                            ck = false;
                            break;
                        }
                    }
                    if(ck) cou++;
                }
            }
        }
        pf("%d\n", cou);
    }
}
bool isvalid(int i, int j)
{
    if(i == row || i < 0 || j == col || j < 0) return false;
    return true;
}
