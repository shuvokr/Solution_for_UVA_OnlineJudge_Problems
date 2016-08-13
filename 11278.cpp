/*
                                Shuvo
                                11278
*/
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

int main()
{
    char *l = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char *r = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
    char *L = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char *R = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

    char IP, tmp[257];
    int len = strlen(l), ln = strlen(L), i, j;

    for(i = 0; i < len; i++)
        tmp[l[i]] = r[i];

    for(i = 0; i < len; i++)
        tmp[L[i]] = R[i];

    while(sf ("%c", &IP) != EOF)
    {
        if(IP == '\n') putchar('\n');
        else if(IP == ' ') putchar(' ');
        else pf("%c", tmp[IP]);
    }
}
