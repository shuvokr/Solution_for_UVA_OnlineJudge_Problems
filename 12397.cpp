#include <cstdio>
int c[16] = { 4, 6, 3, 5, 2, 4, 2, 4, 2, 3, 2, 3, 1 };
int v[16] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
int main()
{
    for(int res(0), n; scanf("%d", &n) == 1; res = 0)
    {
        for(int i = 0; n; ++i)
            while(n >= v[i]){
                res += c[i];
                n -= v[i];
            }
        printf("%d\n", res);
    }
    return 0;
}
