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
#define eps 1e-6
#define INF

void input();

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main()
{
    input();

    return 0;
}
void input()
{
    int i, j, k, len, T, kag = 0;
    double I, P, U, res;
    char in[ 100 ], valu[ 32 ];
    sf("%d", &T); getchar();
    while(T--)
    {
        gets( in );
        len = strlen( in );
        I = U = P = eps;
        fo(i, len)
        {
            if(in[ i ] == '=')
            {
                mem(valu, 0);
                if(in[ i - 1 ] == 'U')
                {
                    k = 0; i++;
                    while(isdigit(in[ i ]) || in[ i ] == '-' || in[ i ] == '+')
                    {
                        valu[ k++ ] = in[ i ];
                        i++;
                    }
                    if(in[ i ] == '.' && isdigit(in[ i + 1 ]))
                    {
                        valu[ k++ ] = in[ i++ ];
                        while(isdigit(in[ i ]))
                        {
                            valu[ k++ ] = in[ i ];
                            i++;
                        }
                    }
                    sscanf(valu, "%lf", &U);
                    while(isspace(in[ i ])) i++;
                    if(in[ i ] == 'm') U *= 0.001;
                    else if(in[ i ] == 'M') U*= 1000000.00;
                    else if(in[ i ] == 'k') U*= 1000.00;

                }
                else if(in[ i - 1 ] == 'P')
                {
                    k = 0; i++;
                    while(isdigit(in[ i ]) || in[ i ] == '-' || in[ i ] == '+')
                    {
                        valu[ k++ ] = in[ i ];
                        i++;
                    }
                    if(in[ i ] == '.' && isdigit(in[ i + 1 ]))
                    {
                        valu[ k++ ] = in[ i++ ];
                        while(isdigit(in[ i ]))
                        {
                            valu[ k++ ] = in[ i ];
                            i++;
                        }
                    }
                    sscanf(valu, "%lf", &P);
                    while(isspace(in[ i ])) i++;
                    if(in[ i ] == 'm')  P*= 0.001;
                    else if(in[ i ] == 'M') P*= 1000000.00;
                    else if(in[ i ] == 'k') P*= 1000.00;
                }
                else if(in[ i - 1 ] == 'I')
                {
                    k = 0; i++;
                    while(isdigit(in[ i ]) || in[ i ] == '-' || in[ i ] == '+')
                    {
                        valu[ k++ ] = in[ i ];
                        i++;
                    }
                    if(in[ i ] == '.' && isdigit(in[ i + 1 ]))
                    {
                        valu[ k++ ] = in[ i++ ];
                        while(isdigit(in[ i ]))
                        {
                            valu[ k++ ] = in[ i ];
                            i++;
                        }
                    }
                    sscanf(valu, "%lf", &I);
                    while(isspace(in[ i ])) i++;
                    if(in[ i ] == 'm') I *= 0.001;
                    else if(in[ i ] == 'M') I*= 1000000.00;
                    else if(in[ i ] == 'k') I*= 1000.00;
                }
            }
        }
        //pf("%.2lf %.2lf %.2lf\n", I, P, U);
        pf("Problem #%d\n", ++kag);
        bool ck = true;
        if(P == eps)
        {
            pf("P=%.2lfW\n", I * U);
        }
        else if(U == eps)
        {
            pf("U=%.2lfV\n", P / I);
        }
        else
        {
            pf("I=%.2lfA\n", P / U);
        }
        puts("");
    }
}
