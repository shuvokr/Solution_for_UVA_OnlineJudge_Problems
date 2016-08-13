/*
    Shuvo
    Problem name : Batman
    Problem ID : 11514
    Problem algo: 0/1 Knapsak (Classic DP)
*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int i, j, batman_atack[ 1002 ], batman_calori[ 1002 ], dp[ 1002 ][ 1002 ], var[ 1002 ];
bool betal_coulification[ 1002 ][ 1002 ];
map <string, int> mapping;
char name[ 102 ];

int main()
{

    int hero, vollain, max_calori, tmp;
    while(~scanf("%d %d %d", &hero, &vollain, &max_calori))
    {
        if(!hero && !vollain && !max_calori) break;
        hero++; vollain++;
        mapping.clear();
        for(i = 0; i < vollain; i++)
            for(j = 0; j < hero; j++)
            {   if( !i ) dp[ i ][ j ] = 0;
                else dp[ i ][ j ] = 1e9;
                betal_coulification[ i ][ j ] = false;
            }

        for(i = 1; i < hero; i++)
        {
            scanf("%s %d %d", name, &batman_atack[ i ], &batman_calori[ i ]);
            mapping[ name ] = i;
        }

        for(j = 1; j < vollain; j++)
        {
            scanf("%*s %d %[^,\n]", var + j, name);
            do
            {
                i = mapping[ name ];
                betal_coulification[ j ][ i ] = batman_atack[ i ] >= var[ j ] ? true : false;
            }while(scanf(",%[^,\n]", name) == 1);
        }
        for(i = 1; i < vollain; i++)
            for(j = 1; j < hero; j++)
            {
                dp[ i ][ j ] = dp[ i ][j - 1];
                if(betal_coulification[ i ][ j ])
                    dp[ i ][ j ] = dp[ i ][ j ] < dp[i - 1][j - 1] + batman_calori[ j ] ? dp[ i ][ j ] : dp[i - 1][j - 1] + batman_calori[ j ];
            }

        puts(dp[vollain - 1][hero - 1] <= max_calori ? "Yes" : "No");
    }
    return 0;
}
