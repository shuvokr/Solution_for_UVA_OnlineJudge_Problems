#include <cstdio>
#include <cstring>
void input();
bool isok(int s, int e);

char in[ 100010 ], q[ 1010 ];

int main()
{
    input();

    return 0;
}
void input()
{
    int i, T, quri;
    bool ck;
    scanf("%d", &T); getchar();
    for(int j = 0; j < T; j++)
    {
        gets( in );
        scanf("%d", &quri); getchar();
        for(i = 0; i < quri; i++)
        {
            gets( q );
            ck = isok(0, strlen(q) - 1);
            if( ck ) puts("y");
            else puts("n");
        }
    }
}
bool isok(int s, int e)
{
    int i = s, j = 0, k = strlen( q ) - 1;
    while(j <= k)
    {
        if(in[ s ] != q[ j ] || in[ e ] != q[ k ]) return false;
        j++; s++;
        e--; k--;
    }
    return true;
}
