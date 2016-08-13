#include <stdio.h>
#include <string.h>

using namespace std;

struct data
{
    char name[ 50 ];
    int atack;
    int defance;
    data() {}
};
int main()
{
    data player[ 50 ], tmp;
    int T, i, j, k, kag = 0;
    scanf("%d", &T);
        while(T--)
        {
            for(i = 0; i < 10; i++)
                scanf("%s %d %d", &player[ i ].name, &player[ i ].atack, &player[ i ].defance);
            for(i = 0; i < 9; i++)
            {
                for(j = i + 1; j < 10; j++)
                {
                    if(player[ i ].atack < player[ j ].atack)
                    {
                        tmp = player[ i ];
                        player[ i ] = player[ j ];
                        player[ j ] = tmp;
                    }
                    else if(player[ i ].atack == player[ j ].atack)
                    {
                        if(player[ i ].defance > player[ j ].defance)
                        {
                            tmp = player[ i ];
                            player[ i ] = player[ j ];
                            player[ j ] = tmp;
                        }
                        else if(player[ i ].defance == player[ j ].defance)
                        {
                            if(strcmp(player[ i ].name, player[ j ].name) > 0)
                            {
                                tmp = player[ i ];
                                player[ i ] = player[ j ];
                                player[ j ] = tmp;
                            }
                        }
                    }
                }
            }
            for(i = 0; i < 4; i++)
            {
                for(j = i + 1; j < 5; j++)
                {
                    if(strcmp(player[ i ].name, player[ j ].name) > 0)
                    {
                        tmp = player[ i ];
                        player[ i ] = player[ j ];
                        player[ j ] = tmp;
                    }
                }
            }
            for(i = 5; i < 9; i++)
            {
                for(j = i + 1; j < 10; j++)
                {
                    if(strcmp(player[ i ].name, player[ j ].name) > 0)
                    {
                        tmp = player[ i ];
                        player[ i ] = player[ j ];
                        player[ j ] = tmp;
                    }
                }
            }
            printf("Case %d:\n(%s", ++kag, player[ 0 ].name);
            for(i = 1; i < 5; i++) printf(", %s", player[ i ].name); printf(")\n(%s", player[ 5 ].name);
            for(i = 6; i < 10; i++) printf(", %s", player[ i ].name); printf(")\n");
        }
    return 0;
}
