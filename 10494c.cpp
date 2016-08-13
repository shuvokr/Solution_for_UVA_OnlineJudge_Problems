#include<stdio.h>
#include<string.h>
int main()
{
    char a[10010],b;
    long long int i,len1,len2,s1,c,s2,j,m, flag;
    while(~scanf("%s %c %lld",&a,&b,&c))
    {
         len1=strlen(a);
        if(b=='/')
           {
               flag=s1=0;
               for(i=0;i<len1;i++)
               {
                   s1=(s1*10 + (a[i]-'0'));
                   if(s1 / c != 0) flag = 1;
                   if( flag ) printf("%lld", s1 / c);
                   s1 = s1 % c;
               }
               if(!flag) puts("0");
               else puts("");
           }
        else if(b=='%')
        {
               s2=0;
               for(j=0;j<len1;j++)
               {
                   s2=(s2*10+(a[j]-'0'))%c;
               }
               printf("%lld\n",s2);
        }
    }
    return 0;
}

