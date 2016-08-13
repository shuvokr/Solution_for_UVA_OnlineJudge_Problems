#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[7];
        int len;
        scanf("%s",a);
        len=strlen(a);
        if(len==5)
        {
            printf("3\n");
        }
        else if((a[0]=='o' && a[1]=='n') || (a[0]=='o' && a[1]=='e') || (a[1]=='n' && a[2]=='e')||(a[0]=='o' && a[2]=='e') || (a[0]=='o' && a[2]=='n'))
        {
            printf("1\n");
        }
        else
        {
            printf("2\n");
        }
    }
    return 0;
}
