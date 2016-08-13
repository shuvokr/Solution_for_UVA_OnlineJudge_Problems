#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define sf scanf
#define pf printf

int main()
{
    int i, j, k, len1, T, len2, x ;
    char Inpch1[200], Inpch2[200];
    sf("%d", &T);
    getchar();
    while(T--)
    {
        gets(Inpch1);
        gets(Inpch2);
        len1 = strlen(Inpch1);
        len2 = strlen(Inpch2);
        char res1[200] = {0}, res2[200] = {0}, save1[200] = {0}, save2[200] = {0}, save3[200] = {0}, save4[200] = {0};
        j = 0;
        for(i = 0; i < len1; i++)
        {
            if(Inpch1[i] != 60 && Inpch1[i] != 62)
            {
                res1[j] = Inpch1[i]; j++;
            }
        }

        x = 0;
        for(i = 0; i < len1; i++)
        {
            if(Inpch1[i] == 60)
            {
                i++;
                while(Inpch1[i] != 62)
                {
                    save1[x] = Inpch1[i];
                    x++; i++;
                }
                i++;
                    x = 0;
                    while(Inpch1[i] != 60)
                    {
                        save2[x] = Inpch1[i];
                        i++; x++;
                    }
                    i++;
                        x = 0;
                        while(Inpch1[i] != 62)
                        {
                            save3[x] = Inpch1[i];
                            i++; x++;
                        }
                        i++;
                            x = 0;
                            while(i < len1)
                            {
                                save4[x] = Inpch1[i];
                                x++; i++;
                            }
            }
        }

        k = 0; x = 0;
        for(i = 0; i < len2; i++)
        {
            if(Inpch2[i] == 46 && Inpch2[i+1] == 46 && Inpch2[i+2] == 46 && Inpch2[i+3] != 46)
            {
                int len = strlen(save3);
                for(x = 0; x < len; x++)
                {
                    res2[k] = save3[x];
                    k++;
                }
                len = strlen(save2);
                for(x = 0; x < len; x++)
                {
                    res2[k] = save2[x];
                    k++;
                }

                len = strlen(save1);
                for(x = 0; x < len; x++)
                {
                    res2[k] = save1[x];
                    k++;
                }
                len = strlen(save4);
                for(x = 0; x < len; x++)
                {
                    res2[k] = save4[x];
                    k++;
                }
                i += 2;
            }
            else
            {
                res2[k] = Inpch2[i]; k++;
            }
        }
        puts(res1);
        puts(res2);
    }
    return 0;
}
