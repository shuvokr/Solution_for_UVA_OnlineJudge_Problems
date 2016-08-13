#include<stdio.h>
int main()
{
    char ques[100],sign;
    int a,b,res,r,c,ca=0;
    while(gets(ques))
    {
        if(sscanf(ques,"%d%c%d=%d",&a,&sign,&b,&res)!=4)
            continue;
        switch(sign)
        {
        case '+':
            r=a+b;
            break;
        case '-':
            r=a-b;
            break;
        }
        if(r==res)ca++;
    }
    printf("%d\n",ca);
    return 0;
}
