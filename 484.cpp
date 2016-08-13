#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

map <int, int> m;
vector <int> v;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(!m[ n ]) v.push_back( n );
        m[ n ]++;
    }
    int len = v.size();
    for(int i = 0; i < len; i++)
        printf("%d %d\n", v[ i ], m[ v[ i ] ]);
    return 0;
}
