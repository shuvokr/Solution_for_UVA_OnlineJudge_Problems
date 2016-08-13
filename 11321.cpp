/*
#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int num, modul;
}in[ 10010 ];
bool operator< (const data &a, const data &b)
{
    if(a.modul < b.modul) return true;
    if(a.modul == b.modul)
    {
        int x, y;
        x = a.num % 2 != 0 ? 1 : 0;
        y = b.num % 2 != 0 ? 1 : 0;
        if(x == 1 && !y) return true;
        else if(x == 1 && y == 1 && b.num < a.num) return true;
        else if(!x && !y && a.num < b.num) return true;
    }
    return false;
}
int main()
{
    int n, mod, tmp;
    while(~scanf("%d %d", &n, &mod) && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &in[ i ].num);
            in[ i ].modul = in[ i ].num % mod;
        }
        sort(in, in + n);
        printf("%d %d\n", n, mod);
        for(int i = 0; i < n; i++) printf("%d\n", in[ i ].num);
    }
    puts("0 0");
    return 0;
}
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int num, modul;
};
bool cmp(const data &a, const data &b)
{
    if(a.modul < b.modul) return true;
    if(a.modul == b.modul)
    {
        int x, y;
        x = a.num % 2 != 0 ? 1 : 0;
        y = b.num % 2 != 0 ? 1 : 0;
        if(x == 1 && !y) return true;
        else if(x == 1 && y == 1 && a.num > b.num) return true;
        else if(!x && !y && a.num < b.num) return true;
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, mod, tmp;
    data in[ 10010 ];
    while(~scanf("%d %d", &n, &mod) && n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &in[ i ].num);
            in[ i ].modul = in[ i ].num % mod;
        }
        sort(in, in + n, cmp);
        printf("%d %d\n", n, mod);
        for(int i = 0; i < n; i++) printf("%d\n", in[ i ].num);
    }
    puts("0 0");
    return 0;
}
