#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int btd(int base);
void dtb(int base, int num);
char num[ 1010 ], number[ 35 ], res[ 35 ];
int main()
{
    int rb, inb;
    while(~scanf("%d", &rb) && rb)
    {
        scanf("%s %s", num, number);
        inb = btd( rb );
        int mod = 0, len = strlen( num );
        for(int i = 0; i < len; i++) mod = (mod * rb + (num[ i ] - 48)) % inb;
        dtb(rb, mod);
    }
    return 0;
}
int btd(int base)
{
    int ret = 0, len = strlen( number );
    for(int i = 0; i < len; i++) ret = ret * base + (number[ i ] - 48);
    return ret;
}
void dtb(int base, int num)
{
    if(!num)
    {
        puts("0");
        return ;
    }
    int i = 0;
    while(num)
    {
        res[ i++ ] = (num % base) + 48;
        num /= base;
    }
    res[ i ] = NULL;
    reverse(res, res + i);
    puts(res);
}
