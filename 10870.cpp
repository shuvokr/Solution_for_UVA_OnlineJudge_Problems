#include <stdio.h>
#include <string.h>

struct matrix
{
    long long adj[ 16 ][ 16 ];
};

matrix power(matrix mat, long long p);
matrix multiply(matrix a, matrix b);

long long d, mod, n, fn[ 16 ];
matrix mat;

int main()
{
    while(~scanf("%lld %lld %lld", &d, &n, &mod) && (d || n || mod))
    {
        for(int i = 0; i < d; i++) scanf("%lld", &mat.adj[ 0 ][ i ]);
        for(int i = 1; i < d; i++)
            for(int j = 0; j < d; j++)
            {
                if(j + 1 == i)
                {
                    mat.adj[ i ][ j ] = 1;
                    continue;
                }
                mat.adj[ i ][ j ] = 0;
            }
        for(int i = 0; i < d; i++) scanf("%lld", &fn[ i ]);
        if(n <= d)
        {
            printf("%lld\n", fn[n - 1] % mod);
            continue;
        }
        mat = power(mat, n - d);
        long long res = 0;
        for(int i = 0; i < d; i++) res += ((mat.adj[ 0 ][ i ] * fn[d - 1 - i]) % mod);
        printf("%lld\n", res % mod);
    }
    return 0;
}
matrix power(matrix mat, long long p)
{
    if(p == 1) return mat;
    if(p % 2) return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p >> 1);
    return multiply(ret, ret);
}
matrix multiply(matrix a, matrix b)
{
    matrix ret;
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
        {
            long long sum = 0;
            for(int k = 0; k < d; k++)
                sum += a.adj[ i ][ k ] * b.adj[ k ][ j ] % mod;
            ret.adj[ i ][ j ] = sum;
        }
    return ret;
}
