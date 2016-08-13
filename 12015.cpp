#include<stdio.h>
#include<string.h>
int main()
{
    int T, z = 0;
    scanf("%d",&T);
    while(T--)
    {
        char c1[101], c2[101], c3[101], c4[101], c5[101], c6[101], c7[101], c8[101], c9[101], c10[101];
        int i, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, y = 0;

        scanf("%s%d",c1,&x1);
        scanf("%s%d",c2,&x2);
        scanf("%s%d",c3,&x3);
        scanf("%s%d",c4,&x4);
        scanf("%s%d",c5,&x5);
        scanf("%s%d",c6,&x6);
        scanf("%s%d",c7,&x7);
        scanf("%s%d",c8,&x8);
        scanf("%s%d",c9,&x9);
        scanf("%s%d",c10,&x10);


            if(x1 != 1 && y == 0)
            {
                y = x1;
            }
            else if(x2 != 2 && y == 0)
            {
                y = x2;
            }
            else if(x3 != 3 && y == 0)
            {
                y = x3;
            }
            else if(x4 != 4 && y == 0)
            {
                y = x4;
            }
            else if(x5 != 5 && y == 0)
            {
                y = x5;
            }
            else if(x6 != 6 && y == 0)
            {
                y = x6;
            }
            else if(x7 != 7 && y == 0)
            {
                y = x7;
            }
            else if(x8 != 8 && y == 0)
            {
                y = x8;
            }
            else if(x9 != 9 && y == 0)
            {
                y = x9;
            }
            else if(x10 != 10 && y == 0)
            {
                y = x10;
            }


            printf("Case #%d:\n",++z);
            if(y == x1)
            {
                puts(c1);
            }
            if(y == x2)
            {
                puts(c2);
            }
            if(y == x3)
            {
                puts(c3);
            }
            if(y == x4)
            {
                puts(c4);
            }
            if(y == x5)
            {
                puts(c5);
            }
            if(y == x6)
            {
                puts(c6);
            }
            if(y == x7)
            {
                puts(c7);
            }
            if(y == x8)
            {
                puts(c8);
            }
            if(y == x9)
            {
                puts(c9);
            }
            if(y == x10)
            {
                puts(c10);
            }
    }
    return 0;
}
