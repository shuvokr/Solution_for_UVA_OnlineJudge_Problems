#include<stdio.h>
#include<string.h>
int main()
{
    int len,l2,i,j,a,k;
    char ar1[1000],ar2[1000];
    while(gets(ar1))
    {
        a=0;
        k=-1;
        len=strlen(ar1);
        if(len==4 && ar1[0]=='D' && ar1[1]=='O' && ar1[2]=='N' && ar1[3]=='E')
        break;
        for(i=0; i<len; i++)
        {
            if(ar1[i]!='.' && ar1[i]!=',' && ar1[i]!='?' && ar1[i]!='!' && ar1[i]!=' ')
            {
                k++;
                ar2[k]=ar1[i];
            }
        }
        for(j=0; j<=k; j++)
        {
            if(ar2[j]!=ar2[k-j] && ar2[j]!=(ar2[k-j]+32) && ar2[j]!=(ar2[k-j]-32))
            {
                printf("Uh oh..\n");
                a=1;
                break;
            }
        }
        if(a==0)
            printf("You won't be eaten!\n");
    }
    return 0;
}
