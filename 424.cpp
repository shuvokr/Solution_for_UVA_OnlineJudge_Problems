#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    char ch[100000], c[100000];
    long len, i, j = 0, k, ans[100000] = {0}, carry = 0, last = 0;
    while(gets(ch))
    {

        if(ch[0] == '0')
        {
            if(last > 0) pf("%ld", last);
            puts(c);
            return 0;
        }

        len = strlen(ch);
        carry = 0;

        for(i = len - 1; i >= 0; i--)
        {
            k = (ch[i] - 48) + ans[i] + carry;
            ans[i] = k % 10;
            c[i] = ans[i] + 48;
            carry = k / 10;
        }
        last += carry;
    }
    return 0;
}
