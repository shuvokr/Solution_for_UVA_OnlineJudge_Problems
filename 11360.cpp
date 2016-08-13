#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf
int main()
{
    char ch[11], c[10];
    int matrix[11][11], n, T, i, j, k, run, x, y, z, temp, count = 0;
    sf("%d", &T);
    while(T--)
    {
        sf("%d", &n);
        j = 0;
        for(i = 0; i < n; i++)
        {
            sf("%s", ch);
            for(k = 0; k < n; k++)
            {
                matrix[j][k] = ch[k] - 48;
            }
            j++;
        }
        sf("%d", &run);
        for(x = 0; x < run; x++)
        {
            sf("%s", c);
            if(strcmp(c,"row") == 0)
            {
                sf("%d%d",&y, &z);
                y--; z--;
                k = 0;
                for(j = 0; j < n; j++)
                {
                    temp = matrix[y][k];
                    matrix[y][k] = matrix[z][k];
                    matrix[z][k] = temp;
                    k++;
                }
            }
            else if(strcmp(c,"col") == 0)
            {
                sf("%d%d",&y, &z);
                y--; z--;
                k = 0;
                for(j = 0; j < n; j++)
                {
                    temp = matrix[k][y];
                    matrix[k][y] = matrix[k][z];
                    matrix[k][z] = temp;
                    k++;
                }
            }
            else if(strcmp(c,"inc") == 0)
            {
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        temp = matrix[i][j] + 1;
                        if(temp < 0)
                            matrix[i][j] = 10 + temp;
                        else
                            matrix[i][j] = temp % 10;
                    }
                }
            }
            else if(strcmp(c,"dec") == 0)
            {
                for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                    {
                        temp = matrix[i][j] - 1;
                        if(temp < 0)
                            matrix[i][j] = 10 + temp;
                        else
                            matrix[i][j] = temp % 10;
                    }
                }
            }
            else if(strcmp(c,"transpose") == 0)
            {
                int xx = 0;
                for(i = 0; i < n; i++)
                {
                    for(j = i; j < n; j++)
                    {
                        temp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = temp;
                    }
                }
            }
        }

        pf("Case #%d\n", ++count);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                pf("%d", matrix[i][j]);
            }
            pf("\n");
        }
        pf("\n");
    }
    return 0;
}
