#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set <int> s;

int main()
{
    int T, kag = 0;
    scanf("%d", &T);
    while( T-- )
    {
        s.clear();
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == b)
        {
            printf("Case #%d: 0\n", ++kag);
            continue;
        }
        int x = a - b, sqt = sqrt( x ) + 1;
        for(int i = 1; i < sqt; i++)
        {
            int tmp = (int)(x / i);
            if(tmp * i == x)
            {
                if(tmp > b) s.insert( tmp );
                if(i > b) s.insert( i );
            }
        }
        printf("Case #%d:", ++kag);
        for(set <int> :: iterator it = s.begin(); it != s.end(); it++)
            cout << " " << *it;
        puts("");
    }
    return 0;
}
