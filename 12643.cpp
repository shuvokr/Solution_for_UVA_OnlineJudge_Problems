#include <stdio.h>
int main()
{
    int round, n, i, j, s;
    while(~scanf("%d %d %d", &n, &i, &j))
    {
        if(i > j) s = i, i = j, j = s; n++;
        for(round = 1; round < n; round++)
        {
            if((i % 2) && !(j % 2) && j - i == 1) break;
            i = (i + 1) >> 1;
            j = (j + 1) >> 1;
            if(i > j) s = i, i = j, j = s;
        }
        printf("%d\n", round);
    }
    return 0;
}
