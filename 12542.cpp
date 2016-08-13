/*
                                            Shuvo
                                            12542
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
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define max 99999

void isprime();
void convertCtoI(char ch[]);

int mx, ck;
bool cheak[max];

int main()
{
    isprime();
    char num[256], temp[7];
    int i, j, k, len, cou, t;
    while(gets(num))
    {
        mx = 0;
        len = strlen(num);
        if(len == 1 && num[0] == '0') return 0;
        cou = 1;
        for(i = 0; i < len;)
        {
            if(num[i] != '0')
            {
                memset(temp, 0, sizeof(temp));
                k = 0;
                for(j = i; j < i + cou; j++)
                {
                    temp[k++] = num[j];
                }
                convertCtoI(temp);
                if(cheak[ck])
                    if(mx < ck)
                        mx = ck;
                cou++;
                if(cou == 6 || cou == len + 1) i++, cou = 1;
                if(i == len || cou == len + 1) break;
            }
            else i++;
        }
        pf("%d\n", mx);
    }
}
void isprime()
{
    int i, j, N = 99998, nsqrt;
    nsqrt = sqrt(N);
    for(i = 0; i <99998; i++) cheak[i] = true;
    for(i = 2; i <= nsqrt; i++)
        for(j = i * i; j < 99998; j += i)
            if(cheak[j]) cheak[j] = false;
    int k = 0;
    cheak[0] = false;
    cheak[1] = false;
}
void convertCtoI(char ch[])
{
    sscanf(ch, "%d", &ck);
}
