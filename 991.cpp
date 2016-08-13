#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long

int main()
{
    char s[11][6];
    s[1] = {'1'};       s[6] = {'1', '3', '2'};
    s[2] = {'2'};       s[7] = {'4', '2', '9'};
    s[3] = {'5'};       s[8] = {'1', '4', '3', '0'};
    s[4] = {'1', '4'};  s[9] = {'4', '8', '6', '2'};
    s[5] = {'4', '2'};  s[10] = {'1', '6', '7', '9', '6'};

    int n;
    scanf("%d", &n);
    puts(s[n]);
    while(scanf("%d", &n) != EOF)
    {
        puts("");
        puts(s[n]);
    }
    return 0;
}

/*void input();
void save();

ll catalan[11];

int main()
{
    save();
    input();

    return 0;
}
void save()
{
    int n, a, b;
    catalan[0] = 1;
    catalan[1] = 1;
    for(int i = 2; i < 11; i++)
    {
        n = i - 1;
        a = 2 * ((2 * n) + 1);
        b = n + 2;
        catalan[i] = (catalan[n] * a) / b;
        //pf("%lld ", catalan[i]);
    }
}
void input()
{
    int n, cou = 0;

    sf("%d", &n);
    pf("%lld\n", catalan[n]);
    while(sf("%d", &n) != EOF)
    {
        pf("\n%lld\n", catalan[n]);
    }
}
*/
