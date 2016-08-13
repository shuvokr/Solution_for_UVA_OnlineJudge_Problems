#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct data
{
    string name, pname;
    int time;
}in[ 105 ];

bool cmd(const data &a, const data &b)
{
    if(a.time < b.time) return true;
    else if(a.time == b.time)
    {
        if(a.name < b.name) return true;
    }
    return false;
}

int main()
{
    int i, n, min, sec, ms, len;
    char nm[ 20 ], tmp[ 25 ];
    while(~scanf("%d", &n))
    {
        for(i = 0; i < n; i++)
        {
            scanf("%s : %d %s %d %s %d %s", tmp, &min, nm, &sec, nm, &ms, nm);
            in[ i ].pname = tmp;
            len = strlen( tmp );
            for(int j = 0; j < len; j++)
            {
                if(islower(tmp[ j ])) tmp[ j ] = tmp[ j ] - 32;
            }
            in[ i ].name = tmp;
            in[ i ].time = (min * 60 + sec) * 1000 + ms;
        }
        sort(in, in + n, cmd);
        min = n >> 1; ms = 0;
        for(i = 0; i < min; i++)
        {
            printf("Row %d\n", i + 1);
            cout << in[ ms++ ].pname << endl;
            cout << in[ ms++ ].pname << endl;
        }
        if(n % 2) {printf("Row %d\n", i + 1); cout << in[ ms ].pname << endl;}
        puts("");
    }
}
