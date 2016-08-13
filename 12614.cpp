#include <stdio.h>
using namespace std;
int main()
{
    int n, T, k = 0, i, c, in;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &T);
        c = 1 >> 30;
        while(T--)
        {
            scanf("%d", &in);
            if(c < in)
                c = in;
        }
        printf("Case %d: %d\n", ++k, c);
    }
    return 0;
}
