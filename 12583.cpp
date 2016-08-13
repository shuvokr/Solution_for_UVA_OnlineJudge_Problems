#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,x,len,T,z=1,day,count=0;
    char ch[1000];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%s",&day,&k,ch);
        len = strlen(ch);
        for(i=len-1; i>0; i--)
        {
            x = i-k;
            if(x<0) x=0;
            for(j=x; j<i; j++)
            {
                if(ch[i]==ch[j])
                {
                    count++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",z,count);
        z++; count = 0;
    }
    return 0;
}
