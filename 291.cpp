#include <cstdio>
void backtrack();

bool M[ 6 ][ 6 ], mark[ 6 ][ 6 ];
char ans[ 9 ];
int cou;

int main()
{
    for(int i = 1; i < 6; i++)
        for(int j = 1; j < 6; j++)
            mark[ i ][ j ] = M[ i ][ j ] = false;

    M[ 1 ][ 2 ] = M[ 1 ][ 3 ] = M[ 1 ][ 5 ] = M[ 2 ][ 1 ] = M[ 2 ][ 3 ] = M[ 2 ][ 5 ] = M[ 3 ][ 1 ] = M[ 3 ][ 2 ] = M[ 3 ][ 4 ] = M[ 3 ][ 5 ] = M[ 4 ][ 3 ] = M[ 4 ][ 5 ] = M[ 5 ][ 1 ] = M[ 5 ][ 2 ] = M[ 5 ][ 3 ] = M[ 5 ][ 4 ] = true;

    cou = 0;
    ans[ 0 ] = 49;
    ans[ 8 ] = NULL;
    backtrack();

    return 0;
}
void backtrack()
{
    if(cou == 8)
    {
        puts( ans );
        return ;
    }
    for(int i = 1; i < 6; i++)
        if(M[ ans[ cou ] - 48 ][ i ] && !mark[ ans[ cou ] - 48 ][ i ])
        {
            mark[ ans[ cou ] - 48 ][ i ] = mark[ i ][ ans[ cou ] - 48 ] = true;
            ans[ ++cou ] = i + 48;

            backtrack();

            cou--;
            mark[ ans[ cou ] - 48 ][ i ] = mark[ i ][ ans[ cou ] - 48 ] = false;
        }
}
