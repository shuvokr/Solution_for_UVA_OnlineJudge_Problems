#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
#define n 1002

unsigned long F(unsigned long sum)
{
    lu i, len = log10(sum) + 1, ck = 0;
    for(i = 0; i < len; i++)
    {
        ck += sum % 10;
        sum /= 10;
    }
    return ck;
}

int main()
{
    char ch[n];
    lu i, sum, len, count, ck;
    while(gets(ch))
    {
        sum = 0;
        len = strlen(ch);
        if(len == 1 && ch[0] == '0') return 0;
        for(i = 0; i < len; i++)
            sum += ch[i] - 48;
        if(sum % 9 != 0)
        {
            for(i = 0; i < len; i++)
                pf("%c",ch[i]);
            pf(" is not a multiple of 9.\n");
        }
        else
        {
            count = 1;
            for(i = 0; i < len; i++)
                pf("%c",ch[i]);
            while(sum != 9){
                sum = F(sum);
                count++;
            }
            pf(" is a multiple of 9 and has 9-degree %lu.\n",count);
        }
    }
    return 0;
}

