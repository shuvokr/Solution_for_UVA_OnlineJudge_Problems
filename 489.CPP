#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int contest(char a[], char b[])
{
    int f = 0, ck[100], count = 0, i = 0, j = 0, k = 0, guess[50] = {0}, stroke = 0;
    memset(ck, 0, sizeof(ck));
    int len1 = strlen(a), len2 = strlen(b);
    for(i = 0; i < len2; i++)
    {
        for(j = 0; j < len1; j++)
        {
            if(b[i] == a[j] && !ck[j])
            {
                ck[j] = 1;
                f = 1;
                guess[i] = 1;
                count++;
                if(count == len1) return 2;
           }
        }
        if(!f) stroke++;
        f = 0;
        if(stroke >= 7) return 0;
    }
    return 1;
}

int main()
{
    int n, flag;
    char ans[100], gu[100];
    while(scanf("%d",&n) != EOF)
    {
        if(n == -1) return 0;
        scanf("%s %s",ans,gu);
        flag = contest(ans, gu);

        printf("Round %d\n",n);
        if(flag == 2)
            puts("You win.");
        else if(flag == 1)
            puts("You chickened out.");
        else
            puts("You lose.");
    }
}
