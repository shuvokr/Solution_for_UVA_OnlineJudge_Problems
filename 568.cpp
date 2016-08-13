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
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
void mul(char str1[], char str2[]);
void sum(char str[]);

char fres[10002][1], in1[100000], in2[100000], ch1[100000], ch2[100000], tmp[100000], res[100000];
int shu = 0;


/*
my calculaton way
Just a example
How i multiply two number
    123
     56
.............
    738
   615*
..............
   6888 // Final result
*/

int main()
{
    fres[0][0] = '1';
    fres[1][0] = '1';
    fres[2][0] = '2';

    //******************************
    // this part for Send the last result and the number
    memset(res, 0, sizeof(res));
    res[0] = '2';
    for(int z = 3; z <= 10000; z++) // i make fagtorial for 1 to 1000
    {
        memset(in1, 0, sizeof(in1));
        int a, b, c, d = z, e = 0;
        a = log10(d) + 1;
        for(b = 0; b < a; b++)
        {
            c = d % 10;
            in1[e++] = c + 48;
            d /= 10;
        }
        b = 0;

        for(a = e - 1; a >= 0; a--)
            in2[b++] = in1[a];

        memset(ch1, 0, sizeof(ch1));
        a = strlen(res);
        b = 0;
        if(a <= 3)
        {
            e = 0;
            for(int sss = a - 1; sss >= 0; sss--)
                ch1[e++] = res[sss];
        }
        else
        {
            int sss, nnn = strlen(res);
            sss = 0;
            for(sss = 0; sss < nnn; sss++)
                if(res[sss] != '0')
                    break;

            if(a - (sss + 1) >= 8)
            {
                ch1[0] = res[sss + 8];
                ch1[1] = res[sss + 7];
                ch1[2] = res[sss + 6];
                ch1[3] = res[sss + 5];
                ch1[4] = res[sss + 4];
                ch1[5] = res[sss + 3];
                ch1[6] = res[sss + 2];
                ch1[7] = res[sss + 1];
                ch1[8] = res[sss];
            }
            else if(a - (sss + 1) == 7)
            {
                ch1[0] = res[sss + 7];
                ch1[1] = res[sss + 6];
                ch1[2] = res[sss + 5];
                ch1[3] = res[sss + 4];
                ch1[4] = res[sss + 3];
                ch1[5] = res[sss + 2];
                ch1[6] = res[sss + 1];
                ch1[7] = res[sss];
            }
            else if(a - (sss + 1) == 6)
            {
                ch1[0] = res[sss + 6];
                ch1[1] = res[sss + 5];
                ch1[2] = res[sss + 4];
                ch1[3] = res[sss + 3];
                ch1[4] = res[sss + 2];
                ch1[5] = res[sss + 1];
                ch1[6] = res[sss];
            }
            else if(a - (sss + 1) == 5)
            {
                ch1[0] = res[sss + 5];
                ch1[1] = res[sss + 4];
                ch1[2] = res[sss + 3];
                ch1[3] = res[sss + 2];
                ch1[4] = res[sss + 1];
                ch1[5] = res[sss];
            }
            else if(a - (sss + 1) == 4)
            {
                ch1[0] = res[sss + 4];
                ch1[1] = res[sss + 3];
                ch1[2] = res[sss + 2];
                ch1[3] = res[sss + 1];
                ch1[4] = res[sss];
            }
            else if(a - (sss + 1) == 3)
            {
                ch1[0] = res[sss + 3];
                ch1[1] = res[sss + 2];
                ch1[2] = res[sss + 1];
                ch1[3] = res[sss];
            }
            else if(a - (sss + 1) == 2)
            {
                ch1[0] = res[sss + 2];
                ch1[1] = res[sss + 1];
                ch1[2] = res[sss];
            }
            else if(a - (sss + 1) == 1)
            {
                ch1[0] = res[sss + 1];
                ch1[1] = res[sss];
            }
            else if(a - (sss + 1) == 0)
                ch1[0] = res[sss];
        }

        memset(res, 0, sizeof(res));
        //if(z == 3125) puts(in2);
        //if(z == 3125) puts(ch1);
        mul(ch1, in2); // send the last result and the number .. Example  last Result(24) & num (5)
        //puts(res);
        b = 0;
        while(1)
        {
            if(res[b] != '0') break;
            b++;
        }
        fres[z][0] = res[b];
    }
    //******************************
    int n;
    while(sf("%d", &n) != EOF)
        pf("%5d -> %c\n", n, fres[n][0]);
    return 0;
}
void mul(char str1[], char str2[])
{
    shu = 0;
    int len1 = strlen(str1), len2 = strlen(str2), i, j, k = 0, t, tt, car = 0;
    for(i = len2 - 1; i >= 0; i--)
    {
        k = 0;
        for(j = len1 - 1; j >= 0; j--)
        {
            t = str2[i] - 48;
            tt = str1[j] - 48;
            t = t * tt ;
            t = t + car;
            car = t / 10;
            t = t % 10;
            tmp[k++] = t + 48;
        }
        if(car > 0)
        {
            int sk, lent = log10(car) + 1;
            for(sk = lent - 1; sk >= 0; sk--)
            {
                t = car % 10;
                tmp[k++] = t + 48;
                car /= 10;
            }
        }
        sum(tmp);
        memset(tmp, 0, sizeof(tmp));
        shu++;
    }
}
void sum(char str[])
{
    int i, j, k, t, tt, car = 0, len = strlen(str);
    k = shu;
    for(i = 0; i < len; i++)
    {
        t = str[i] - 48;
        if(isdigit(res[k]))
            tt = res[k] - 48;
        else tt = 0;
        t = t + tt + car;
        car = t / 10;
        t = t % 10;
        res[k++] = t + 48;
    }
    if(car > 0)
    {
        int sk, lent = log10(car) + 1;
        for(sk = lent - 1; sk >= 0; sk--)
        {
            t = car % 10;
            res[k++] = t + 48;
            car /= 10;
        }
    }
}
