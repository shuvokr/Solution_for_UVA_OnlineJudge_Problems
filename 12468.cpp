#include<stdio.h>

int main()
{

	int c1,c2,c,d;
	scanf("%d%d",&c1,&c2);
	while(c1!=-1 && c2!=-1)
	{
        if(c1>=0 && c1<=99 && c2>=0 && c2<=99)
        {
            if(c1<c2)
            {
                d=c2-c1;
            }
            else
            {
                d=c1-c2;
            }

            if(d<=50 && c1<c2)
            {
                c=c2-c1;
                printf("%d\n",c);
            }
            else if(d<=50 && c1>c2)
            {
                c=c1-c2;
                printf("%d\n",c);
            }
            else if(d>=50 && c1<c2)
            {
                c=(c1+100)-c2;
                printf("%d\n",c);
            }
            else if(d>=50 && c1>c2)
            {
                c=(c2+100)-c1;
                printf("%d\n",c);
            }
            else
            {
                printf("0\n");
            }

        }
        scanf("%d%d",&c1,&c2);
	}

	return 0;

}
