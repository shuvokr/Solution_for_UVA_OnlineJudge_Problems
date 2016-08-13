#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int cou = 1, len = 0, n = 0, i = 0, j = 0, k = 0,q = 0,AA = 0;
    char c[1002];
    while(gets(c))
    {
        if(AA == 1) printf("\n");
        int a[1002] = {0}, ar[1002] = {0}, x = 0, m = 0,w = 0;
        len = strlen(c);
        q = 0;
        for(i = 0; i < len; i++)
        {
            n = c[i];
            while(c[i] == n)
            {
                for(j=0; j<x; j++)
                {
                    if(a[j] == n)
                    {
                        q = 1;
                        w = j;
                        break;
                    }
                }
                if(q == 1)
                {
                    ar[w]+=cou;
                }
                else
                {
                    a[x] = n;
                    ar[x]+=cou;
                }
                i++;
                q=0;
            }
            i--;
            x++;
        }

        for(i=0; i<x-1; i++)
        {
            for(j=0; j<x-1; j++)
            {
                if(ar[j]>ar[j+1])
                {
                    k = ar[j];
                        m = a[j];
                    ar[j] = ar[j+1];
                        a[j] = a[j+1];
                    ar[j+1] = k;
                        a[j+1] = m;
                }
            }
        }
        int y = 0;
        for(i=0; i<x; i++)
        {
            n = ar[i];
            y=i;
            while(ar[i] == n)
            {
                i++;
            }
            for(j=y; j<i-1; j++)
            {
                for(k=y; k<i-1; k++)
                {
                    if(a[k]<a[k+1])
                    {
                        m = a[k];
                        a[k] = a[k+1];
                        a[k+1] = m;
                    }
                }
            }
            i--;
        }

        i=0;
        for(; i < x; i++)
        {
            if(a[i]!=0 && ar[i]!=0)
            printf("%d %d\n",a[i],ar[i]);
        }
        x = 0;
        AA = 1;
    }
    return 0;
}
