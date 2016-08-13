#include <cstdio>
struct matrix
{
    long long adj[ 3 ][ 3 ];
};
matrix power(matrix mat, long long p);
matrix multiply(matrix a, matrix b);
long long mod = 1000000009;
int main()
{
    matrix mat;
    long long n, m;
    while(~scanf("%lld", &n) && n)
    {
        if(n == 1)
        {
            puts("0");
            continue;
        }
        if(n == 2)
        {
            puts("1");
            continue;
        }
        if(n == 3)
        {
            puts("2");
            continue;
        }
        if(n == 4)
        {
            puts("3");
            continue;
        }

        mat.adj[ 0 ][ 0 ] = 1; mat.adj[ 0 ][ 1 ] = 1; mat.adj[ 0 ][ 2 ] = 1; mat.adj[ 1 ][ 0 ] = mat.adj[ 2 ][ 1 ] = 1;
        mat.adj[ 1 ][ 1 ] = mat.adj[ 1 ][ 2 ] = mat.adj[ 2 ][ 0 ] = mat.adj[ 2 ][ 2 ] = 0;


        mat = power(mat, n - 3);
        printf("%lld\n", ( ((mat.adj[ 0 ][ 0 ] * 2) % mod) + (mat.adj[ 0 ][ 1 ] % mod) ) % mod);
    }
    return 0;
}
matrix power(matrix mat, long long p)
{
    if(p == 1) return mat;
    if(p % 2)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p >> 1);
    return multiply(ret, ret);
}
matrix multiply(matrix a, matrix b)
{
    int i, j, k;
    long long sum;
    matrix ret;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            sum = 0;
            for(k = 0; k < 3; k++)
                sum += ((a.adj[ i ][ k ] % mod) * (b.adj[ k ][ j ] % mod)) % mod;
            ret.adj[ i ][ j ] = sum % mod;
        }

    return ret;
}
