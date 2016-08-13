#include <stdio.h>

int in[ 100010 ], n;

int main()
{
    bool mark;
    while(~scanf("%d", &n))
    {
        mark = true;
        for(int i = 0; i < n; i++) scanf("%d", &in[ i ]);
        int last = 0, s = 0, e = 0, cou = 0, res = 1, ck = 0;
        for(int i = 1; i < n; i++)
        {
            e++;
            if(ck == 0)
            {
                if(in[i - 1] > in[ i ]) ck++, last = i;
            }
            else
            {
                if(in[i - 1] > in[ i ])
                {
                    mark = false;
                    int k = e - 1 - s + 1;
                    res = res < k ? k : res;
                    s = last;
                    last = i;
                }
                else
                {
                    int k = e - s + 1;
                    res = res < k ? k : res;
                }
            }
        }
        if( mark ) res = n;
        printf("%d\n", res);
    }
    return 0;
}
