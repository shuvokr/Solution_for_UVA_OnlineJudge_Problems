#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

void mul(int n);
void mul2(int n);
void mul3(int n);
void pre(int n);
void pre1(int n);
void pre2(int n);


bool ck;
struct data
{
    int num[10];
};
data save[367];

char ch[800];
char ch1[800], ch2[800], ch3[800];

int main()
{
    ck = true;
    save[1].num[1] = 1;
    save[2].num[2] = 1;
    save[3].num[6] = 1;
    save[4].num[2] = 1;
    save[4].num[4] = 1;
    save[5].num[1] = 1;
    save[5].num[2] = 1;
    save[5].num[0] = 1;
    save[6].num[0] = 1;
    save[6].num[2] = 1;
    save[6].num[7] = 1;

    memset(ch, 0, sizeof(ch));
    ch[0] = 7 + 48;
    ch[1] = 2 + 48;
    ch[2] = 0 + 48;

    int i, n;
    for(i = 7; i < 367; i++) // seave ......................
    {
        if(i < 10) mul(i);
        else if(i > 9 && i < 367) mul2(i);
        else if (i > 99) mul3(i);
    }
    while(sf("%d", &n) != EOF)
    {
        if(n == 0) return 0;
        pf("%d! --\n   ", n);
        for(i = 0; i < 5; i++)
        {
            pf("(%d)",i);
            pf("%4d", save[n].num[i]);
            if(i != 4)
            {
                pf("    ");
            }
        }
        puts("");
        pf("   ");
        for(i = 5; i < 10; i++)
        {
            pf("(%d)",i);
            pf("%4d", save[n].num[i]);
            if(i != 9)
            {
                pf("    ");
            }
        }
        puts("");
    }
}

void mul(int n)
{
    char c[800];
    memset(c, 0, sizeof(c));
    strcpy(c, ch);
    int carry, i, j, t, tt, ttt, len;
    len = strlen(c);
    memset(ch, 0, sizeof(ch));
    carry = 0, j = 0;
    i = len - 1;
    for(; i >= 0; i--)
    {
        t = ((c[i] - 48) * n) + carry;
        tt = t % 10;
        ch[j++] = tt + 48;
        carry = t / 10;
    }
    if(carry > 0)
    {
        len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            t = carry % 10;
            carry /= 10;
            ch[j++] = t + 48;
        }
    }

    reverse(ch, ch + j);
    for(i = 0; i < j; i++)
        save[n].num[ch[i] - 48]++;
}

void mul2(int n)
{
    int one, two;
    one = n % 10;
    two = n / 10;
    memset(ch1, 0, sizeof(ch1));
    memset(ch2, 0, sizeof(ch2));
    pre(one);
    pre1(two);
    //if(n == 13) puts(ch1), puts(ch2);
    memset(ch, 0, sizeof(ch));
    int temp, carry = 0, i, j, len1 = strlen(ch1), len2 = strlen(ch2);
    ch[0] = ch1[len1 - 1];
    int k = 1;
    len1--;
    if(len2 > len1)
    {
        len1--;
        for(i = len2 - 1; i >= 0; i--)
        {
            if(len1 >= 0)
            {
                temp = (ch1[len1--] - 48) + (ch2[i] - 48) + carry;
                carry = temp / 10;
                temp = temp % 10;
                ch[k++] = temp + 48;
            }
            else
            {
                temp = (ch2[i] - 48) + carry;
                carry = temp / 10;
                temp = temp % 10;
                ch[k++] = temp + 48;
            }
        }
    }
    else////////////////////////////
    {
        len2--;
        for(i = len1 - 1; i >= 0; i--)
        {
            if(len2 >= 0)
            {
                temp = (ch1[i] - 48) + (ch2[len2--] - 48) + carry;
                carry = temp / 10;
                temp = temp % 10;
                ch[k++] = temp + 48;
            }
            else
            {
                temp = (ch1[i] - 48) + carry;
                carry = temp / 10;
                temp %= 10;
                ch[k++] = temp + 48;
            }
        }
    }
    if(carry > 0)
    {
        int len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            temp = carry % 10;
            ch[k++] = temp + 48;
            carry /= 10;
        }
    }
    reverse(ch, ch + k);
    for(i = 0; i < k; i++)
        save[n].num[ch[i] - 48]++;
}
void pre(int n)
{
    char c[800], stor[800];
    strcpy(stor, ch);
    memset(c, 0, sizeof(c));
    strcpy(c, ch);
    int carry, i, j, t, tt, ttt, len;
    len = strlen(c);
    memset(ch, 0, sizeof(ch));
    carry = 0, j = 0;
    i = len - 1;
    for(; i >= 0; i--)
    {
        t = ((c[i] - 48) * n) + carry;
        tt = t % 10;
        ch[j++] = tt + 48;
        carry = t / 10;
    }
    if(carry > 0)
    {
        len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            t = carry % 10;
            carry /= 10;
            ch[j++] = t + 48;
        }
    }

    reverse(ch, ch + j);
    strcpy(ch1, ch);
    strcpy(ch, stor);
}
void pre1(int n)
{
    char c[800], stor[800];
    strcpy(stor, ch);
    memset(c, 0, sizeof(c));
    strcpy(c, ch);
    int carry, i, j, t, tt, ttt, len;
    len = strlen(c);
    memset(ch, 0, sizeof(ch));
    carry = 0, j = 0;
    i = len - 1;
    for(; i >= 0; i--)
    {
        t = ((c[i] - 48) * n) + carry;
        tt = t % 10;
        ch[j++] = tt + 48;
        carry = t / 10;
    }
    if(carry > 0)
    {
        len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            t = carry % 10;
            carry /= 10;
            ch[j++] = t + 48;
        }
    }

    reverse(ch, ch + j);
    strcpy(ch2, ch);
    strcpy(ch, stor);
}

void pre2(int n)
{
    char c[800], stor[800];
    strcpy(stor, ch);
    memset(c, 0, sizeof(c));
    strcpy(c, ch);
    int carry, i, j, t, tt, ttt, len;
    len = strlen(c);
    memset(ch, 0, sizeof(ch));
    carry = 0, j = 0;
    i = len - 1;
    for(; i >= 0; i--)
    {
        t = ((c[i] - 48) * n) + carry;
        tt = t % 10;
        ch[j++] = tt + 48;
        carry = t / 10;
    }
    if(carry > 0)
    {
        len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            t = carry % 10;
            carry /= 10;
            ch[j++] = t + 48;
        }
    }

    reverse(ch, ch + j);
    strcpy(ch3, ch);
    strcpy(ch, stor);
}
void mul3(int n)
{
    int one, two, three, tmp = n, a, b, c;
    one = tmp % 10;
    tmp /= 10;
    two = tmp % 10;
    three = tmp / 10;

    //pf("%d %d %d\n", one, two, three);

    memset(ch1, 0, sizeof(ch1));
    memset(ch2, 0, sizeof(ch2));
    memset(ch3, 0, sizeof(ch3));

    pre(one);
    pre1(two);
    pre2(three);

    memset(ch, 0, sizeof(ch));

    int temp, carry = 0, i, j, len1 = strlen(ch1), len2 = strlen(ch2), len3 = strlen(ch3);

    ch[0] = ch1[len1 - 1];
    len1--;
    temp = (ch1[len1 - 1] - 48) + (ch2[len2 - 1] - 48);
    len1--;
    len2--;
    carry = temp / 10;
    temp %= 10;
    ch[1] = temp + 48;

    int k = 2;
    if(len3 > len1 && len3 > len2)
    {
        len1--; len2--;
        for(i = len3 - 1; i >= 0; i--)
        {
            temp = 0;
            if(len1 >= 0){
                a = ch1[len1--] - 48;
                temp += a;
            }
            if(len2 >= 0){
                b = ch2[len2--] - 48;
                temp += b;
            }
            c = ch3[i] - 48;
            temp += c;
            temp += carry;
            carry = temp / 10;
            temp %= 10;
            ch[k++] = temp + 48;
        }
    }
    else if(len2 > len1 && len2 > len3)
    {
        len1--; len3--;
        temp = 0;
        for(i = len2 - 1; i >= 0; i--)
        {
            temp = 0;
            if(len1 >= 0){
                a = ch1[len1--] - 48;
                temp += a;
            }
            b = ch2[i] - 48;
            temp += b;
            if(len3 >= 0){
                c = ch3[len3--] - 48;
                temp += c;
            }
            temp += carry;
            carry = temp / 10;
            temp %= 10;
            ch[k++] = temp + 48;
        }
    }
    else if(len1 >= len2 && len1 >= len3)
    {
        len2--; len3--;
        temp = 0;
        for(i = len1 - 1; i >= 0; i--)
        {
            temp = 0;
            a = ch1[i] - 48;
            temp += a;
            if(len2 >= 0){
                b = ch2[len2--] - 48;
                temp += b;
            }
            if(len3 >= 0){
                c = ch3[len3--] - 48;
                temp += c;
            }
            temp += carry;
            carry = temp / 10;
            temp %= 10;
            ch[k++] = temp + 48;
        }
    }

    if(carry > 0)
    {
        int len = log10(carry) + 1;
        for(i = 0; i < len; i++)
        {
            temp = carry % 10;
            ch[k++] = temp + 48;
            carry /= 10;
        }
    }
    reverse(ch, ch + k);
    for(i = 0; i < k; i++)
        save[n].num[ch[i] - 48]++;
}
