//Templet start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define long long lld
#define llu unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 5000
#define pb push_back
#define maxn 200000+2
#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void save_code();

char save[ 7 ][ 20 ];

int main()
{
    save_code();
    input();

    return 0;
}
void save_code()
{
    strcpy(save[ 0 ], "#include<string.h>");
    strcpy(save[ 1 ], "#include<stdio.h>");
    strcpy(save[ 2 ], "int main()");
    strcpy(save[ 3 ], "{");
    strcpy(save[ 4 ], "printf(\"\\n\");");
    strcpy(save[ 5 ], "return 0;");
    strcpy(save[ 6 ], "}");
    //for(int i = 0; i < 7; i++) puts(save[ i ]);
}
void input()
{
    char in[ 100 ][ 1000 ], tmp[ 1000 ];
    int i, len, T, j, k, kag = 0;
    while(sf("%d", &T) != EOF)
    {
        getchar();
        if(T == 0) break;
        j = k = 0;
        mem(in, 0);
        while( 1 )
        {
            gets( tmp );
            if(strlen(tmp) != 0) strcpy(in[ j++ ], tmp);
            if(j == T) break;
        }
        pf("Case %d:\n", ++kag);
        fo(i, 4) puts(save[ i ]);
        fo(k, T)
        {
            pf("printf(\"");
            len = strlen(in[ k ]);
            fo(i, len)
            {
                if(in[ k ][ i ] == '"') pf("\\\"");
                else if(in[ k ][ i ] == '\\') pf("\\\\");
                else pf("%c", in[ k ][ i ]);
            }
            pf("\\n\");\n");
        }

        for(i = 4; i < 7; i++) puts(save[ i ]);
    }
}
