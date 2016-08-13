/*
                                    Shuvo
                                    10523
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

void power();
void multy(int nm);
void convertItoC(int nn);
void mul();
void sumty();
void kumty();
void hijibiji();

int N, cou;
char A[3], num1[10000], num2[10000], num3[10000], res[10000], save[10000], temp[10000], sk[10000], shu[10000];
bool ck;

int main()
{
    int i, j, k;
    memset(A, 0, 3);
    while(sf ("%d%s", &N, A) != EOF)
    {
        if(A[0] == '0') puts("0");
        else
        {
            memset(save, 0, sizeof(save));
            memset(num1, 0, sizeof(num1));
            memset(num2, 0, sizeof(num2));
            memset(num3, 0, sizeof(num3));
            memset(res, 0, sizeof(res));
            memset(temp, 0, sizeof(temp));
            memset(sk, 0, sizeof(sk));

            strcpy(save, A);
            int len = strlen(save);
            reverse(save, save + len);

            power();
            len = strlen(save);
            reverse(save, save + len);
            puts(save);
        }
    }
    return 0;
}
void power()
{
    memset(num1, 0, sizeof(num1));
    memset(sk, 0, sizeof(sk));
    strcpy(num1, A);
    strcpy(sk, A);
    for(int i = 2; i <= N; i++)
    {
        multy(i);
    }
}
void multy(int nm)
{
    memset(temp, 0, sizeof(temp));
    cou = 0;
        int len = strlen(num1), ln = strlen(A), i, j, k, tmp, t1, t2, carry = 0;
        k = 0;
    for(j = ln - 1; j >= 0; j--)
    {
       k = 0;
        memset(num2, 0, sizeof(num2));
        t1 = A[j] - 48;
        for(i = len - 1; i >= 0; i--)
        {
            t2 = num1[i] - 48;
            tmp = (t1 * t2) + carry;
            carry = tmp / 10;
            tmp %= 10;
            num2[k++] = tmp + 48;
        }
        while(carry > 0)
        {
            tmp = carry % 10;
            num2[k++] = tmp + 48;
            carry /= 10;
        }
        sumty();
    }
    len = strlen(temp);
    reverse(temp, temp + len);
    memset(num1, 0, sizeof(num1));
    strcpy(num1, temp);

    convertItoC(nm);
    mul();
    //puts(temp);
    hijibiji();
}
void sumty()
{
    int i, j, k = cou, tmp, t, car = 0, len = strlen(num2);
    if(cou == 0) strcpy(temp, num2);
    else
    {
        for(i = 0; i < len; i++)
        {
            if(isdigit(temp[k]))
                t = temp[k] - 48;
            else t = 0;
            tmp = num2[i] - 48;
            tmp = tmp + t + car;
            car = tmp / 10;
            tmp %= 10;
            temp[k++] = tmp + 48;
        }

        while(car > 0)
        {
            t = car % 10;
            temp[k++] = t + 48;
            car /= 10;
        }
    }
    cou++;
}
void convertItoC(int nn)
{
    memset(num3, 0, sizeof(num3));
    int len = log10(nn) + 1, k = 0, i, t;
    for(i = 0; i < len; i++)
    {
        t = nn % 10;
        num3[k++] = t + 48;
        nn /= 10;
    }
}
void mul()
{
    cou = 0;
        int len = strlen(num1), ln = strlen(num3), i, j, k, tmp, t1, t2, carry = 0;
        k = 0;
       // puts(num1);
    for(j = 0; j < ln; j++)
    {
        memset(num2, 0, sizeof(num2));//osdijfodijdlfjgdljgl;dkfgl;dfjgml;dfjkgl
        k = 0;
        t1 = num3[j] - 48;
        for(i = len - 1; i >= 0; i--)
        {
            t2 = num1[i] - 48;
            tmp = (t1 * t2) + carry;
            carry = tmp / 10;
            tmp %= 10;
            num2[k++] = tmp + 48;
        }
        while(carry > 0)
        {
            tmp = carry % 10;
            num2[k++] = tmp + 48;
            carry /= 10;
        }
        kumty();
        //puts(num2);
    }
}
void kumty()
{
    //puts(num2);
    //puts(temp);
    int i, j, k = cou, tmp, t, car = 0, len = strlen(num2);
    //pf("%d\n", len);
    if(cou == 0) strcpy(temp, num2);
    else
    {
        for(i = 0; i < len; i++)
        {
            if(isdigit(temp[k]))
                t = temp[k] - 48;
            else t = 0;
            tmp = num2[i] - 48;
            tmp = tmp + t + car;
            car = tmp / 10;
            tmp %= 10;
            temp[k++] = tmp + 48;
        }
        while(car > 0)
        {
            t = car % 10;
            temp[k++] = t + 48;
            car /= 10;
        }
    }
    //puts(temp);
    cou++;
}
void hijibiji()
{


    int car = 0, len = strlen(temp), i, j = 0, k , t, tt, ln = strlen(save);
    k = 0; j = 0;
    for(i = 0; i < len; i++)
    {
        t = temp[i] - 48;
        if(k < ln)
            tt = save[k] - 48;
        else tt = 0;
        t = t + tt + car;
        car = t / 10;
        t %= 10;
        save[k++] = t + 48;
    }
    while(isdigit(save[k]))
    {
        t = save[k] - 48;
        t = t + car;
        car = t / 10;
        t = t % 10;
        save[k++] = t + 48;
    }
    while(car > 0)
    {
        t = car % 10;
        save[k++] = t + 48;
        car /= 10;
    }
    //puts(save);
}
