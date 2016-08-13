#include<stdio.h>
#include<string.h>
#include<math.h>
int isprime(int n)
{
    int i,lim=999999999;
    lim=sqrt(n);
    for(i=2; i<=lim; i++)
    {
        if((n%i)==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char L[25];
    while(gets(L))
    {
        int len,i,r=0;
        len = strlen(L);
        for(i=0; i<len; i++)
        {
            if(L[i]=='a')
            {
                r+=1;
            }
            else if(L[i]=='b')
            {
                r+=2;
            }
            else if(L[i]=='c')
            {
                r+=3;
            }
            else if(L[i]=='d')
            {
                r+=4;
            }
            else if(L[i]=='e')
            {
                r+=5;
            }
            else if(L[i]=='f')
            {
                r+=6;
            }
            else if(L[i]=='g')
            {
                r+=7;
            }
            else if(L[i]=='h')
            {
                r+=8;
            }
            else if(L[i]=='i')
            {
                r+=9;
            }
            else if(L[i]=='j')
            {
                r+=10;
            }
            else if(L[i]=='k')
            {
                r+=11;
            }
            else if(L[i]=='l')
            {
                r+=12;
            }
            else if(L[i]=='m')
            {
                r+=13;
            }
            else if(L[i]=='n')
            {
                r+=14;
            }
            else if(L[i]=='o')
            {
                r+=15;
            }
            else if(L[i]=='p')
            {
                r+=16;
            }
            else if(L[i]=='q')
            {
                r+=17;
            }
            else if(L[i]=='r')
            {
                r+=18;
            }
            else if(L[i]=='s')
            {
                r+=19;
            }
            else if(L[i]=='t')
            {
                r+=20;
            }
            else if(L[i]=='u')
            {
                r+=21;
            }
            else if(L[i]=='v')
            {
                r+=22;
            }
            else if(L[i]=='w')
            {
                r+=23;
            }
            else if(L[i]=='x')
            {
                r+=24;
            }
            else if(L[i]=='y')
            {
                r+=25;
            }
            else if(L[i]=='z')
            {
                r+=26;
            }

            if(L[i]=='A')
            {
                r+=27;
            }
            else if(L[i]=='B')
            {
                r+=28;
            }
            else if(L[i]=='C')
            {
                r+=29;
            }
            else if(L[i]=='D')
            {
                r+=30;
            }
            else if(L[i]=='E')
            {
                r+=31;
            }
            else if(L[i]=='F')
            {
                r+=32;
            }
            else if(L[i]=='G')
            {
                r+=33;
            }
            else if(L[i]=='H')
            {
                r+=34;
            }
            else if(L[i]=='I')
            {
                r+=35;
            }
            else if(L[i]=='J')
            {
                r+=36;
            }
            else if(L[i]=='K')
            {
                r+=37;
            }
            else if(L[i]=='L')
            {
                r+=38;
            }
            else if(L[i]=='M')
            {
                r+=39;
            }
            else if(L[i]=='N')
            {
                r+=40;
            }
            else if(L[i]=='O')
            {
                r+=41;
            }
            else if(L[i]=='P')
            {
                r+=42;
            }
            else if(L[i]=='Q')
            {
                r+=43;
            }
            else if(L[i]=='R')
            {
                r+=44;
            }
            else if(L[i]=='S')
            {
                r+=45;
            }
            else if(L[i]=='T')
            {
                r+=46;
            }
            else if(L[i]=='U')
            {
                r+=47;
            }
            else if(L[i]=='V')
            {
                r+=48;
            }
            else if(L[i]=='W')
            {
                r+=49;
            }
            else if(L[i]=='X')
            {
                r+=50;
            }
            else if(L[i]=='Y')
            {
                r+=51;
            }
            else if(L[i]=='Z')
            {
                r+=52;
            }
        }

            if(r==1)
            {
                printf("It is a prime word.\n");
            }
            else
            {
                r=isprime(r);
                if(r==1)
                {
                    printf("It is a prime word.\n");
                }
                else
                {
                    printf("It is not a prime word.\n");
                }
            }
    }
    return 0;
}
