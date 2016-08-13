#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

#define sf scanf
#define pf printf
#define pf printf
#define LL unsigned long long
#define L long long

int main()
{
    int n, ck_num;
    while(sf("%d", &n) != EOF)
    {
        vector <int> array ;
        if(n == 0) return 0;
        bool chaker = false;
        while(n--)
        {
            sf("%d", &ck_num);
            if(ck_num != 0)
            {
                array.push_back(ck_num);
                chaker = true;
            }
        }
        if(chaker)
        {
            pf("%d", array[0]);
            for(int i = 1; i < array.size(); i++)
                pf(" %d", array[i]);
            pf("\n");
        }
        else puts("0");
    }
}
