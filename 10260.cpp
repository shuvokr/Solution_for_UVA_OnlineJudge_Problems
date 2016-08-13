#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
#define M 1
int main()
{
    char ch[22];
    unsigned int len = 0, i = 0, j = 0;
    while(gets(ch))
    {
        char ans[22] = {0};
        len = strlen(ch);
        char ck = {0};
        for(i = 0; i < len; i++)
        {
            if(ch[i] != 'A' || ch[i] != 'E' || ch[i] != 'I' || ch[i] != 'O' || ch[i] != 'U'|| ch[i] != 'H' || ch[i] != 'W' || ch[i] != 'Y')
            if(ch[i] == 'R' && ch[i+1] != 'R')
                ans[j++] = 6+48;
            else if(ch[i] == 'L' && ch[i+1] != 'L')
                ans[j++] = 4+48;
            else if((ch[i] == 'D' || ch[i] == 'T') && (ch[i+1] != 'D' && ch[i+1] != 'T'))
                ans[j++] = 3+48;
            else if ((ch[i] == 'M' || ch[i] == 'N') && (ch[i+1] != 'M' && ch[i+1] != 'N'))
                ans[j++] = 5+48;
            else if((ch[i] == 'B' || ch[i] == 'F' || ch[i] == 'P' || ch[i] == 'V') && (ch[i+1] != 'B' && ch[i+1] != 'F' && ch[i+1] != 'P' && ch[i+1] != 'V'))
                ans[j++] = 1+48;
            else if((ch[i] == 'C' || ch[i] == 'G' || ch[i] == 'J' || ch[i] == 'K' || ch[i] == 'Q' || ch[i] == 'S' || ch[i] == 'X' || ch[i] == 'Z') && (ch[i+1] != 'C' && ch[i+1] != 'G' && ch[i+1] != 'J' && ch[i+1] != 'K' && ch[i+1] != 'Q' && ch[i+1] != 'S' && ch[i+1] != 'X' && ch[i+1] != 'Z'))
                ans[j++] = 2+48;
        }
        ans[j] = NULL;
        puts(ans); j = 0;
    }
    return 0;
}
