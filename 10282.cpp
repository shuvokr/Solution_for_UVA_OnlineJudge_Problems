#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map <string, string> dictionary;
    char in[ 100000 ], *tok1, *tok2;
    while( gets( in ) )
    {
        if(in[ 0 ] == NULL) break;
        tok1 = strtok(in, " ");
        tok2 = strtok(NULL, " ");
        dictionary[ tok2 ] = tok1;
    }

    while( gets( in ) )
    {
        if(in[ 0 ] == NULL) break;
        if(dictionary[ in ] == "") puts("eh");
        else cout << dictionary[ in ] << endl;
    }

    return 0;
}
