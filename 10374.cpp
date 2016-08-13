/*
        Shuvo
        Problem algo: Ad hoc
        Problem ID: 10374
        Problem name: Election
*/
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
#define maxn 99+1

#define white 0
#define black 1

typedef vector <int> vi;

int diraction1[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int diraction2[] = {0, -1, 1, 0, 1, -1, 1, -1};
int horsed1[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horsed2[] = {1, -1, -2, -2, -1, 1, 2, 2};

//Templet end
void input();
void get_input();
int calculate_result();

map <string, string> info;
map <string, int> cou;
int n, m, res, maxi;
char res_str[ maxn ];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    input();

    return 0;
}
void input()
{
    int i, T;
    char in[ maxn ], inn[ maxn ];
    sf("%d", &T);
    bool ck = false;
    while(T--)
    {
        if( ck ) puts("");
        else ck = true;

        get_input();
        res = calculate_result();
        if(res == 1) cout << info[ res_str ] << endl;
        else puts("tie");
    }
}
void get_input()
{
    info.clear(); cou.clear();
    int i;
    maxi = -1;
    char in[ maxn ], inn[ maxn ];
    sf("%d", &n);
    cin.ignore(20, '\n');
    fo(i, n)
    {
        gets( in ); gets( inn );
        info[ in ] = inn;
    }
    sf("%d", &m);
    cin.ignore(20, '\n');
    fo(i, m)
    {
        gets( in );
        cou[ in ]++;
        if(maxi < cou[ in ])
        {
            mem(res_str, 0);
            strcpy(res_str, in);
            maxi = cou[ in ];
        }
    }
}
int calculate_result()
{
    int coun = 0;
    map <string, int> :: iterator it;
    for(it = cou.begin(); it != cou.end(); it++)
    {
        if(cou[ (*it).first ] == maxi) coun++;
    }
    return coun;
}
