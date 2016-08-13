/************************************
    Shuvo
    Problem ID: 11734
    Problem algo: Ad hoq( String procage )
************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int T,z=1,i,ku=0;
    char team[400],j[400],st[400];

    scanf("%d",&T);
    getchar();
    for(z=1; z<=T; z++)
    {

        int len1,len2,jj=0;

        gets(team);

        gets(j);

        len1=strlen(team);
        len2=strlen(j);

        if(strcmp(j,team)==0)
        {
            printf("Case %d: Yes\n",z);
        }
        else if(len1!=len2)
        {
            if(len1>len2)
            for(i=0; i<=len1; i++)
            {
                if(!isspace(team[i]))
                {
                   st[jj]=team[i];
                   jj++;
                }
            }
            else
            {
                for(i=0; i<=len1; i++)
                    if(team[i]==j[i])
                        ku++;
            }
            if(strcmp(j,st)==0 || len1==ku)
                printf("Case %d: Output Format Error\n",z);
            else
                printf("Case %d: Wrong Answer\n",z);
        }
        else
            printf("Case %d: Wrong Answer\n",z);

    }
    return 0;
}
