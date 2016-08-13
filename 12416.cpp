#include<stdio.h>
char c[1000000];
int main()
{
    while(gets(c))
    {
        int i,s=0,sml=0;
        for(i=0; c[i]; i++)
        {
            if(c[i]==' ')
            {
                s++;
            }
            else{
                if(sml<s)
                {
                    sml=s;
                }
                s=0;
            }
        }
        s=0;
        while(sml != 1)
        {
            s++;
            sml = sml/2 + (sml-sml/2*2);
        }
        printf("%d\n",s);
    }
    return 0;
}
