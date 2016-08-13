#include<stdio.h>
int main()
{
    int T,a,b,c,r;
    float s;
    scanf("%d",&T);
    while(T>0)
    {
        s=0;
        scanf("%d%d%d",&a,&b,&c);
        if(a==b && a==c)
        {
            printf("OK\n");
        }
        else
        {
            s=((float)a+(float)b+(float)c)/2;
            s=(s-a)*(s-b)*(s-c);
            if(s==0 || s<0)
            {
                printf("Wrong!!\n");
            }
            else
            {
                printf("OK\n");
            }
        }

        T--;
    }
    return 0;
}

//triangle given a,b,c = sqrt[s(s-a)(s-b)(s-c)] when s = (a+b+c)/2 (Heron's formula)
// And if a=b=c then ok :)
