#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define lld long long
#define llu unsigned long long
#define fo(i, v, n) for(i = v; i < n; i++)
#define foo(i, v, n) for(i = n - 1; i >= v; i--)
#define mem(n, v) memset(n, v, sizeof(n))
#define maxn 100+10

typedef vector< int > vi;
typedef pair<int, int> pi;

void input();
void YMD(char ch[]);

int year, day;
char month[ 11 ];

int main()
{
    input();

    return 0;
}
void input()
{
    //Save manth name and value :)
    char manth[ 13 ][ 11 ];
    strcpy(manth[ 1 ], "January");
    strcpy(manth[ 2 ], "February");
    strcpy(manth[ 3 ], "March");
    strcpy(manth[ 4 ], "April");
    strcpy(manth[ 5 ], "May");
    strcpy(manth[ 6 ], "June");
    strcpy(manth[ 7 ], "July");
    strcpy(manth[ 8 ], "August");
    strcpy(manth[ 9 ], "September");
    strcpy(manth[ 10 ], "October");
    strcpy(manth[ 11 ], "November");
    strcpy(manth[ 12 ], "December");

    map <string, int> m;

    m [ manth[1] ] = 1;
    m [ manth[2] ] = 2;
    m [ manth[3] ] = 3;
    m [ manth[4] ] = 4;
    m [ manth[5] ] = 5;
    m [ manth[6] ] = 6;
    m [ manth[7] ] = 7;
    m [ manth[8] ] = 8;
    m [ manth[9] ] = 9;
    m [ manth[10] ] = 10;
    m [ manth[11] ] = 11;
    m [ manth[12] ] = 12;
   // End saveing...........

    char in[ 20 ];
    int T, i, days, mon, tmp1, tmp2, kag = 0;
    bool leap;
    sf("%d", &T);
    while(T--)
    {
        mon = 0;
        getchar();
        gets( in );
        sf("%d", &days);
        YMD( in );
        mon = m[ month ];
        /*pf("%d\n", mon);
        int len = strlen(month);
        pf("lenth = %d\n", len);

        puts(month);*/
        while(days)
        {
            if(days)
            if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
            {
                //puts("     31");
                tmp1 = 0; tmp2 = 0;
                while(days && day <= 31)
                {
                    day++;
                    days--;
                    if(day == 32) tmp1 = 1;
                    if(mon == 12 && day == 32) tmp2 = 1;
                }
                if(tmp1 == 1) day = 1, mon++;
                if(tmp2 == 1) mon = 1, day = 1, year++;
            }
            if(days)
            if(mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                //puts("     30");
                tmp1 = 0; tmp2 = 0;
                while(days && day <= 30)
                {
                    day++;
                    days--;
                    if(day == 31) tmp1 = 1;
                    if(mon == 12 && day == 31) tmp2 = 1;
                }
                if(tmp1 == 1) day = 1, mon++;
                if(tmp2 == 1) mon = 1, day = 1, year++;
            }
            leap = false;
            if(days)
            if(mon == 2)
            {
                //puts("       leap");
                if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) leap = true;
                else leap = false;
                if(leap)
                {
                    tmp1 = 0; tmp2 = 0;
                        while(days && day <= 29)
                        {
                            day++;
                            days--;
                            if(day == 30) tmp1 = 1;
                            if(mon == 12 && day == 30) tmp2 = 1;
                        }
                        if(tmp1 == 1) day = 1, mon++;
                        if(tmp2 == 1) mon = 1, day = 1, year++;
                }
                else
                {
                    tmp1 = 0; tmp2 = 0;
                    while(days && day <= 28)
                    {
                        day++;
                        days--;
                        if(day == 29) tmp1 = 1;
                        if(mon == 12 && day == 29) tmp2 = 1;
                    }
                    if(tmp1 == 1) day = 1, mon++;
                    if(tmp2 == 1) mon = 1, day = 1, year++;
                }
            }
        }
        pf("Case %d: %d-%s-", ++kag, year, manth[ mon ]);
        if(day < 10) pf("0%d\n", day);
        else pf("%d\n", day);
    }
}
void YMD(char ch[])
{
    year = ( ((ch[0] - '0') * 1000) + ((ch[1] - '0') * 100) + ((ch[2] - '0') * 10) + (ch[3] - '0') );
    int i = 5, k = 0;
    mem(month, 0);
    while(isalpha(ch[ i ])) month[ k++ ] = ch[ i++ ];
    i++;
    day = ((ch[i] - '0') * 10) + (ch[i + 1] - '0');
}

/*
1
1900-February-01
30
*/
