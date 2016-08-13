#include<stdio.h>
#include<string.h>

using namespace std;

#define VALU 1003

int main()
{
    int i, j, k, ck, MAX, c[VALU][VALU], len1, len2;
    char ar1[VALU], ar2[VALU];
    while(gets(ar1))
    {
        gets(ar2);
        len1 = strlen(ar1);
        len2 = strlen(ar2);
        if(len1 > len2) MAX = len1;
        else MAX = len2;
        for(i = 0; i < MAX; i++) c[i][0] = c[0][i] = 0;

        for(i = 1; i <= len1; i++)
        {
            for(j = 1; j <= len2; j++)
            {
                if(ar1[i-1] == ar2[j-1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else if(c[i-1][j] >= c[i][j-1])
                    c[i][j] = c[i-1][j];
                else c[i][j] = c[i][j-1];
            }
        }
        printf("%d\n", c[len1][len2]);
    }
    return 0;
}
