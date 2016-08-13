/*
    Shuvo
    Problem no: 11508. Name: Life On Mars
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
#define lld long long
#define ld long
#define fo(i, n) for(i = 0; i < n; i++)
#define mem(n) memset(n, -1, sizeof(n))

void input();

char ch[6];

int main()
{
    input();

    return 0;
}
void input()
{
    int num, n, tmp, i, len, pos, mamo[100005];
    vector <int> in;

    char inp[99999];
    while(gets(inp))
    {
        if(strcmp(inp, "0") == 0) break;
        len = strlen(inp);
        mem(mamo);
        mem(ch);
        pos = 0; stack <int> stor;
        int cnt = 1, max = 0;
        fo(i, len)
        {
            if(isdigit(inp[i]))
            {
                ch[pos++] = inp[i];
            }
            else if(isspace(inp[i]))
            {
                cnt++;
                num = atoi(ch); pos = 0; mem(ch);
                if(max < num) max = num;
                if(mamo[num] == -1) mamo[num] = num;
                else if(mamo[num] == num) stor.push(num);
            }
        }
        num = atoi(ch);
        if(mamo[num] == -1) mamo[num] = num;
        else if(mamo[num] == num) stor.push(num);

        if(max < num) max = num;
        //pf(" %d %d\n", max, cnt);
        if(max >= cnt) {puts("Message hacked by the Martians!!!"); continue;}

        bool space = false;

            fo(i, cnt)
            {
                if ( space ) printf (" "); space = true;
                if ( mamo [i] == -1 )
                {
                    int k = stor.top();
                    printf ("%d", k);
                    stor.pop ();
                }
                else printf ("%d", mamo [i]);
            }
            printf ("\n");
    }
}
