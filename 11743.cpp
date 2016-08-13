#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    int a =0 ,b =0 ,c = 0,d = 0, ans = 0, r = 0,r1 = 0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16;
    int x1,x2;
    scanf("%d",&T);
    while(T--)
    {
        r = 0; x1 = 0; x2 = 0;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        c1 = a/1000;
        a = a % 1000;
        c2 = a/100;
        a = a%100;
        c3 = a/10;
        c4 = a%10;

        c5 = b/1000;
        b = b % 1000;
        c6 = b/100;
        b = b%100;
        c7 = b/10;
        c8 = b%10;

        c9 = c/1000;
        c = c % 1000;
        c10 = c/100;
        c = c%100;
        c11 = c/10;
        c12 = c%10;

        c13 = d/1000;
        d = d % 1000;
        c14 = d/100;
        d = d%100;
        c15 = d/10;
        c16 = d%10;

        x2 = c1+c1;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c3+c3;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c5+c5;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c7+c7;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c9+c9;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c11+c11;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c13+c13;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;
        x2 = c15+c15;
        x1 = log10(x2);
        if(x1 == 1)
        {
            r+= (x2/10)+(x2%10);
        }
        else r+=x2;

        r1 = c2+c4+c6+c8+c10+c12+c14+c16;
        r = r + r1;
        r = r % 10;
        if(r == 0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
