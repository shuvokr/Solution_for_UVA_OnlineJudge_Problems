#include <stdio.h>
using namespace std;
int half,len,n,min,max,i,tmp,T,s;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&len,&n);
        half=len>>1;half++;
        min=max=0;
        for(i=0;i!=n;i++)
        {
            scanf("%d",&tmp);
            s=len-tmp;
            tmp<half?
                min=min<tmp?tmp:min,
                max=max<s?s:max:
                min=min<s?s:min,
                max=max<tmp?tmp:max;
        }
        printf("%d %d\n", min, max);

    }
    return 0;
}
