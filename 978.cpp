/*
                                            Shuvo
                                              978
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    int i, F, G, B, n, temp[10050][2], T, cou, res;
    priority_queue <int> Gr;
    priority_queue <int> Bl;

    sf("%d", &T);
    while(T--)
    {
        sf("%d%d%d", &F, &G, &B);
        for(i = 0; i < G; i++) sf("%d", &n), Gr.push(n);
        for(i = 0; i < B; i++) sf("%d", &n), Bl.push(n);

        while(!Gr.empty() && !Bl.empty())
        {
            cou = 0;
            while(!Gr.empty() && !Bl.empty() && cou < F)
            {
                temp[cou][0] = Gr.top();
                    Gr.pop();
                temp[cou][1] = Bl.top();
                    Bl.pop();

                cou++;
            }

            while(cou--)
            {
                res = temp[cou][0] - temp[cou][1];
                if(res > 0) Gr.push(res);
                else if(res < 0) Bl.push(-res);
            }
        }

        if(!Gr.empty())
        {
            puts("green wins");
            while(!Gr.empty()) pf("%d\n", Gr.top()), Gr.pop();
        }
        else if(!Bl.empty())
        {
            puts("blue wins");
            while(!Bl.empty()) pf("%d\n", Bl.top()), Bl.pop();
        }
        else puts("green and blue died");

        if(T != 0) puts("");
    }
    return 0;
}
