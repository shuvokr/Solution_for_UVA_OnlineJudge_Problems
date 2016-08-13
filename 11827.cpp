#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long
#define fo(i, n) for(i = 0; i < n; i++)


int GCD(int a,int b)
{
    int c;
    if(a > b)
    {
        while(b != 0)
        {
            c = b;
            b = a % b;
            a = c;
        }
    }
    else
    {
        while(a != 0)
        {
            c = a;
            a = b % a;
            b = c;
        }
    }
    return c;
}


int main()
{
    int T, max, len, i, j, temp, sk;
    sf("%d", &T);
    getchar();
    string str;
    while(T--)
    {
        //vector <unsigned long long> Input;
        int Input[100];
        char c = NULL;
        max = 0;
        len = 0;
        /*do
        {
            sf("%llu%c", &sk, &c);
            Input.push_back(sk);
            len++;
        }
        while(c == 32);*/

        getline(cin, str);
        stringstream ss(str);
        while(ss >> Input[len]) len++;

        for(i = 0; i < len - 1; i++)
            for(j = i + 1; j < len; j++)
            {
                temp = GCD(Input[i], Input[j]);
                if(max < temp) max = temp;
            }
        pf("%d\n", max);
    }
    return 0;
}
