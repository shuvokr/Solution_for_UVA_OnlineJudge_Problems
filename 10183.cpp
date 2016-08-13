/*
                                    Shuvo
                                    10183
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

char num[500][1000], tmp[1000], num1[1000], res[1000];

void saveresult();
void Febonacci(char ch1[], char ch2[]);
void compare(char x[], char y[]);

int cou;

int main()
{
    //***************************
    memset(num, 0, sizeof(num));
    num[0][0] = '0'; num[1][0] = '1'; num[2][0] = '1'; num[3][0] = '2'; num[4][0] = '3'; num[5][0] = '5';
    memset(num1, 0, sizeof(num1));
    memset(tmp, 0, sizeof(tmp));
    memset(res, 0, sizeof(res));
    num1[0] = '3';
    tmp[0] = '5';
    //***************************

    saveresult();

    char n1[102], n2[102];
    while(sf ("%s%s", n1, n2) != EOF)
    {
        if(n1[0] == '0' && n2[0] == '0') return 0;
        compare(n1, n2);
        pf("%d\n", cou);
    }
}
void saveresult()
{
    int len, i, k;
    for(i = 6; i < 500; i++)
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
void compare(char x[], char y[])
{
    cou = 0;
    int tmp, len1, len2, i, j, k;
    bool ck = true;

    len1 = strlen(x);
    for(i = 2; i < 500; i++)
    {
        len2 = strlen(num[i]);
        if(strcmp(num[i], x) == 0) break;
        if(len1 == len2)
        {
            ck = true;
            for(j = 0; j < len1; j++)
            {
                if(num[i][j] == x[j]) int shuvo;
                else if(num[i][j] < x[j]) break;
                else if(num[i][j] > x[j]) {ck = false; break;}
            }
        }
        if(!ck) break;
        else if(len2 > len1) break;
    }

    tmp = i;
    len1 = strlen(y);
    for(i = tmp; i < 500; i++)
    {
        len2 = strlen(num[i]);
        if(len2 < len1) cou++;
        else if(len2 > len1) return;
        else
        {
            if(strcmp(num[i], y) == 0)
            {
                cou++; return;
            }
            ck = true;
            for(j = 0; j < len1; j++)
            {
                if(y[j] == num[i][j]) int ss;
                if(y[j] < num[i][j]) return;
                else if(y[j] > num[i][j])
                {
                    cou++; break;
                }
            }
        }
    }
}

