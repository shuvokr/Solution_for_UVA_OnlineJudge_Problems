#include<stdio.h>
#include<string.h>
int main()
{
    int d,m,y,dd,mm,yy,T,sd,sm,sy;
    char ch[100],b[100],s[100];
    scanf("%d",&T);
    T=T-1;
    scanf("%s%d%d%d",ch,&d,&m,&y);
    sd=d; sm = m; sy = y;
    strcpy(s,ch);
    strcpy(b,ch);
    while(T--)
    {
        scanf("%s%d%d%d",ch,&dd,&mm,&yy);
        if(y<yy)
        {
            y=yy;
            strcpy(b,ch);
        }
        else if(sy>yy)
        {
            sy=yy;
            strcpy(s,ch);
        }
        else
        {
            if(m<mm)
            {
                m=mm;
                strcpy(b,ch);
            }
            else if(sm>mm)
            {
                sm=mm;
                strcpy(s,ch);
            }
            else
            {
                if(d<dd)
                {
                    d=dd;
                    strcpy(b,ch);
                }
                else if(sd>dd)
                {
                    sd=dd;
                    strcpy(s,ch);
                }
                else
                {
                    strcpy(b,ch);
                    strcpy(s,ch);
                }
            }
        }
    }
    puts(b);
    puts(s);
    return 0;
}
