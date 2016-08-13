#include <stdio.h>
#include <string.h>

using namespace std;

struct data
{
    int start;
    int end;
};

int main()
{
    //freopen("output.txt", "w", stdout);
    int n, h1, m1, h2, m2, i, kag = 0, j;
    char ch[ 2050 ];
    data ar[ 130 ], tmp;
    while(~scanf("%d", &n))
    {
        //Make the input
        ar[ 0 ].start = 0; ar[ 0 ].end = 600;
        ar[ n + 1 ].end = 0; ar[ n+1 ].start = 1080;
        for(i = 1; i <= n; i++)
        {
            scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
            gets( ch );
            ar[ i ].start = h1 * 60 + m1;
            ar[ i ].end = h2 * 60 + m2;
        }
        //****************************

        //sort the input data
        for(i = 0; i <= n; i++)
        {
            for(j = i + 1; j <= n+1; j++)
            {
                if(ar[ i ].start > ar[ j ].start)
                {
                    tmp = ar[ i ];
                    ar[ i ] = ar[ j ];
                    ar[ j ] = tmp;
                }

                if(ar[ i ].start == ar[ j ].start && ar[ i ].end > ar[ j ].end)
                {
                    tmp = ar[ i ];
                    ar[ i ] = ar[ j ];
                    ar[ j ] = tmp;
                }
            }
        }
        //***********************************

        //Find the result
        m1 = -1;
        for(i = 1; i <= n+1; i++)
        {
            h1 = ar[ i ].start - ar[ i - 1 ].end;
            if(m1 < h1)
            {
                m1 = h1;
                h2 = ar[ i-1 ].end;
            }
        }
        //***********************************

        //print the result
        if(m1 < 60)
        {
            printf("Day #%d: the longest nap starts at ", ++kag);
            h1 = h2 / 60;
            m2 = h2 - (h1 * 60);
            if(h1 < 10) printf("0%d:", h1);
            else printf("%d:", h1);
            if(m2 < 10) printf("0%d ", m2);
            else printf("%d ", m2);
            printf("and will last for %d minutes.\n", m1);
        }
        else
        {
            printf("Day #%d: the longest nap starts at ", ++kag);
            h1 = h2 / 60;
            m2 = h2 - (h1 * 60);
            if(h1 < 10) printf("0%d:", h1);
            else printf("%d:", h1);
            if(m2 < 10) printf("0%d ", m2);
            else printf("%d ", m2);
            h1 = m1 / 60;
            m2 = m1 - (h1 * 60);
            printf("and will last for %d hours and %d minutes.\n", h1, m2);
        }
        //***********************************
    }
    return 0;
}
