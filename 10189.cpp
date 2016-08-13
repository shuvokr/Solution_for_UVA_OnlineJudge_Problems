/*
    Shuvo
    Problem no: 10189. Problem name: Minesweeper
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf
#define LLD long long
#define LD long
#define fo(i, n) for(i = 0; i < n; i++)
#define of(i, n) for(i = n - 1; i >= 0; i--)
#define mem(n) memset(n, 0, sizeof(n))

int input();

int main()
{
    input();

    return 0;
}
int input()
{
    int row, col, n, i, j, mtp, kag = 1;
    char in[102][102];
    mem(in);
    sf("%d%d", &row, &col);
        getchar();
        fo(i, row) gets(in[i]);
        puts("Field #1:");
        fo(i, row)
            fo(j, col)
            {
                if(in[i][j] == '*') pf("*");
                else
                {
                    int count = 0;
                    if(in[i - 1][j] == '*') count++;
                    if(in[i + 1][j] == '*') count++;
                    if(in[i][j - 1] == '*') count++;
                    if(in[i][j + 1] == '*') count++;
                    if(in[i - 1][j - 1] == '*') count++;
                    if(in[i + 1][j + 1] == '*') count++;
                    if(in[i + 1][j - 1] == '*') count++;
                    if(in[i - 1][j + 1] == '*') count++;
                    pf("%d", count);
                 }
                 if(j == col - 1) puts("");
            }


    while(sf("%d%d", &row, &col) != EOF)
    {
        if(row + col == 0) return 0;
        puts("");
        getchar(); mem(in);
        fo(i, row) gets(in[i]);
        pf("Field #%d:\n", ++kag);
        fo(i, row)
            fo(j, col)
            {
                if(in[i][j] == '*') pf("*");
                else
                {
                    int count = 0;
                    if(in[i - 1][j] == '*') count++;
                    if(in[i + 1][j] == '*') count++;
                    if(in[i][j - 1] == '*') count++;
                    if(in[i][j + 1] == '*') count++;
                    if(in[i - 1][j - 1] == '*') count++;
                    if(in[i + 1][j + 1] == '*') count++;
                    if(in[i + 1][j - 1] == '*') count++;
                    if(in[i - 1][j + 1] == '*') count++;
                    pf("%d", count);
                 }
                 if(j == col - 1) puts("");
            }
    }
}
