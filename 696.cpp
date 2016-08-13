#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int r, c, tmp, a, b;
    while(~scanf("%d %d", &r, &c))
    {
        if(!r && !c) return 0;
        tmp = r * c;
        if(r == 1 || c == 1)
        {
            printf("%d knights may be placed on a %d row %d column board.\n", tmp, r, c);
            continue;
        }
        if(r == 2 || c == 2)
        {
            tmp = ceil(tmp / 8.0) * 4;
            if(r > 3 && r % 4 == 1) tmp -= 2;
            if(c > 3 && c % 4 == 1) tmp -= 2;
            printf("%d knights may be placed on a %d row %d column board.\n", tmp, r, c);
            continue;
        }
        if(r % 2 == 0 || c % 2 == 0)
        {
            printf("%d knights may be placed on a %d row %d column board.\n", tmp / 2, r, c);
            continue;
        }
        a = r / 2; b = c / 2;
        printf("%d knights may be placed on a %d row %d column board.\n", (a + 1) * (b + 1) + a * b, r, c);
    }
}
