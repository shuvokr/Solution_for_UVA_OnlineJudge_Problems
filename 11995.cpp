#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define Lu unsigned long
#define LLD long long
#define LD long

int main()
{
    int magic = 0, n = 0, x = 0, y = 0, i = 0, mamo;
    while(sf("%d", &n) != EOF)
    {
        stack <int> st;
        queue <int> que;
        priority_queue <int> p_que;

        int ckst, ckque, ckp_que;
        ckst = ckque = ckp_que = 0;
        for(i = 0; i < n; i++)
        {
            sf("%d %d", &x, &y);
            if(x == 1)
            {
                st.push(y);
                que.push(y);
                p_que.push(y);
            }
            else
            {
                if(st.empty()) ckst = 1;
                else
                {
                    mamo =  st.top();
                    st.pop();
                    if(ckst == 0)
                        if(mamo != y)
                            ckst = 1;
                }
                if(que.empty()) ckque = 1;
                else
                {
                    mamo =  que.front();
                    que.pop();

                    if(ckque == 0)
                        if(mamo != y)
                            ckque = 1;
                }
                if(p_que.empty()) ckp_que = 1;
                else
                {
                    mamo =  p_que.top();
                    p_que.pop();

                    if(ckp_que == 0)
                        if(mamo != y)
                            ckp_que = 1;
                }
            }
        }
        magic = ckst + ckque + ckp_que;
        if(magic < 2)
            puts("not sure");
        else if(magic == 3)
            puts("impossible");
        else if(ckst == 0)
            puts("stack");
        else if(ckque == 0)
            puts("queue");
        else puts("priority queue");
    }
    return 0;
}

