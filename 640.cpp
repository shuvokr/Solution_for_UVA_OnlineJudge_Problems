#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define sf scanf
#define pf printf

void save();
int converter(int n);

bool ck[1000001];
const int N = 1000001;

int main()
{
    save();
    return 0;
}
void save()
{
    int i, j, n = 10000, x;
    for(i = 1; i < N; i++) ck[i] = true;

    for(i = 1; i < N; i++)
    {
        x = converter(i);
        if(ck[x]) ck[x] = false;
    }

    for(i = 1; i < N; i++)
        if(ck[i])
            pf("%d\n", i);
}
int converter(int n)
{
    int res = n;
    while(n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}
