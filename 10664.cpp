#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

#define pf printf
#define sf scanf
#define llu unsigned long long int

/*************************************************/
int dp(int pos, int waight);
int len, mamo[ 25 ][ 102 ], target, array[ 25 ];
bool mark;
int main()
{
    freopen("input.txt", "r",stdin);
    char in[ 100 ];
    int sum, i, j, T;
    sf("%d", &T);
    getchar();
    while(T--)
    {
        gets( in ); sum = j = 0;
        char * tok = strtok( in, " " );
        while(tok != NULL)
        {
            array[ j ] = atoi( tok );
            sum += array[ j++ ];
            tok = strtok(NULL, " ");
        }
        if((sum % 2))
        {
            puts("NO");
            continue;
        }
        target = sum / 2; len = j;
        memset(mamo, -1, sizeof mamo);
        mark = false;
        i = dp(0, 0);
        //printf("%d %d\n", i, target);
        puts(mark ? "YES" : "NO");
    }
    return 0;
}
int dp(int pos, int waight)
{
    if(pos == len || mark) return 0;
    if(waight == target) mark = true;
    if(mamo[ pos ][ waight ] != -1) return mamo[ pos ][ waight ];
    int a = 0, b = 0;
    if(array[ pos ] + waight <= target)
        a = array[ pos ] + dp(pos + 1, waight + array[ pos ] );
    b = dp(pos + 1, waight);
    mamo[ pos ][ waight ] = a > b ? a : b;
    return mamo[ pos ][ waight ] ;
}
