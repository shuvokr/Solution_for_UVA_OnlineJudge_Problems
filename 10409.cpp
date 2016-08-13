#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define sf scanf
#define pf printf

int main()
{
    int N;
    char side[6];
    int north, south, east, west, top, bottom, mamoBottom, mamoTop;
    while (sf("%d",&N) != EOF)
    {
        getchar();
        if(N == 0) return 0;

        top = 1;
        bottom = 6;
        east = 4;
        west = 3;
        north = 2;
        south = 5;

        while (N--)
        {
            gets(side);
            if (strcmp(side, "north") == 0)
            {
                mamoBottom = bottom;
                mamoTop = top;
                top = south;
                bottom = north;
                south = mamoBottom;
                north = mamoTop;
            }
            else if (strcmp(side, "south") == 0)
            {
                mamoBottom = bottom;
                mamoTop = top;
                top = north;
                bottom = south;
                south = mamoTop;
                north = mamoBottom;
            }
            else if (strcmp(side, "east") == 0)
            {
                mamoBottom = bottom;
                mamoTop = top;
                top = west;
                bottom = east;
                west = mamoBottom;
                east = mamoTop;
            }
            else
            {
                mamoBottom = bottom;
                mamoTop = top;
                top = east;
                bottom = west;
                east = mamoBottom;
                west = mamoTop;
            }
        }
        pf("%d\n",top);
    }
}
