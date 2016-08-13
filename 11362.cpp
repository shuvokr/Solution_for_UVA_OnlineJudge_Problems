/*
    Shuvo
    Problem no: 11362. Problem name: Phone List
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
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, -1, sizeof(n))

int input();
bool cheak(string a,string b);

int main()
{
    input();

    return 0;
}
int input()
{
    int len, Elen, i, j, tmp, T, n, cou;
    string phon_number[10101];
    bool ck;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);

        fo(i, n)
            cin >> phon_number[i];

        sort(phon_number, phon_number+n);

        ck = true;
        for(i = 0; i < n - 1; i++)
        {
            if(cheak(phon_number[i], phon_number[i+1]))
            {
                ck = false;
                break;
            }
        }
        if(ck) puts("YES");
        else puts("NO");
    }
}
bool cheak(string a,string b)
 {
     int i;
     if(a.size() > b.size())
             return false;
     for(i = 0; i < a.length(); i++)
       {
           if(a[i] != b[i])
           return false;
       }
     return true;
 }
