#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define sf scanf
#define pf printf

void input(char inp[]);
void mul (char str[]);
void sum(char st[]);

char stor1[150], res1[150], inp[150], inpu[150], tm1[150], tmp[150], sav[150], fres1[150];

int n, len, i, j, k, lnn, a, ln, car, x, y, z, ii, jj, sh, s, ss, shuvo, shu, as;

int main()
{
    memset(inp, 0, sizeof(inp));
    while(gets(inp))
    {
        memset(tm1, 0, sizeof(tm1));
        memset(fres1, 0, sizeof(fres1));
        memset(res1, 0, sizeof(res1));
        input(inp);
    }
    return 0;
}

void input(char in[])
{
    shuvo = -3;
    memset(fres1, 0, sizeof(fres1));
    sscanf(in,"%s%d", inpu, &n);
    if(n == 1)
    {
        puts(inpu);
        return;
    }
    else
    {
        len = strlen(inpu);
        k = 0;
        for(i = 0; i < len; i++)
            if(isdigit(inpu[i]))
              tm1[k++] = inpu[i];
            else shuvo = i;
        if(shuvo != -3)
        shuvo = (len - shuvo) - 1;
        lnn = strlen(tm1);
        strcpy(tmp, tm1);
        strcpy(res1, tm1);
        mul(res1);
        for(a = 2; a < n; a++)
        {
            memset(res1, 0, sizeof(res1));
            sh = strlen(fres1);
            s = 0;
            for(ss = sh - 1; ss >= 0; ss--)
                res1[s++] = fres1[ss];
            memset(fres1, 0, sizeof(fres1));
            mul(res1);
        }
        //puts(fres1);
        memset(stor1, 0, sizeof(stor1));
        sh = strlen(fres1);
        shuvo *= n;
        as = 0;
        shu = 0;
        for(s = 0; s < sh; s++)
        {
            as++;
            if(shuvo + 1 != as)
            {
                stor1[shu++] = fres1[s];
            }
            else
            {
                stor1[shu++] = 46;
                stor1[shu++] = fres1[s];
            }
        }
        s = 0;
        if(stor1[0] == '0')
        for(s = 0; s < shu; s++)
        {
            if(stor1[s] != '0')
                break;
        }
        if(inpu[0] != '0')
        {
            for(ss = shu - 1; ss >= s; ss--)
                pf("%c", stor1[ss]);
            puts("");
        }
        else
        {
            for(ss = shu - 2; ss >= s; ss--)
                pf("%c", stor1[ss]);
            puts("");
        }
        memset(fres1, 0, sizeof(fres1));
    }
}
void mul(char str[])
{
    int lent, sk;
    len = strlen(str);
    int temp, t, carry = 0;
    k = 0;
    x = 0;
    for(j = lnn - 1; j >= 0; j--)
    {
        k = 0;
        memset(sav, 0, sizeof(sav));
        if(isdigit(tm1[j]))
            t = tm1[j] - 48;
        for(i = len - 1; i >= 0; i--)
        {
            if(isdigit(str[i]))
                temp = str[i] - 48;
            temp *= t;
            temp += carry;
            carry = temp / 10;
            temp %= 10;
            sav[k++] = temp + 48;
        }
        if(carry > 0)
        {
            lent = log10(carry) + 1;
            for(sk = 0; sk < lent; sk++)
            {
                temp = carry % 10;
                sav[k++] = temp + 48;
                carry /= 10;
            }
        }
        //puts(sav);
        sum(sav);
    }
}
void sum(char st[])
{
    car = y = 0;
    z = x;
    int kk;
    ln = strlen(st);
    for(ii = 0; ii < ln; ii++)
    {
        if(isdigit(fres1[z]))
            y = fres1[z] - 48;
        else y = 0;
        if(isdigit(st[ii]))
            kk = st[ii] - 48;
        else kk = 0;
        kk = kk + y + car;
        car = kk / 10;
        kk = kk % 10;
        fres1[z++] = kk + 48;
    }
    if(car > 0)
    {
        //pf("%d\n", car);
        int sk, lent = log10(car) + 1;
        for(sk = lent - 1; sk >= 0; sk--)
        {
            kk = car % 10;
            fres1[z++] = kk + 48;
            car /= 10;
        }
    }
    //puts(fres1);
    x++;
}
