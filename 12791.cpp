#include <stdio.h>
int main()
{
    int a, b, res, s, e, tmp;
    while(~scanf("%d %d", &a, &b))
    {
        tmp = a; res = 0;
        s = 1, e = b;
        while(1)
        {
            if(a >= s && a <= e) {res++, a += tmp;}
            else {break;}

            s = e + 1; e += b;
        }
        printf("%d\n", res + 1);
    }
    return 0;
}
