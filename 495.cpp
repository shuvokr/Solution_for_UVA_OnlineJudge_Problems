/*
                                    Shuvo
                                      495
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define lu unsigned long int
#define llu unsigned long long int
#define lld long long int
#define sf scanf
#define pf printf

char num[5005][10000], tmp[10000], num1[10000], res[10000];

void saveresult();
void Febonacci(char ch1[], char ch2[]);

int main()
{
    memset(num, 0, sizeof(num));
    num[0][0] = '0'; num[1][0] = '1'; num[2][0] = '1'; num[3][0] = '2'; num[4][0] = '3'; num[5][0] = '5';
    memset(num1, 0, sizeof(num1));
    memset(tmp, 0, sizeof(tmp));
    memset(res, 0, sizeof(res));
    num1[0] = '3';
    tmp[0] = '5';

    saveresult();

    int n;
    while(sf ("%d", &n) != EOF)
    {
        pf ("The Fibonacci number for %d is ", n);
        puts(num[n]);
    }
}
void saveresult()
{
    int len, i, k;
    for(i = 6; i < 5001; i++)
    {
        Febonacci(tmp, num1);
        len = strlen(res);
        for(k = 0; k < len; k++)
            num[i][k] = res[k];
        strcpy(num1, tmp);
        strcpy(tmp, res);
    }
}
void Febonacci(char ch1[], char ch2[])
{
    int k = 0, carry = 0, ln = strlen(ch2), len = strlen(ch1), ii, jj, ttmp, skk, tt;
    for(ii = len - 1; ii >= 0; ii--)
    {
        ttmp = ch1[ii] - 48;
        if(ln > 0)
            tt = ch2[--ln] - 48;
        else tt = 0;
        tt += (ttmp + carry);
        carry = tt / 10;
        tt %= 10;
        res[k++] = tt + 48;
    }
    if(carry > 0)
    {
        tt = carry % 10;
        carry /= 10;
        res[k++] = tt + 48;
    }
    reverse(res, res + k);
}
