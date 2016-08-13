#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char ch[42][102], c[102];
    int n, t, i;
    scanf("%d", &n);
    getchar();
    n *= 2;
    for(i = 0; i < n; i++)
        gets(ch[i]);
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        gets(c);
        for(i = 0; i < n; i++)
            if(strcmp(ch[i], c) == 0)
            {
                puts(ch[i+1]);
                break;
            }
    }
    return 0;
}
