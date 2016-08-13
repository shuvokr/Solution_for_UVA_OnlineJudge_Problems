#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf
#define fo(i, n) for(i = 0; i < n; i++)
#define mem(n) memset(n, 0, sizeof(n))

void input();
void BFS(int index1, int index2);

char in[ 102 ][ 102 ];
int row, col;
int diraction1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diraction2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, answer;
    while(sf("%d %d", &row, &col) != EOF)
    {
        if(row + col == 0) break;
        getchar(); answer = 0; mem(in);
        fo(i, row) gets(in[ i ]);
        fo(i, row)
            fo(j, col)
                if(in[ i ][ j ] == '@')
                {
                    answer++; BFS(i, j);
                }
        pf("%d\n", answer);
    }
}
void BFS(int index1, int index2)
{
    int i, tmp1, tmp2;
    queue < int > Q;
    Q.push( index1 ); Q.push( index2 );
    while(!Q.empty())
    {
        tmp1 = Q.front(); Q.pop(); tmp2 = Q.front(); Q.pop();
        fo(i, 8)
        {
            index1 = tmp1 + diraction1[ i ];
            index2 = tmp2 + diraction2[ i ];

            if(in[ index1 ][ index2 ] == '@')
            {
                in[ index1 ][ index2 ] = '*';
                Q.push( index1 ); Q.push( index2 );
            }
        }
    }
}

