#include <cstdio>
bool isok(int n);
int main()
{
    int n, m, k, p, cou, res, num, tar;
    bool clock;
    while(~scanf("%d %d %d", &n, &m, &k) && n)
    {
        p = 0; cou = 0; num = 0; clock = true; tar = n;
        while(cou != k)
        {
            if(p == tar)
            {
                if( clock ) clock = false, p = n, tar = 1;
                else clock = true, p = 1, tar = n;
            }
            if(clock) p++;
            else p--;
            num++;
            if(p == m)
            if(isok(num)) cou++;
        }
        printf("%d\n", num);
    }
    return 0;
}
bool isok(int n)
{
    if(n % 7 == 0) return true;
    while( n )
    {
        if(n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}
