#include <stdio.h>
#include <math.h>
const int pr = 46345;
int prime[ 4795 ], ind;
bool mark[ pr ];
int calculate(int n, int p);
void primelist()
{
    for(int i = 4; i < pr; i += 2) mark[ i ] = false;
    for(int i = 3; i < pr; i += 2) mark[ i ] = true; mark[ 2 ] = true;
    for(int i = 3, sq = sqrt( pr ); i < sq; i += 2)
        if(mark[ i ])
            for(int j = i << 1; j < pr; j += i) mark[ j ] = false;
    prime[ 0 ] = 2; ind = 1;
    for(int i = 3; i < pr; i += 2)
        if(mark[ i ]) prime[ ind++ ] = i; //printf("%d\n", ind);
}
int main()
{
    //freopen("output.txt", "w", stdout);
    primelist();
    int n, m, a, b;
    while(~scanf("%d %d", &n, &m))
    {
        if((m <= n && m) || (!n && m == 1))
        {
            printf("%d divides %d!\n", m, n);
            continue;
        }
        if(!m || !n)
        {
            printf("%d does not divide %d!\n", m, n);
            continue;
        }
        a = m; b = n;
        int res = 1, i = 0, cou, tot;
        while(prime[ i ] <= m && i < ind)
        {
            //puts("ok");
            cou = 0;
            while(!(m % prime[ i ]))
            {
                //puts("kkkk");
                m /= prime[ i ];
                cou++;
            }
            if(cou)
            {
                tot = calculate(n, prime[ i ]);
                //printf("  %d %d\n", tot, cou);
                if(tot < cou) {res = 0; break;}
            }
            i++;
            if(m == 1) break;
        }
        if(m > 1)
        {
            tot = calculate(n, m);
            if(!tot) res = 0;
        }
        if(res) printf("%d divides %d!\n", a, b);
        else printf("%d does not divide %d!\n", a, b);
    }
    return 0;
}
int calculate(int n, int p)
{
    //printf(" %d\n", p);
    int ret = 0;
    unsigned long long k = p;
    while(k <= n)
    {
        ret += n / k;
        k *= p;
    }
    return ret;
}
