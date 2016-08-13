#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int T,ca=1,i;
    char mn[100000];
    scanf("%d",&T);
    gets(mn);

    while(T>0)
    {

        int res=0,len,i;
        char c[100000];
        gets(c);
        len=strlen(c);
        for(i=0; i<len; i++)
        {
            if(c[i]=='a' || c[i]=='d' || c[i]=='g' || c[i]=='j' || c[i]=='m' || c[i]=='p' || c[i]=='t' || c[i]=='w' || isspace(c[i]))
            {
                res+=1;
            }
            else if(c[i]=='b' || c[i]=='e' || c[i]=='h' || c[i]=='k' || c[i]=='n' || c[i]=='q' || c[i]=='u' || c[i]=='x')
            {
                res+=2;
            }
            else if(c[i]=='c' || c[i]=='f' || c[i]=='i' || c[i]=='l' || c[i]=='o' || c[i]=='r' || c[i]=='v' || c[i]=='y')
            {
                res+=3;
            }
            else if(c[i]=='s' || c[i]=='z')
            {
                res+=4;
            }
            else
            {
                res+=0;
            }
        }

        printf("Case #%d: %d\n",ca,res);
        ca++;
        T--;
    }
    return 0;
}
