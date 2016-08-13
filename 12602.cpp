#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)

void input();
int value(char c);

int a, b, cc;

int main()
{
    input();

    return 0;
}
void input()
{
    int T, n, i;
    char ch[9], c[4];
    sf("%d", &T);

    while(T--)
    {
        sf("%s", ch);
        memset(c, 0, 4);
        fo(i, 3) c[i] = ch[i];
        n = ((ch[4] - 48) * 1000) + ((ch[5] - 48) * 100) + ((ch[6] - 48) * 10) + (ch[7] - 48);

        a = value(c[0]);
        b = value(c[1]);
        cc = value(c[2]);

        a = (a * int(ceil(pow(26, 2)))) + (b * int(ceil(pow(26, 1)))) + cc;
        a = abs(a - n);
        if(a < 101) {puts("nice"); continue;}
        puts("not nice");

    }
}
int value(char c)
{
    if(c == 'A') return 0;
    if(c == 'B') return 1;
    if(c == 'C') return 2;
    if(c == 'D') return 3;
    if(c == 'E') return 4;
    if(c == 'F') return 5;
    if(c == 'G') return 6;
    if(c == 'H') return 7;
    if(c == 'I') return 8;
    if(c == 'J') return 9;
    if(c == 'K') return 10;
    if(c == 'L') return 11;
    if(c == 'M') return 12;
    if(c == 'N') return 13;
    if(c == 'O') return 14;
    if(c == 'P') return 15;
    if(c == 'Q') return 16;
    if(c == 'R') return 17;
    if(c == 'S') return 18;
    if(c == 'T') return 19;
    if(c == 'U') return 20;
    if(c == 'V') return 21;
    if(c == 'W') return 22;
    if(c == 'X') return 23;
    if(c == 'Y') return 24;
    if(c == 'Z') return 25;
}
