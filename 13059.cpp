#include <stdio.h>
#include <string.h>
int main()
{
	char p[50];
	char *buff = p;
	int len, i;
	while(gets(p))
	{
		len = strlen(p);
		if(p[len - 1] == '0')
		{
			i = len - 1;
			while(p[i] == '0') i--;
			if(p[i] > '1') 
			{
				p[i]--; i++; while(i < len) p[i++] = 57;
			}
			else
			{
				if(i == 0) { for(i = 0; i < len; i++) p[i] = 57; p[len - 1] = NULL; }
				else
				{
					p[i]--; i++;
					while(i < len) p[i++] = 57;
				}
			}
		}
		else p[len - 1]--;
		puts(buff);
	}
	
	return 0;
}
