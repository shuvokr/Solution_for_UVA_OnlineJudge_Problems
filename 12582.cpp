/*
        Shuvo
        Problem algo: Ad hoc
        Problem ID: 12582
        Problem name: Wedding of Sultan
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int T, i, j, index, len, cou, a, b, kag = 0;
    char in[ 10000 ], tmp[ 10000 ], c, cc, mm[ 10000 ];
    map <int, int> m;
    map <char, int> q;
    scanf("%d", &T); getchar();
    while(T--)
    {
        printf("Case %d\n", ++kag);
        m.clear();
        gets( in );
        len = strlen( in );
        memset(tmp, 0, 10000);
        strcpy(tmp, in);
        a = 0; b = 1;
        while(true)
        {
            if(a == 0 && b == len - 1) break;
            //printf("   %c %c\n", in[a], in[b]);
            if(in[ a ] == in[ b ])
            {
                in[ a ] = '.';
                in[ b ] = '.';
                j = a;
                while(in[ j ] == '.')
                {
                    j--;
                }
                a = j;
                b++;
            }
            else if(in[a] != in[b] && (in[b] != '.' || in[ a ] != '.'))
            {
                m[ in[a] ]++;
                a = b;
                m[ in[b] ]++;
                b++;
            }
        }
        q.clear(); a = 0;
        for(i = 0; i < len; i++)
        {
            if(q[ tmp[i] ] == 0)
            {
                q[ tmp[i] ] = 1;
                mm[ a++ ] = tmp[ i ];
            }
        }

        sort(mm, mm+a);
        for(i = 0; i < a; i++)
            printf("%c = %d\n", mm[i], m[mm[i]]);
    }
    return 0;
}
/*#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int T, i, j, len, cou, a, b, kag = 0;
    char in[ 100 ], c, cc;
    map <char, int> m;
    scanf("%d", &T); getchar();
    while(T--)
    {
        printf("Case %d\n", ++kag);
        m.clear();
        gets( in );
        len = strlen( in );
        a = 0; b = 1;
        while(true)
        {
            if(a == 0 && b == len - 1) break;
            if(in[ a ] == in[ b ])
            {
                in[ a ] = '.';
                in[ b ] = '.';
                j = a;
                while(in[ j ] == '.')
                {
                    j--;
                }
                a = j;
                b++;
            }
            else if(in[a] != in[b] && (in[b] != '.' || in[ a ] != '.'))
            {
                m[ in[a] ]++;
                a = b;
                m[ in[b] ]++;
                b++;
            }
        }

        map<char, int> :: iterator ii;
        for(ii = m.begin(); ii != m.end(); ii++)
            cout << (*ii).first << " = " << (*ii).second << endl;
    }
    return 0;
}
*/
