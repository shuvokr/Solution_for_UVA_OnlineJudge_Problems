#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct data
{
    string num;
}in[ 55 ];
bool cmp(const data &x, const data &y)
{
    string a, b;
    a = x.num + y.num;
    b = y.num + x.num;
    return (a > b);
}
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i++) cin >> in[ i ].num;
        sort(in, in + n, cmp);
        for(int i = 0; i < n; i++) cout << in[ i ].num;
        puts("");
    }
    return 0;
}
