#include <cstdio>
struct matrix
{
    long long adj[ 2 ][ 2 ];
};
matrix power(matrix mat, int p);
matrix multiply(matrix a, matrix b);
int mod;
int main()
{
    matrix mat;
    int i, n, m;
    while(~scanf("%d %d", &n, &m))
    {
        if(!n)
        {
            puts("0");
            continue;
        }
        if(n == 1 || n == 2)
        {
            puts("1");
            continue;
        }
        mat.adj[ 0 ][ 0 ] = mat.adj[ 0 ][ 1 ] = mat.adj[ 1 ][ 0 ] = 1;
        mat.adj[ 1 ][ 1 ] = 0;
        if(!m) mod = 1;
        else mod = 2;
        for(i = 1; i < m; i++) mod <<= 1;
        mat = power(mat, n - 2);
        printf("%lld\n", (mat.adj[ 0 ][ 0 ] + mat.adj[ 0 ][ 1 ]) % mod);
    }
    return 0;
}
matrix power(matrix mat, int p)
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
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
        {
            sum = 0;
            for(k = 0; k < 2; k++)
                sum += (a.adj[ i ][ k ] % mod) * (b.adj[ k ][ j ] % mod) % mod;
            ret.adj[ i ][ j ] = sum;
        }
    return ret;
}
