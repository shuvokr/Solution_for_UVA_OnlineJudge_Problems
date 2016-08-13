/*
        Shuvo
        Problem algo: Simple Ad hoc
        Problem ID: 10789
        Problem name: Prime Frequency
*/
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int T, kag = 0, i, j, len, res[ 124 ];
    bool prime[ 2000 ], ck;

    prime[ 0 ] = false;
    prime[ 1 ] = false;
    prime[ 2 ] = true;
    for(i = 4; i < 2000; i += 2) prime[ i ] = false;
    for(i = 3; i < 2000; i += 2) prime[ i ] = true;

    for(i = 3; i < 45; i += 2)
        for(j = i * i; j < 2000; j += i)
            prime[ j ] = false;

    char in[ 2002 ];
    scanf("%d", &T); getchar();
    while(T--)
    {
        gets( in );
        len = strlen( in );
        for(i = 48; i < 58; i++) res[ i ] = 0;
        for(i = 65; i < 91; i++) res[ i ] = 0;
        for(i = 97; i < 123; i++) res[ i ] = 0;
        for(i = 0; i < len; i++)
        {
            res[ in[ i ] ]++;
        }
        printf("Case %d: ", ++kag);
        ck = false;
        for(i = 48; i < 58; i++)
        {
            if(prime[ res[ i ] ])
                printf("%c", i), ck = true;
        }
        for(i = 65; i < 91; i++)
        {
            if(prime[ res[ i ] ])
                printf("%c", i), ck = true;
        }
        for(i = 97; i < 123; i++)
        {
            if(prime[ res[ i ] ])
                printf("%c", i), ck = true;
        }
        if( !ck ) puts("empty");
        else puts("");
    }

    return 0;
}
/*
Its works slow
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    int T, kag = 0, i, j, len;
    map<char, int> m;
    bool prime[ 2000 ], ck;

    prime[ 0 ] = false;
    prime[ 1 ] = false;
    prime[ 2 ] = true;
    for(i = 4; i < 2000; i += 2) prime[ i ] = false;
    for(i = 3; i < 2000; i += 2) prime[ i ] = true;

    for(i = 3; i < 45; i += 2)
        for(j = i * i; j < 2000; j += i)
            prime[ j ] = false;

    char in[ 2002 ];
    scanf("%d", &T); getchar();
    while(T--)
    {
        gets( in );
        len = strlen( in );
        for(i = 0; i < len; i++)
        {
            m[ in[ i ] ]++;
        }
        printf("Case %d: ", ++kag);
        ck = false;

        map <char, int> :: iterator it;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(prime[(*it).second])
            {
                ck = true;
                printf("%c", (*it).first);
            }
        }
        if( !ck ) puts("empty");
        else puts("");
        m.clear();
    }

    return 0;
}
*/
