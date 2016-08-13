#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    int i, j, k, temp , ans[100000] = {0}, T, len, x = 0, count = 1, m, n, start, end;
    char Inpch[100000], resch[100000] = {0}, save, out[100000] = {0}, tmp[100000] = {0};
    sf("%d", &T);
    getchar();
    while(T--)
    {
        gets(Inpch);
        len = strlen(Inpch);
        for(i = 0; i < len; i++)
            if(isalpha(Inpch[i]))
            {
                if(Inpch[i] > 96 && Inpch[i] < 123)
                    Inpch[i] = Inpch[i] - 32;
                resch[x++] = Inpch[i];
            }
    }

    for(i = 0; i < x-1; i++)
        for(j = 0; j < x-1; j++)
        {
            if(resch[j] < resch[j+1])
            {
                save = resch[j];
                resch[j] = resch[j+1];
                resch[j+1] = save;
            }
        }

    j = 0;
    for(i = 0; i < x; i++)
    {
        if(resch[i] == resch[i+1])
            count++;
        else
        {
            out[j] = resch[i];
            ans[j] = count;
            j++;
            count = 1;
        }
    }

    for(i = 0; i < j-1; i++)
        for(x = 0; x < j-1; x++)
        {
            if(ans[x] < ans[x+1])
            {
                temp = ans[x];
                save = out[x];
                ans[x] = ans[x+1];
                out[x] = out[x+1];
                ans[x+1] = temp;
                out[x+1] = save;
            }
        }

    count = 0; x = 0; start = 0; int ck = 0;
    for(i = 0; i < j; i++)
    {
        if(ans[i] == ans[i+1] && ck == 0)
        {
            start = i; ck = 1;
        }
        if(ans[i] != ans[i+1] && ck == 1)
        {
            for(k = start; k < i; k++)
                for(m = start; m < i; m++)
                {
                    if(out[m] > out[m+1])
                    {
                        save = out[m];
                        out[m] = out[m+1];
                        out[m+1] = save;
                    }
                }

            ck = 0;
        }
    }

    for(i = 0; i < j; i++)
        pf("%c %d\n", out[i], ans[i]);
    return 0;
}
