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

int diraction1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diraction2[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char in[ 27 ][ 27 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int row, i, j, col, answer, kag = 0;
    while(sf("%d", &row) != EOF)
    {
        getchar();
        mem(in); fo(i, row) gets(in[ i ]); col = row;
        answer = 0;
        fo(i, row)
            fo(j, col)
                if(in[ i ][ j ] == '1')
                {
                    in[ i ][ j ] = '0';
                    answer++;
                    BFS(i, j);
                }
        pf("Image number %d contains %d war eagles.\n", ++kag, answer);
    }
}
void BFS(int index1, int index2)
{
    int fst, snd, i, j;
    queue < int > Q;
    Q.push( index1 ); Q.push( index2 );
    while(!Q.empty())
    {
        fst = Q.front(); Q.pop(); snd = Q.front(); Q.pop();
        fo(i, 8)
        {
            index1 = fst + diraction1[ i ];
            index2 = snd + diraction2[ i ];

            if(in[ index1 ][ index2 ] == '1')
            {
                in[ index1 ][ index2 ] = '0';
                Q.push( index1 ); Q.push( index2 );
            }
        }
    }
}
