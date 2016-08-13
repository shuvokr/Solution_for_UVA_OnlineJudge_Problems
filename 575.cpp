#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int len,k;
    char n[32],s[10];
    gets(n);
    len=strlen(n);
    if(len==1 && n[0]=='0')
    {
        k=0;
    }
    else
    {
        k=1;
    }
	unsigned long long int i,r=0,h;
	while(k!=0)
	{
		h=len;

		for(i=0; i<len; i++)
		{
			if(n[i]=='1')
			{
				r+=1*((pow(2,h))-1);
			}
			else if(n[i]=='2')
			{
				r+=2*((pow(2,h))-1);
			}
			else if(n[i]=='3')
			{
				r+=3*((pow(2,h))-1);
			}
			else if(n[i]=='4')
			{
				r+=4*((pow(2,h))-1);
			}
			else if(n[i]=='5')
			{
				r+=5*((pow(2,h))-1);
			}
			else if(n[i]=='6')
			{
				r+=6*((pow(2,h))-1);
			}
			else if(n[i]=='7')
			{
				r+=7*((pow(2,h))-1);
			}
			else if(n[i]=='8')
			{
				r+=8*((pow(2,h))-1);
			}
			else if(n[i]=='9')
			{
				r+=9*((pow(2,h))-1);
			}
			else
			{
				r+=0;
			}
			h--;

		}
		printf("%llu\n",r);
		r=0;

		gets(n);
		len=strlen(n);
		if(len==1 && n[0]=='0')
		{
			k=0;
		}
		else
        {
            k=1;
        }

    }
    return 0;
}
