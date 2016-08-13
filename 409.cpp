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
#define col 2200
#define row 22

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

char in[ row ][ col ], line[ row ][ col ], save_line[ row ][ col ];

int main()
{
    input();

    return 0;
}
void input()
{
    char wrd[ col ];
    int max_res[ row ], i, j, k, word, sentence, len, kag = 0, maximum;
    while(sf("%d %d", &word, &sentence) != EOF)
    {
        getchar();
        mem(line, 0); mem(in, 0);
        fo(i, word)
        {
            gets( in[ i ] );
            len = strlen( in[ i ] );
            fo(j, len) if(isupper(in[ i ][ j ])) in[ i ][ j ] = in[ i ][ j ] + 32;
        }
        fo(i, sentence)
        {
            gets(line[ i ]);
            strcpy(save_line[ i ], line[ i ]);
            len = strlen( line[ i ] );
            fo(j, len)
                if(isupper(line[ i ][ j ])) line[ i ][ j ] = line[ i ][ j ] + 32;
        }
        fo(i, sentence)
        {
            int cou = 0;
            len = strlen( line[ i ]);
            for(k = 0; ; )
            {
                if(k == len) break;
                if(!islower(line[ i ][ k ])) k++;
                else
                {
                    mem(wrd, 0); int pos = 0;
                    while(k < len && islower(line[ i ][ k ])) wrd[ pos++ ] = line[ i ][ k++ ];
                    pos = 0;
                    fo(j, word)
                    {
                        if(strcmp(in[ j ], wrd) == 0)
                        {
                            cou++; j = word;
                        }
                    }
                }
            }
            max_res[ i ] = cou; cou = 0;
        }
        maximum = -1;
        fo(i, sentence) if(maximum < max_res[ i ]) maximum = max_res[ i ];
        pf("Excuse Set #%d\n", ++kag);
        fo(i, sentence)
        {
            if(maximum == max_res[ i ]) puts(save_line[ i ]);
        }
        puts("");
    }
}
