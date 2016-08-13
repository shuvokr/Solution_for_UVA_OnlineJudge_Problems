#include <stdio.h>
int main()
{
    int x1, y1, x2, y2, x, y ,r, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y, &r);
        int dorgho = x2 - x1;
        int prostho = y2 - y1;
        int d = (9 * dorgho) / 20;
        int xx = x1 + d;
        int yy = y1 + (prostho / 2);
        if(dorgho * 6 == prostho * 10 && 5 * r == dorgho && (9 * dorgho) % 20 == 0 && prostho % 2 == 0 && xx == x && yy == y)
        {
            puts("YES");
        }
        else puts("NO");
    }
    return 0;
}
/*
4
0 0 20 12 9 6 4
0 0 10 6 4 3 2
1 1 21 13 10 7 4
0 0 20 20 9 10 4

*/
