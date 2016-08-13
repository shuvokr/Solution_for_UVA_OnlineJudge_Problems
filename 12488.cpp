#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

#define sf scanf
#define pf printf

int main()
{
    int n = 0, m = 0, i, j, k;
    while(sf("%d", &n) != EOF)
    {
        vector <int> start;
        vector <int> end;

        for(i = 0; i < n; i++)
        {
            sf("%d", &m);
            start.push_back(m);
        }

        for(i = 0; i < n; i++)
        {
            sf("%d", &m);
            end.push_back(m);
        }

        int count = 0, temp;

        for(i = 0; i < n; i++)
        {
            if(start[i] != end[i])
            {
                for(j = i + 1; j < n; j++)
                    if(start[j] == end[i])
                    {
                        temp = j;
                        continue;
                    }
                for(k = temp; k > i; k--)
                {
                    start[k] = start[k - 1];
                    start[k - 1] = end[i];
                    count++;
                }
            }
        }
        pf("%d\n", count);
    }
    return 0;
}
