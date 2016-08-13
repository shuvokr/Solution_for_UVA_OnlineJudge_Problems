#include <stdio.h>
#include <string.h>
int count[4];
int main()
{
    char haiku[1000] = " ", input[1000];
    int i, j, k, len, flag, add;
    while(gets(input) && strcmp(input,"e/o/i") != 0)
    {
        strcat(haiku,input);
        strcat(haiku,"/ ");
        len=strlen(haiku);
        j=0;
        flag=1;
        add=0;
        for(i=1;i<len-1;i++)
        {
              if(haiku[i]=='/')
              {
                    if(j == 0 && count[j] != 5)
                    {
                        flag = 0;
                        break;
                    }
                    else if(j == 1 && count[j] != 7)
                    {
                        flag = 0;
                        break;
                    }
                    else if(j == 2 && count[j] != 5)
                    {
                        flag = 0;
                        break;
                    }
                    j++;
              }
              if(((haiku[i] == 'a' || haiku[i] == 'e'|| haiku[i] == 'i' || haiku[i] == 'o' || haiku[i] == 'u' || haiku[i] == 'y') && !(haiku[i - 1] == 'a' || haiku[i - 1] == 'e' || haiku[i - 1] == 'i' || haiku[i - 1] == 'o' || haiku[i - 1] == 'u' || haiku[i - 1] == 'y'))) count[j]++;
        }
        if(flag == 0) printf("%d\n", j + 1);
        else if(flag == 1) puts("Y");
        for(k = 0; k < 3; k++)count[k] = 0;
        strcpy(haiku," ");
    }
    return 0;
}
