#include<stdio.h>
#include<math.h>
int main()
{
    int i,n,m,cou=0,a1,a2,a3,a4,x,y,z;
    while(scanf("%d%d",&n,&m)==2)
    {
        int len,r;
        for(i=n; i<=m; i++)
        {
            len=(int)log10(i)+1;
            if(len==1)
                cou++;
            else if(len==2 && (i!=11 && i!=22 && i!=33 && i!=44 && i!=55 && i!=66 && i!=77 && i!=88 && i!=99))
                cou++;
            else if(len==3)
            {
                a1=i%10;
                y=i/10;
                a2=y%10;
                a3=y/10;
                if(a1!=a2 && a1!=a3 && a2!=a3)
                    cou++;
            }
            else if(len==4)
            {
                a1=i%10;
                y=i/10;
                a2=y%10;
                y=y/10;
                a3=y%10;
                a4=y/10;
                if(a1!=a2 && a1!=a3 && a1!=a4 && a2!=a3 && a2!=a4 && a3!=a4)
                    cou++;
            }
        }
        printf("%d\n",cou);
        cou=0;
    }

    return 0;
}
