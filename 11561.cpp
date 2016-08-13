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

    void input();
    int BFS(int index1, int index2);

    int diraction1[] = {-1, 0, 1, 0};
    int diraction2[] = {0, 1, 0, -1};
    char in[ 55 ][ 55 ];
    int row, col;

    int main()
    {
        input();

        return 0;
    }
    void input()
    {
        int i, j, r, c, k;
        bool res;
        while(sf("%d %d", &col, &row) != EOF)
        {
            getchar(); mem(in);
            fo(i, row) gets(in[ i ]);

            fo(i, row)
                fo(j, col)
                    if(in[ i ][ j ] == 'T')
                    {
                        fo(k, 4)
                        {
                            r = i + diraction1[ k ];
                            c = j + diraction2[ k ];
                            if(in[ r ][ c ] == 'G')
                                in[ r ][ c ] = 'D';
                            else if(in[ r ][ c ] != 'D'  && in[ r ][ c ] != 'T') in[ r ][ c ] = '#';
                        }
                    }
            //puts("");
            //fo(i, row) puts(in[ i ]);

            res = true;
            fo(i, row)
                fo(j, col)
                    if(in[ i ][ j ] == 'P') {pf("%d\n", BFS(i, j)); res = false;}
            if(res) puts("0");
        }
    }
    int BFS(int index1, int index2)
    {
        int answer = 0, i, j, k, tmp1, tmp2;
        queue < int > Q;
        bool cool = true, cl = true;
        Q.push( index1 ); Q.push( index2 );
        while(!Q.empty())
        {
            tmp1 = Q.front(); Q.pop();
            tmp2 = Q.front(); Q.pop();
            fo(i, 4)
            {
                index1 = tmp1 + diraction1[ i ];
                index2 = tmp2 + diraction2[ i ];

                if(in[ index1 ][ index2 ] == '.')
                {
                    in[ index1 ][ index2 ] = '#';
                    Q.push( index1 ); Q.push( index2 );
                }
                else if(in[ index1 ][ index2 ] == 'D')
                {
                    in[ index1 ][ index2 ] = '#';
                    answer++;
                }
                else if(in[ index1 ][ index2 ] == 'G')
                {
                    in[ index1 ][ index2 ] = '#';
                    Q.push( index1 ); Q.push( index2 );
                    answer++;
                }
            }
        }
        return answer;
    }
