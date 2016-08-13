#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int isok(int r, int c);
bool isokk(int r, int c);

char board[ 5 ][ 7 ];
bool mrk[ 5 ][ 7 ];
int mark[ 5 ][ 7 ], ar[ 20 ], ind;
int n, maxres;

int main()
{
    while(scanf("%d", &n) && n)
    {
        getchar();
        memset(mark, 0, sizeof mark);
        memset(mrk, true, sizeof mrk);
        for(int i = 0; i < n; i++) gets( board[ i ]);
        ind = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mark[ i ][ j ] = isok(i, j), ar[ ind++ ] = mark[ i ][ j ];
        sort(ar, ar + ind); maxres = 0;
        for(int i = 0; i < ind; i++)
        {
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    if(mark[ j ][ k ] == ar[ i ] && isokk(j, k))
                    {
                        mrk[ j ][ k ] = false;
                        maxres++;
                    }
        }
        printf("%d\n", maxres);
    }
    return 0;
}
int isok(int r, int c)
{
    int ret = 0;
    if(board[ r ][ c ] == 'X') return 1 << 29;
    int a = r, b = c;
    while( true )
    {
        if(board[ a ][ b ] == 'X') break;
        ret++;
        b--; if(b < 0) break;
    }

    a = r, b = c;
    while( true )
    {
        if(board[ a ][ b ] == 'X') break;
        ret++;
        b++; if(b == n) break;
    }

    a = r, b = c;
    while( true )
    {
        if(board[ a ][ b ] == 'X') break;
        ret++;
        a--; if(a < 0) break;
    }

    a = r, b = c;
    while( true )
    {
        if(board[ a ][ b ] == 'X') break;
        ret++;
        a++; if(a == n) break;
    }
    return ret;
}
bool isokk(int r, int c)
{
    if(board[ r ][ c ] == 'X') return false;
    int a = r, b = c;
    while( true )
    {
        if(mrk[ a ][ b ] == false) return false;
        if(board[ a ][ b ] == 'X') break;
        b--; if(b < 0) break;
    }

    a = r, b = c;
    while( true )
    {
        if(mrk[ a ][ b ] == false) return false;
        if(board[ a ][ b ] == 'X') break;
        b++; if(b == n) break;
    }

    a = r, b = c;
    while( true )
    {
        if(mrk[ a ][ b ] == false) return false;
        if(board[ a ][ b ] == 'X') break;
        a--; if(a < 0) break;
    }

    a = r, b = c;
    while( true )
    {
        if(mrk[ a ][ b ] == false) return false;
        if(board[ a ][ b ] == 'X') break;
        a++; if(a == n) break;
    }
    return true;
}

