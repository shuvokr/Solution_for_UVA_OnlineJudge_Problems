#include <cstdio>
struct matrix
{
    int adj[ 2 ][ 2 ];
};

matrix power(matrix mat, int p);
matrix mutiply(matrix a, matrix b);

int mod;
int main()
{
    int i, T, a, b, n, m;
    matrix mat;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d %d %d %d", &a, &b, &n, &m);
        mod = 1;
        for(i = 0; i < m; i++) mod *= 10;
        if(n < 3)
        {
            if(!n) printf("%d\n", a);
            else if(n == 1) printf("%d\n", b);
            else printf("%d\n", (a + b) % mod);
            continue;
        }

        mat.adj[ 0 ][ 0 ] = mat.adj[ 0 ][ 1 ] = mat.adj[ 1 ][ 0 ] = 1;
        mat.adj[ 1 ][ 1 ] = 0;
        mat = power(mat, n - 1);
        printf("%d\n", (b * mat.adj[ 0 ][ 0 ] + a * mat.adj[ 0 ][ 1 ]) % mod);
    }
    return 0;
}
matrix power(matrix mat, int p)
{
    if(p == 1) return mat;
    if(p % 2)
        return mutiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p >> 1);
    return mutiply(ret, ret);
}
matrix mutiply(matrix a, matrix b)
{
    int i, j, k, sum;
    matrix ret;
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
        {
            sum = 0;
            for(k = 0; k < 2; k++)
                sum += a.adj[ i ][ k ] * b.adj[ k ][ j ] % mod;
            ret.adj[ i ][ j ] = sum;
        }
    return ret;
}
