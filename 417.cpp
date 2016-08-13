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
#define foo(i, j, n) for(i = j; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n, v) memset(n, v, sizeof( n ))
#define eps 1e-8
#define INF 1e9
#define maxn 83681+1

#define filA 1
#define filB 2
#define emtA 3
#define emtB 4
#define purAB 5
#define purBA 6

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

void input();
void save_res();
bool cheaking(char ch[]);

char save[ maxn ][ 6 ];
int two, three, four, five, len;

int main()
{
    save_res();
    input();

    return 0;
}
void input()
{
    char in[ 6 ];
    int i;
    bool ck;
    while(gets( in ))
    {
        len = strlen( in );
        if(len == 1) pf("%d\n", in[ 0 ] - 'a' + 1);
        else
        {
            ck = cheaking( in );
            if(!ck) puts("0");
            else
            {
                if(len == 2)
                {
                    foo(i, two, maxn)
                    {
                        if(strcmp(in, save[ i ]) == 0)
                        {
                            pf("%d\n", i+1);
                        }
                    }
                }
                else if(len == 3)
                {
                    foo(i, three, maxn)
                    {
                        if(strcmp(in, save[ i ]) == 0)
                        {
                            pf("%d\n", i+1);
                        }
                    }
                }
                else if(len == 4)
                {
                    foo(i, four, maxn)
                    {
                        if(strcmp(in, save[ i ]) == 0)
                        {
                            pf("%d\n", i+1);
                        }
                    }
                }
                else
                {
                    foo(i, five, maxn)
                    {
                        if(strcmp(in, save[ i ]) == 0)
                        {
                            pf("%d\n", i+1);
                        }
                    }
                }
            }
        }
    }
}
bool cheaking(char ch[])
{
    int i;
    fo(i, len - 1)
    {
        if(ch[ i ] >= ch[ i + 1 ]) return false;
    }
    return true;
}
void save_res()
{
    int i, j, k, l, m, cou = 0;

    fo(i, 26) save[ cou++ ][ 0 ] = 'a' + i;

    two = cou;
    fo(i, 26)
        foo(j, i + 1, 26)
        {
            save[ cou ][ 0 ] = 'a' + i;
            save[ cou++ ][ 1 ] = 'a' + j;
        }

    three = cou;
    fo(i, 26)
        foo(j, i + 1, 26)
            foo(k, j + 1, 26)
            {
                save[ cou ][ 0 ] = 'a' + i;
                save[ cou ][ 1 ] = 'a' + j;
                save[ cou++ ][ 2 ] = 'a' + k;
            }

    four = cou;
    fo(i, 26)
        foo(j, i + 1, 26)
            foo(k, j + 1, 26)
                foo(l, k + 1, 26)
                {
                    save[ cou ][ 0 ] = 'a' + i;
                    save[ cou ][ 1 ] = 'a' + j;
                    save[ cou ][ 2 ] = 'a' + k;
                    save[ cou++ ][ 3 ] = 'a' + l;
                }

    five = cou;
    fo(i, 26)
        foo(j, i + 1, 26)
            foo(k, j + 1, 26)
                foo(l, k + 1, 26)
                    foo(m, l + 1, 26)
                    {
                        save[ cou ][ 0 ] = 'a' + i;
                        save[ cou ][ 1 ] = 'a' + j;
                        save[ cou ][ 2 ] = 'a' + k;
                        save[ cou ][ 3 ] = 'a' + l;
                        save[ cou++ ][ 4 ] = 'a' + m;
                    }
}
