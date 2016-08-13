#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    list <int> vr;
    int n, i, temp;
    while(sf("%d" , &n) != EOF)
    {
        vr.clear();
        bool flag = true;
        if(n == 0) return 0;
        for(i = n; i >= 1; i--)
            vr.push_front(i);
        if(n == 1)
        {
            temp = vr.front();
            pf("Discarded cards:\nRemaining card: %d\n", temp);
        }
        else
        {
            pf("Discarded cards:");

            while(vr.size() > 1)
            {
                if(flag)
                {
                    flag = false;

                    temp = vr.front();
                    pf(" %d", temp);
                    vr.pop_front();
                    temp = vr.front();
                    vr.pop_front();
                    vr.push_back(temp);
                }
                else
                {
                    temp = vr.front();
                    pf(", %d", temp);
                    vr.pop_front();
                    temp = vr.front();
                    vr.pop_front();
                    vr.push_back(temp);
                }
                if(vr.size() == 1) puts("");
            }
            temp = vr.front();
            pf("Remaining card: %d\n", temp);
        }
    }
}
