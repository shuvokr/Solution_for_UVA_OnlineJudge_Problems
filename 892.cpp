#include <iostream>
#include <cstdio>
#include <ctype.h>
using namespace std;
int main()
{
    string line, tmp = "";
    bool next = false;
    while(getline(cin, line))
    {
        if(line == "#")
            break;
        int i, len = line.length();
        for(i = 0; i < len; i++)
        {
            if(isspace(line[i]))
            {
                cout << tmp;
                if( next )
                    puts("");
                printf("%c", line[ i ]);
                next = false;
                tmp = "";
            }
            else if(isalpha(line[i])) tmp += line[ i ];
            else
            {
                if(line[ i ] == '-')
                    if(tmp.length() > 0 && i == len-1) next = true;
                else
                {
                    cout << tmp;
                    tmp = "";
                    if( next )
                        puts("");
                    next = false;
                }
            }
        }
        if( !next )
        {
            cout << tmp;
            if( next )
                puts("");
            tmp = "";
        }
        puts("");
    }
    return 0;
}
