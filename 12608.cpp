#include <stdio.h>
using namespace std;
struct data
{
    int a, b;
};
int main()
{
    data in[ 1010 ]; bool mark;
    int maxw, point, i, res, wi, T, at, cou;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &maxw, &point); mark = true;
        for(wi = res = at = i = 0; i < point; )
        {
            if(mark) scanf("%d %d", &in[ i ].a, &in[ i ].b), mark = false;
            res += in[ i ].a - at;
            at = in[ i ].a;
            if(wi + in[ i ].b <= maxw)
            {
                wi = wi + in[ i++ ].b;
                mark = true;
                if(wi == maxw) {res += at; at = 0; wi = 0;}
            }
            else {res += at; at = 0; wi = 0;}
        }
        printf("%d\n", res + at);
    }
    return 0;
}


