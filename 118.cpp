#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))

void input();
void procage(char sk);

int row, col, x, y;
bool mark[ 55 ][ 55 ], last;
char ck;

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, tmp;
    char in[ 110 ];
    fo(i, 55) fo(j, 55) mark[ i ][ j ] = false;
    sf("%d %d", &col, &row);
    while(sf("%d %d %c", &x, &y, &ck) != EOF)
    {
        sf("%s", in);
        last = false;
        for(i = 0; in[ i ] && !last; i++) procage( in[ i ] );
        if ( !last )
            pf("%d %d %c\n", x, y, ck);
    }
}
void procage(char sk)
{
    if (ck == 'S' && sk == 'R') ck = 'W';
    else if (ck == 'S' && sk == 'L') ck= 'E';
    else if (ck == 'N' && sk == 'R') ck= 'E';
    else if (ck == 'N' && sk == 'L') ck = 'W';
    else if (ck == 'E' && sk == 'R') ck = 'S';
    else if (ck == 'E' && sk == 'L') ck = 'N';
    else if (ck == 'W' && sk == 'R') ck= 'N';
    else if (ck == 'W' && sk == 'L') ck= 'S';

    if(sk == 'F')
    {
        switch ( ck )
        {
        case 'N':
            {
                if (row == y && mark[ x ][ y ]) break;
                else if (row == y && !mark[ x ][ y ])
                {
                    mark[ x ][ y ] = true;
                    pf ("%d %d %c LOST\n", x, y, ck);
                    last = true;
                    break;
                }
                y++;
                break;
            }
        case 'S':
            if (y == 0 && mark[ x ][ y ]) break;
            else if (y == 0 && !mark[ x ][ y ])
            {
                mark[ x ][ y ] = true;
                pf("%d %d %c LOST\n", x, y, ck);
                last = true;
                break;
            }
            y--;
            break;
        case 'E':
            if (col == x && mark[ x ][ y ]) break;
            else if ( col == x && !mark[ x ][ y ])
            {
                mark[ x ][ y ] = true;
                pf("%d %d %c LOST\n", x, y, ck);
                last = true;
                break;
            }
            x++;
            break;
        case 'W':
            if (x == 0 && mark[ x ][ y ]) break;
            else if (x == 0 && !mark[ x ][ y ])
            {
                mark[ x ][ y ] = true;
                pf("%d %d %c LOST\n", x, y, ck);
                last = true;
                break;
            }
            x--;
        }
    }
}

