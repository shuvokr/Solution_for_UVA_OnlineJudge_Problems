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

int main()
{
    input();

    return 0;
}
void input()
{
    map <string, int> res;
    int n, i, j;
    char in[ 10000 ], on[ 10000 ];
    sf("%d", &n);
    getchar();
    while(n--)
    {
        gets( in ); j = 0;
        mem(on, 0);
        sscanf(in, "%s", on);
        res[ on ]++;
    }
    map <string, int> :: iterator it;
    for(it = res.begin(); it != res.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}
