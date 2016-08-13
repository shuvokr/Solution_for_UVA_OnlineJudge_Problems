#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char in[ 250 ], *tok;
    int len, i, cou;
    double tot;
    while( gets( in ) )
    {
        if( in[ 0 ] == '*' ) break;
        cou = 0;
        tok = strtok(in, "/");
        while( tok != NULL )
        {
            tot = 0.00;
            len = strlen( tok );
            for(i = 0; i < len; i++)
            {
                tot += tok[ i ] == 'W' ? 1.0 :
                    tok[ i ] == 'H' ? 0.5 :
                        tok[ i ] == 'Q' ? 0.25 :
                            tok[ i ] == 'E' ? 0.125 :
                                tok[ i ] == 'S' ? 0.0625 :
                                    tok[ i ] == 'T' ? 0.03125 : 0.015625;
            }
            if(tot == 1.0) cou++;
            tok = strtok(NULL, "/");
        }
        printf("%d\n", cou);
    }
    return 0;
}
