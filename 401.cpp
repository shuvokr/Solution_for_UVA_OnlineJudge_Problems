#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define lu unsigned long int
#define sf scanf
#define pf printf
#define N 22

char wo[] = "AEHIJLMOSTUVWXYZ12358";
char rw[] = "A3HILJMO2TUVWXY51SEZ8";

int pallin(char w[]);
int  mirror(char w[]);

int main()
{
    char word[N];
    lu pal = 0, mirr = 0;
    while(gets(word))
    {
        pal = 0; mirr = 0;
        if(pallin(word))
            pal = 1;
        if(mirror(word))
            mirr = 1;

        if(pal && mirr){
            printf("%s",word); puts(" -- is a mirrored palindrome.\n");
        }
        else if(pal){
            printf("%s",word); puts(" -- is a regular palindrome.\n");
        }
        else if(mirr){
            printf("%s",word); puts(" -- is a mirrored string.\n");
        }
        else{
            printf("%s",word); puts(" -- is not a palindrome.\n");
            }

     }
    return 0;
}


int pallin(char w[])
{
       int i, len, k=0;
       char a[N];
       len = strlen(w) - 1;
       for(i=len;i>=0;i--)
        a[k++] = w[i];
       a[k] = '\0';

       if(!strcmp(a,w))
        return 1;

       return 0;
}

int  mirror(char w[])
{
    int i,k,ck,len,d,j,p;
    d = strlen(w);
    k = d - 1;
    if(d % 2 != 0)
        len  = d / 2;
    else
        len = d / 2 - 1;

    for(i = 0; i <= len; i ++)
    {
        ck = 1;
        for(j = 0; wo[j]; j ++)
        {
            if(w[i] == wo[j])
                if(w[k] == rw[j])
                {
                    ck = 0;
                    break;
                }
        }
        k --;
        if(ck) return 0;
    }
    return 1;
}
