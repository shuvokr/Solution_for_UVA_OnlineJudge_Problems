#include <stdio.h>
#include <string.h>

using namespace std;

int isok();
int isokt();
char big[ 102 ][ 102 ], small[ 102 ][ 102 ], tmp[ 102 ][ 102 ];
int N, n;
int main()
{
    int i, j, k, l;
    while(~scanf("%d %d", &N, &n) && (N || n))
    {
        getchar();
        for(i = 0; i < N; i++) gets(big[ i ]);
        for(i = 0; i < n; i++) gets(small[ i ]);
        printf("%d", isok());
        k = l = 0;
        for(i = 0; i < n; i++)
        {
            for(j = n - 1; j > -1; j--) tmp[ k ][ l++ ] = small[ j ][ i ];
            k++; l = 0;
        }
        printf(" %d", isokt());
        k = l = 0;
        for(i = 0; i < n; i++)
        {
            for(j = n - 1; j > -1; j--) small[ k ][ l++ ] = tmp[ j ][ i ];
            k++; l = 0;
        }
        printf(" %d", isok());
        k = l = 0;
        for(i = 0; i < n; i++)
        {
            for(j = n - 1; j > -1; j--) tmp[ k ][ l++ ] = small[ j ][ i ];
            k++; l = 0;
        }
        printf(" %d\n", isokt());
    }
    return 0;
}
int isok()
{
    int cou = 0;
    bool ck;
    for(int i = 0; i < N; i++)
    {
        if(i + n > N) return cou;
        for(int j = 0; j < N; j++)
        {
            if(j + n > N) j = N;
            else
            {
                ck = true;
                for(int k = 0; k < n; k++)
                {
                    for(int l = 0; l < n; l++)
                    {
                        if(small[ k ][ l ] != big[k + i][l + j])
                        {
                            k = l = n;
                            ck = false;
                        }
                    }
                }
                if( ck ) cou++;
            }
        }
    }
    return cou;
}
int isokt()
{
    int cou = 0;
    bool ck;
    for(int i = 0; i < N; i++)
    {
        if(i + n > N) return cou;
        for(int j = 0; j < N; j++)
        {
            if(j + n > N) j = N;
            else
            {
                ck = true;
                for(int k = 0; k < n; k++)
                {
                    for(int l = 0; l < n; l++)
                    {
                        if(tmp[ k ][ l ] != big[k + i][l + j])
                        {
                            k = l = n;
                            ck = false;
                        }
                    }
                }
                if( ck ) cou++;
            }
        }
    }
    return cou;
}
