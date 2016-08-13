#include<stdio.h>
#include<string.h>
int main()
{
    char c[31];
    while(gets(c))
    {
        int len,i;
        len=strlen(c);
        for(i=0; i<len; i++)
        {

        if(c[i]=='1')
        {
            printf("1");
        }
        else if(c[i]=='2')
        {
            printf("2");
        }
        else if(c[i]=='3')
        {
            printf("3");
        }
        else if(c[i]=='4')
        {
            printf("4");
        }
        else if(c[i]=='5')
        {
            printf("5");
        }
        else if(c[i]=='6')
        {
            printf("6");
        }
        else if(c[i]=='7')
        {
            printf("7");
        }
        else if(c[i]=='8')
        {
            printf("8");
        }
        else if(c[i]=='9')
        {
            printf("9");
        }
        else if(c[i]=='0')
        {
            printf("0");
        }
        else if(c[i]=='-')
        {
            printf("-");
        }
        else if(c[i]=='A' || c[i]=='B' || c[i]=='C')
        {
            printf("2");
        }
        else if(c[i]=='D' || c[i]=='E' || c[i]=='F')
        {
            printf("3");
        }
        else if(c[i]=='G' || c[i]=='H' || c[i]=='I')
        {
            printf("4");
        }
        else if(c[i]=='J' || c[i]=='K' || c[i]=='L')
        {
            printf("5");
        }
        else if(c[i]=='M' || c[i]=='N' || c[i]=='O')
        {
            printf("6");
        }
        else if(c[i]=='P' || c[i]=='Q' || c[i]=='R' || c[i]=='S')
        {
            printf("7");
        }
        else if(c[i]=='T' || c[i]=='U' || c[i]=='V')
        {
            printf("8");
        }
        else if(c[i]=='W' || c[i]=='X' || c[i]=='Y' || c[i]=='Z')
        {
            printf("9");
        }

        }
        printf("\n");



    }
    return 0;

}
