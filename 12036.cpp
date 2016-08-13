#include <stdio.h>
#include <cstring>
using namespace std;
struct MyMap
{
    int mapArray[ 101 ];
        MyMap()
        {
                memset(mapArray, 0, sizeof(mapArray));
        }
        void clear()
        {
            memset(mapArray, 0, sizeof(mapArray));
        }
        int &operator[](int key)
        {
                return mapArray[key];
        }
};
int main()
{
    int i, j, n, T, tmp, kag = 0;
    bool res;
    MyMap num;
    scanf("%d", &T);
    while(T--)
    {
        num.clear();
        scanf("%d", &n); res = true;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d", &tmp);
                if( res ) num[ tmp ]++;
                if(num[ tmp ] > n) res = false;
            }

        if( res ) printf("Case %d: yes\n", ++kag);
        else printf("Case %d: no\n", ++kag);
    }
    return 0;
}
