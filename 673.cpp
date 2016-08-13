#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<stack>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf

int main()
{
    char ch[130];
    int T, len, i, ck;
    sf("%d",&T);
    getchar();
    while(T--)
    {
        stack <char> st;
        gets(ch);
        len = strlen(ch);
        if(ch[0] == '\n') puts("yes");
        else if(len % 2 != 0) puts("No");
        else{
        ck = 0;
        for(i = 0; i < len; i++)
        {
            if(ch[i] == '(' || ch[i] == '[')
                st.push(ch[i]);
            else if(ch[i] == ')' && !st.empty() && st.top() == '(')
                st.pop();
            else if(ch[i] == ']' && !st.empty() && st.top() == '[')
                st.pop();
            else ck = 1;
        }
        if(st.empty() && ck == 0) puts("Yes");
        else puts("No");
        }
    }

    return 0;
}
