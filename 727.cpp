#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    char c[2];
    int cont = 0, T;
    void *p;
    string res = "";
    sf("%d", &T);
    gets(c);
    gets(c);
    while(T--)
    {
        res = "";
        stack <char> st;
        while(1)
        {
            p = gets(c);
            if (p == NULL) break;
            if (c[0] == '\0') break;
            if (isdigit(c[0])) res += c[0];
            else
            {
                if (c[0] == ')')
                {
                    while(st.top() != '(')
                    {
                        res += st.top();
                        st.pop();
                    }
                st.pop();
                continue;
                }
                if (c[0] == '(')
                {
                    st.push(c[0]);
                    continue;
                }
                if(c[0] != '*' && c[0] != '/' && c[0] != '+' && c[0] != '-') continue;
                if (st.empty())
                {
                    st.push(c[0]);
                    continue;
                }
                while(!st.empty() && st.top() != '(' && ((st.top() == '*' || st.top() == '/')
                || !((st.top() == '+' || st.top() == '-') && (c[0] == '*' || c[0] == '/'))))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c[0]);
            }
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        if(T == 0)
        printf("%s\n", res.c_str());
        else
        printf("%s\n\n", res.c_str());
    }
    return 0;
}

