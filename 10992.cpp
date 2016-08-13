#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, len, n2, n7, n5, n11, n15, n20, n28, n36, n100, n4, n400;
    int a5 = 2148 % 5, a7 = 2148 % 7, a11 = 2148 % 11, a15 = 2148 % 15, a20 = 2148 % 20, a28 = 2148 % 28, a36 = 2148 % 36;
    char in[ 55 ];
    bool mark, space = false;
    while(gets( in ))
    {
        if(in[ 0 ] == '0') break;
        if(space) puts("");
        else space = true;

        if(strlen(in) < 5)
        {
            int sex = atoi( in );
            if(sex < 2148)
            {
                puts( in );
                puts("No ghost will come in this year");
                continue;
            }
        }

        n2 = n5 = n4 = n7 = n11 = n15 = n20 = n28 = n36 = n100 = n400 = 0;
        len = strlen( in );
        for(i = 0; i < len; i++)
        {
            n2 = ((n2 * 10) + (in[ i ] - 48)) % 2;
            n4 = ((n4 * 10) + (in[ i ] - 48)) % 4;
            n5 = ((n5 * 10) + (in[ i ] - 48)) % 5;
            n7 = ((n7 * 10) + (in[ i ] - 48)) % 7;
            n11 = ((n11 * 10) + (in[ i ] - 48)) % 11;
            n15 = ((n15 * 10) + (in[ i ] - 48)) % 15;
            n20 = ((n20 * 10) + (in[ i ] - 48)) % 20;
            n28 = ((n28 * 10) + (in[ i ] - 48)) % 28;
            n36 = ((n36 * 10) + (in[ i ] - 48)) % 36;
            n100 = ((n100 * 10) + (in[ i ] - 48)) % 100;
            n400 = ((n400 * 10) + (in[ i ] - 48)) % 400;
        }
        puts( in );
        mark = true;
        if(!n2){ puts("Ghost of Tanveer Ahsan!!!"); mark = false; }
        if(n5 == a5){ puts("Ghost of Shahriar Manzoor!!!"); mark = false; }
        if(n7 == a7){ puts("Ghost of Adrian Kugel!!!"); mark = false; }
        if(n11 == a11){ puts("Ghost of Anton Maydell!!!"); mark = false; }
        if(n15 == a15){ puts("Ghost of Derek Kisman!!!"); mark = false; }
        if(n20 == a20){ puts("Ghost of Rezaul Alam Chowdhury!!!"); mark = false; }
        if(n28 == a28){ puts("Ghost of Jimmy Mardell!!!"); mark = false; }
        if(n36 == a36){ puts("Ghost of Monirul Hasan!!!"); mark = false; }
        if((!n4 && n100) || !n400){ puts("Ghost of K. M. Iftekhar!!!"); mark = false; }
        if(mark) puts("No ghost will come in this year");
    }
    return 0;
}
