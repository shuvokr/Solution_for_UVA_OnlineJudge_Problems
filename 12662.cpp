#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int len, n, q, pos, i, j, lef, righ, L, R;
int main()
{
    map <int, string> take;
    string tk;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        cin >> tk;
        take[ i ] = tk;
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &pos);
        if(take[ pos - 1 ] != "?")
        {
            cout << take[pos - 1] << endl;
            continue;
        }
        lef = pos - 2;
        righ = pos;
        L = R = 1;
        while( 1 )
        {
            if(lef >= 0 && take[ lef ] != "?") break;
            if(righ < n && take[ righ ] != "?") break;
            if( lef > 0 ) L++, lef--;
            if(righ < n - 1) R++, righ++;
        }
        if(L == R && take[ lef ] != "?" && take[ righ ] != "?")
        {
            cout << "middle of " << take[ lef ] << " and " << take[ righ ] << endl;
            continue;
        }
        if(take[ righ ] != "?" && righ < n)
        {
            for(int k = 0; k < R; k++) printf("left of ");
            cout << take[ righ ] << endl;
            continue;
        }
        if(take[ lef ] != "?")
        {
            for(int k = 0; k < L; k++) printf("right of ");
            cout << take[ lef ] << endl;
            continue;
        }
    }
    return 0;
}
