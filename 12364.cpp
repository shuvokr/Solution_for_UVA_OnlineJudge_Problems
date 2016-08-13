#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    char in[ 4 ][ 300 ], line[ 105 ], ch[ 2 ];
    int D, i;
    while(scanf("%d", &D) && D)
    {
        getchar(); gets( ch );
        string str[ 210 ];
        if(ch[ 0 ] == 'S')
        {
            gets( line );
            int len = strlen( line ), i, r = 0;
            for(i = 0; i < len; i++)
                if(line[ i ] == 48)
                {
                    str[ 0 ] += ".*";
                    str[ 1 ] += "**";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 49)
                {
                    str[ 0 ] += "*.";
                    str[ 1 ] += "..";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 50)
                {
                    str[ 0 ] += "*.";
                    str[ 1 ] += "*.";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 51)
                {
                    str[ 0 ] += "**";
                    str[ 1 ] += "..";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 52)
                {
                    str[ 0 ] += "**";
                    str[ 1 ] += ".*";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 53)
                {
                    str[ 0 ] += "*.";
                    str[ 1 ] += ".*";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 54)
                {
                    str[ 0 ] += "**";
                    str[ 1 ] += "*.";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 55)
                {
                    str[ 0 ] += "**";
                    str[ 1 ] += "**";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 56)
                {
                    str[ 0 ] += "*.";
                    str[ 1 ] += "**";
                    str[ 2 ] += "..";
                }
                else if(line[ i ] == 57)
                {
                    str[ 0 ] += ".*";
                    str[ 1 ] += "*.";
                    str[ 2 ] += "..";
                }
                else
                {
                    str[ 0 ] += ".*";
                    str[ 1 ] += "**";
                    str[ 2 ] += "..";
                }
            for(i = 0; i < 3; i++)
            {
                printf("%c%c", str[ i ][ 0 ], str[ i ][ 1 ]);
                for(int j = 2; j < str[ i ].size(); j += 2)
                    printf(" %c%c", str[ i ][ j ], str[ i ][j + 1]);
                puts("");
            }
        }
        else
        {
            int k = 0, cou = 0;
            for(i = 0; i < 3; i++) gets(in[ i ]);
            for(i = 0; i < D; i++)
            {
                if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '.' && in[ 1 ][ k ] == '.' && in[ 1 ][k + 1] == '.' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '1';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '.' && in[ 1 ][ k ] == '*' && in[ 1 ][k + 1] == '.' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '2';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '*' && in[ 1 ][ k ] == '.' && in[ 1 ][k + 1] == '.' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '3';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '*' && in[ 1 ][ k ] == '.' && in[ 1 ][k + 1] == '*' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '4';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '.' && in[ 1 ][ k ] == '.' && in[ 1 ][k + 1] == '*' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '5';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '*' && in[ 1 ][ k ] == '*' && in[ 1 ][k + 1] == '.' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '6';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '*' && in[ 1 ][ k ] == '*' && in[ 1 ][k + 1] == '*' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '7';
                else if(in[ 0 ][ k ] == '*' && in[ 0 ][k + 1] == '.' && in[ 1 ][ k ] == '*' && in[ 1 ][k + 1] == '*' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '8';
                else if(in[ 0 ][ k ] == '.' && in[ 0 ][k + 1] == '*' && in[ 1 ][ k ] == '*' && in[ 1 ][k + 1] == '.' && in[ 2 ][ k ] == '.' && in[ 2 ][k + 1] == '.') line[ cou ] = '9';
                else  line[ cou ] = '0';
                cou++; k += 3;
            }
            line[ cou ] = NULL;
            puts(line);
        }
    }
    return 0;
}
