#include <stdio.h>
int main()
{
    int N, M, res, i, j, fl, tmp;
    while(~scanf("%d %d", &N, &M))
    {
        res = 0;
        for(i = 0; i < N; i++)
        {
            fl = 1;
            for(j = 0; j < M; j++)
            {
                scanf("%d", &tmp);
                fl = tmp == 0 ? 0 : fl;
            }
            res += fl ? 1 : 0;
        }
        printf("%d\n", res);
    }
    return 0;
}
