#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define LU unsigned long
#define fo(i,n) for(i = 0; i < n; i++)

int main()
{
    int n, s, i, len;
    char ch[1002];
    memset(ch, 0, sizeof(ch));
    while(gets(ch))
    {
        s = 0;
        len = strlen(ch);
        if(ch[0] == '0' && len == 1) return 0;
        fo(i, len){
            s = (s * 10 + (ch[i] - 48)) % 11;
            //pf("%d\n", s);
        }
        if(s == 0) pf("%s is a multiple of 11.\n", ch);
        else pf("%s is not a multiple of 11.\n", ch);
    }
}
