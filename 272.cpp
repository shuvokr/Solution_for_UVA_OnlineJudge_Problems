#include<stdio.h>
#include<string.h>
int main()
{
    char c[2000];
    int i,len,z=1;
    char a[2]={0};
    while(gets(c))
    {
        len = strlen(c);
        for(i=0; i<len; i++)
        {
            if(c[i]==34 && a[0]!=39 && a[1]!=39)
            {
                printf("``");
                a[0]=39; a[1]=39;
            }
            else if(c[i]==34 && a[0]==39 && a[0]==39)
            {
                printf("''");
                a[0]=0; a[1]=0;
            }
            else
                printf("%c",c[i]);
        }
        printf("\n");
        z++;
    }
    return 0;
}
