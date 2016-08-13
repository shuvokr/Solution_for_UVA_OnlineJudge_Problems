#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int main()
{
    char name[ 22 ], line[ 1000000 ], *tok;
    int i, tmp, party, value, guess, flag, a, b, tot, kag = 0;
    map <string, double> mapping;
    while(~scanf("%d %d", &party, &guess))
    {
        mapping.clear();
        for(i = 0; i < party; i++)
        {
            scanf("%s %d.%d", name, &a, &b);
            mapping[ name ] = a * 10 + b;
        }
        getchar();
        for(i = 0; i < guess; i++)
        {
            gets( line );
            tok = strtok(line, " +");
            tot = 0;
            while(tok != NULL)
            {
                tot += mapping[ tok ];
                tok = strtok(NULL, " +");
                if(tok[ 0 ] == '=' || tok[ 0 ] == '<' || tok[ 0 ] == '>')
                {
                    if(strlen(tok) == 1)
                    {
                        flag = (tok[ 0 ] == '=') ? 1 :
                            (tok[ 0 ] == '<') ? 2 : 3;
                    }
                    else
                    {
                        flag = (tok[ 0 ] == '<') ? 4 : 5;
                    }
                    break;
                }
            }
            tok = strtok(NULL, " ");
            sscanf(tok, "%d", &a);
            printf("Guess #%d ",++kag);
            if(flag == 1) puts((tot == a * 10) ? "was correct." : "was incorrect.");
            else if(flag == 2) puts((tot < a * 10) ? "was correct." : "was incorrect.");
            else if(flag == 3) puts((tot > a * 10) ? "was correct." : "was incorrect.");
            else if(flag == 4) puts((tot <= a * 10) ? "was correct." : "was incorrect.");
            else if(flag == 5) puts((tot >= a * 10) ? "was correct." : "was incorrect.");
        }
    }
    return 0;
}
