#include <stdio.h>
int main()
{
    char a[ 11 ], b[ 11 ], c;
    int i;
    while(gets(a))
    {
        gets(b); c = 0;
        for(int i = 0; i < 9; i += 2)
            c = a[ i ] == b[ i ] ? 1 : c;
        puts(c ? "N" : "Y");
    }
    return 0;
}
