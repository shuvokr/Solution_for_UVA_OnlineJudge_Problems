#include <stdio.h>

using namespace std;

int main()
{
    char sor[ 100 ], b;
    int x, y, n;
    scanf("%d", &n);
    gets( sor );
    while(n--)
    {
        gets( sor );
        sscanf(sor,"%c %d %d", &b, &x, &y);
        b == 'r' ? x < y ? printf("%d\n", x) : printf("%d\n", y) :
            b == 'Q' ? x < y ? printf("%d\n", x) : printf("%d\n", y) :
                b == 'k' ? printf("%d\n",((x * y) + 1) / 2) : printf("%d\n",((y + 1) / 2) * ((x + 1) / 2));
    }
    return 0;
}

