#include<stdio.h>
#include<string.h>
int main()
{
    int T,z=1;
    scanf("%d",&T);
    while(T--)
    {
        int res=0,len,i;
        char c[102];
        scanf("%d",&len);
            scanf("%s",c);
        for(i=0; i<len; i++)
        {
            if(c[i]=='.')
            {
                res++;
                c[i+1]='#';
                i+=2;
            }
        }

            printf("Case %d: %d\n",z,res);
            z++;
    }
    return 0;
}
