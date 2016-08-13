#include <stdio.h>
#include <string.h>

int main ()
{
    int t = 0;
    char str[10002];
    while (1)
    {
        gets(str);
        if (str[0] == '*')
            break;
        if(strcmp(str, "Hajj") == 0)
            printf ("Case %d: Hajj-e-Akbar\n", ++t);
        else if(strcmp(str, "Umrah") == 0)
            printf ("Case %d: Hajj-e-Asghar\n", ++t);
    }
    return 0;
}
