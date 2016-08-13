#include<stdio.h>
#include<string.h>
int main()
{
    int cou=1;
    char c[16];
    scanf("%s",c);
    while(c[0]!='#')
    {
        if(strcmp(c,"HELLO")==0)
        {
            printf("Case %d: ENGLISH\n",cou);
        }
        else if(strcmp(c,"HOLA")==0)
        {
            printf("Case %d: SPANISH\n",cou);
        }
        else if(strcmp(c,"HALLO")==0)
        {
            printf("Case %d: GERMAN\n",cou);
        }
        else if(strcmp(c,"BONJOUR")==0)
        {
            printf("Case %d: FRENCH\n",cou);
        }
        else if(strcmp(c,"CIAO")==0)
        {
            printf("Case %d: ITALIAN\n",cou);
        }
        else if(strcmp(c,"ZDRAVSTVUJTE")==0)
        {
            printf("Case %d: RUSSIAN\n",cou);
        }
        else
        {
            printf("Case %d: UNKNOWN\n",cou);
        }
        cou++;
        scanf("%s",c);
    }
    return 0;
}
