#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

void input();
bool isok(int n, int base);

int main()
{
    //#ifdef monkey
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    input();

    return 0;
}
void input()
{
    int n, res;
    while(~scanf("%d", &n))
    {
        if(n == 2) {puts("3"); continue;}
        res = 1 << 30;
        int range = sqrt( n ) + 2;
        for(int i = 2; i < range; i++)
        {
            if(isok(n, i))
            {
                res = i;
                break;
            }
            if(n % i == 0)
            {
                int b = n / i;
                b--;
                if(b > i)
                res = res < b ? res : b;
            }
        }
        res = res == 1 << 30 ? n - 1 : res;
        printf("%d\n", res);
    }
}
bool isok(int n, int base)
{
    int k = n;
    vector <int> v;
    while( k )
    {
        v.push_back(k % base);
        k /= base;
    }
    int l = 0, h = v.size() - 1;
    while(l < h)
    {
        if(v[ l ] != v[ h ]) return false;
        l++;
        h--;
    }
    return true;
}
