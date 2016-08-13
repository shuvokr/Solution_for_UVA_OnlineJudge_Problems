/*********************************************
    Shuvo
    Problem Name: Page Hopping
    Problem ID: 821
    Problem Algo: Floyd Warshall (APSP)
**********************************************/
#include <cstdio>
#include <cstring>
int main()
{
    int len, adm[ 102 ][ 102 ], u, v, cost, pr, kag = 0;
    while(~scanf("%d %d", &u, &v) && u)
    {
        for(int i = 1; i < 101; i++)
            for(int j = 1; j < 101; j++) adm[ i ][ j ] = 10010;
        len = 0;
        do
        {
            adm[ u ][ v ] = 1;
            len = u < len ? len : u;
            len = v < len ? len : v;
        }while(~scanf("%d %d", &u, &v) && u);
        len++;
        //Floyd Warshall
        for(int k = 1; k < len; k++)
            for(int i = 1; i < len; i++)
                for(int j = 1; j < len; j++)
                    adm[ i ][ j ] = adm[ i ][ j ] < adm[ i ][ k ] + adm[ k ][ j ] ? adm[ i ][ j ] : adm[ i ][ k ] + adm[ k ][ j ];
        cost = pr = 0;
        for(int i = 1; i < len; i++)
            for(int j = 1; j < len; j++)
                if(i == j) continue;
                else  if(adm[ i ][ j ] != 10010) cost += adm[ i ][ j ], pr++;
        printf("Case %d: average length between pages = %.3f clicks\n", ++kag, (float)cost / (float)pr);
    }
    return 0;
}
