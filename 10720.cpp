/*
        Shuvo
        Problem Algo: Havel-Hakimi algorithm(http://salimsazzad.wordpress.com/2011/07/31/construction-of-graph-from-degree-sequence/)
        Problem ID: 10720
        Problem name: Graph Construction
*/
#include <stdio.h>
#include <string.h>

using namespace std;

bool Havel_Hakimi(int start);
void sort(int s);
bool nagativ(int s);
bool zero( int s );

int stor[ 10000 ], n;

void print(int s)
{
    for(int i = s; i < n; i++) printf("%d ", stor[ i ]);
    printf("\n");
}

int main()
{
    //freopen("output.txt", "w", stdout);
    int tmp, i, start, cou;
    bool mark;
    while(scanf("%d", &n) && n)
    {
        cou = i = 0; mark = true;
        for(; i < n; i++)
        {
            scanf("%d", &stor[ i ]);
            if(stor[ i ] > n - 1) mark = false;
            if(stor[ i ] % 2 != 0) cou++;
        }
        if(cou % 2 != 0 || !mark) puts("Not possible");
        else
        {
            if(Havel_Hakimi(0)) puts("Possible");
            else puts("Not possible");
        }
    }
    return 0;
}
bool Havel_Hakimi(int start)
{
    //print(start);
    if( nagativ(start) ) return false;
    if( zero(start) ) return true;
    sort(start);
    for(int i = start + 1; i < stor[ start ] + start + 1; i++)
        stor[ i ] -= 1;

    Havel_Hakimi(start + 1);
}
void sort(int s)
{
    int i, j, tmp;
    for(i = s; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(stor[ j ] > stor[ i ])
            {
                tmp = stor[ i ];
                stor[ i ] = stor[ j ];
                stor[ j ] = tmp;
            }
}
bool nagativ(int s)
{
    for(int i = s; i < n; i++)
        if(stor[ i ] < 0 ) return true;
    return false;
}
bool zero(int s)
{
    for(int i = s; i < n; i++)
        if(stor[ i ] != 0) return false;
    return true;
}
