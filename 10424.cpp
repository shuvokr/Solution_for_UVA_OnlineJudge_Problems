#include<stdio.h>
#include<string.h>
#include<math.h>

int fun(int n)
{
    int len,m,i,j,x,k;
    while(n!=0)
        {
            len=(int)log10(n);
            j=0;
            for(k=0 ; k<=len ; k++)
            {
                i=n%10;
                j=i+j;
                n=n/10;
            }
        }
        return j;
}

int main()
{
    char L[25],M[25];
    while(gets(L) && gets(M))
    {
        int len1,len2,i,r=0,g=0,len11=100,len22=100;
        float res;
        len1=strlen(L);
        len2=strlen(M);
        for(i=0; i<len1; i++)
        {
            if(L[i]=='a' || L[i]=='A')
            {
                r+=1;
            }
            else if(L[i]=='b' || L[i]=='B')
            {
                r+=2;
            }
            else if(L[i]=='c' || L[i]=='C')
            {
                r+=3;
            }
            else if(L[i]=='d' || L[i]=='D')
            {
                r+=4;
            }
            else if(L[i]=='e' || L[i]=='E')
            {
                r+=5;
            }
            else if(L[i]=='f' || L[i]=='F')
            {
                r+=6;
            }
            else if(L[i]=='g' || L[i]=='G')
            {
                r+=7;
            }
            else if(L[i]=='h' || L[i]=='H')
            {
                r+=8;
            }
            else if(L[i]=='i' || L[i]=='I')
            {
                r+=9;
            }
            else if(L[i]=='j' || L[i]=='J')
            {
                r+=10;
            }
            else if(L[i]=='k' || L[i]=='K')
            {
                r+=11;
            }
            else if(L[i]=='l' || L[i]=='L')
            {
                r+=12;
            }
            else if(L[i]=='m' || L[i]=='M')
            {
                r+=13;
            }
            else if(L[i]=='n' || L[i]=='N')
            {
                r+=14;
            }
            else if(L[i]=='o' || L[i]=='O')
            {
                r+=15;
            }
            else if(L[i]=='p' || L[i]=='P')
            {
                r+=16;
            }
            else if(L[i]=='q' || L[i]=='Q')
            {
                r+=17;
            }
            else if(L[i]=='r' || L[i]=='R')
            {
                r+=18;
            }
            else if(L[i]=='s' || L[i]=='S')
            {
                r+=19;
            }
            else if(L[i]=='t' || L[i]=='T')
            {
                r+=20;
            }
            else if(L[i]=='u' || L[i]=='U')
            {
                r+=21;
            }
            else if(L[i]=='v' || L[i]=='V')
            {
                r+=22;
            }
            else if(L[i]=='w' || L[i]=='W')
            {
                r+=23;
            }
            else if(L[i]=='x' || L[i]=='X')
            {
                r+=24;
            }
            else if(L[i]=='y' || L[i]=='Y')
            {
                r+=25;
            }
            else if(L[i]=='z' || L[i]=='Z')
            {
                r+=26;
            }
            else
            {
                r=r;
            }
        }

        for(i=0; i<len2; i++)
        {
            if(M[i]=='a' || M[i]=='A')
            {
                g+=1;
            }
            else if(M[i]=='b' || M[i]=='B')
            {
                g+=2;
            }
            else if(M[i]=='c' || M[i]=='C')
            {
                g+=3;
            }
            else if(M[i]=='d' || M[i]=='D')
            {
                g+=4;
            }
            else if(M[i]=='e' || M[i]=='E')
            {
                g+=5;
            }
            else if(M[i]=='f' || M[i]=='F')
            {
                g+=6;
            }
            else if(M[i]=='g' || M[i]=='G')
            {
                g+=7;
            }
            else if(M[i]=='h' || M[i]=='H')
            {
                g+=8;
            }
            else if(M[i]=='i' || M[i]=='I')
            {
                g+=9;
            }
            else if(M[i]=='j' || M[i]=='J')
            {
                g+=10;
            }
            else if(M[i]=='k' || M[i]=='K')
            {
                g+=11;
            }
            else if(M[i]=='l' || M[i]=='L')
            {
                g+=12;
            }
            else if(M[i]=='m' || M[i]=='M')
            {
                g+=13;
            }
            else if(M[i]=='n' || M[i]=='N')
            {
                g+=14;
            }
            else if(M[i]=='o' || M[i]=='O')
            {
                g+=15;
            }
            else if(M[i]=='p' || M[i]=='P')
            {
                g+=16;
            }
            else if(M[i]=='q' || M[i]=='Q')
            {
                g+=17;
            }
            else if(M[i]=='r' || M[i]=='R')
            {
                g+=18;
            }
            else if(M[i]=='s' || M[i]=='S')
            {
                g+=19;
            }
            else if(M[i]=='t' || M[i]=='T')
            {
                g+=20;
            }
            else if(M[i]=='u' || M[i]=='U')
            {
                g+=21;
            }
            else if(M[i]=='v' || M[i]=='V')
            {
                g+=22;
            }
            else if(M[i]=='w' || M[i]=='W')
            {
                g+=23;
            }
            else if(M[i]=='x' || M[i]=='X')
            {
                g+=24;
            }
            else if(M[i]=='y' || M[i]=='Y')
            {
                g+=25;
            }
            else if(M[i]=='z' || M[i]=='Z')
            {
                g+=26;
            }
            else
            {
                g=g;
            }

        }
            len11=(int)log10(r);
            while(len11>0)
            {
                r=fun(r);
                len11=(int)log10(r);
            }

            len22=(int)log10(g);
            while(len22>0)
            {
                g=fun(g);
                len22=(int)log10(g);
            }

            if(r>g)
            {
                res=((float)g)/((float)r);
                res=res*100.00;
                printf("%.2f %%\n",res);
            }
            else if(r<g)
            {
                res=((float)r)/((float)g);
                res=res*100.00;
                printf("%.2f %%\n",res);
            }
            else
            {
                printf("100.00 %%\n");
            }
    }
    return 0;
}
