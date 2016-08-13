#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int T, n, m, kag = 0;
    string a;
    scanf("%d", &T);
    vector <string> in;
    set <string> mp;
    while( T-- )
    {
        scanf("%d %d", &n, &m);
        getline(cin, a);
        mp.clear(); in.clear();
        for(int i = 0; i < n; i++)
        {
            getline(cin, a);
            in.push_back( a );
        }

        for(int i = 0; i < m; i++)
        {
            getline(cin, a);
            for(int j = 0; j < n; j++) mp.insert(in[ j ] + a);
        }

        printf("Case %d: %d\n", ++kag, mp.size());
    }
    return 0;
}
/*
2
3 2
cat
dog
mouse
rat
bat
1 1
abc
cab
*/
