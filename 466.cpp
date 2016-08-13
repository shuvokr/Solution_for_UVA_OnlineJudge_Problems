#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool Preservation(string x[], string y[]);
int Degree_Rotation(string x[], string y[]);
void Rotation(string x[]);
bool Vertical_Reflection(string x[], string y[]);
bool one(string x[], string y[]);
bool two(string x[], string y[]);
bool three(string x[], string y[]);

string a[ 13 ], b[ 13 ], ca[ 13 ], cb[ 13 ];
char tm[ 13 ][ 13 ];
int n;

int main()
{
    //freopen("input.txt", "r", stdin);
    int kag = 0;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) cin >> a[ i ] >> b[ i ];
        printf("Pattern %d was ", ++kag);

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        if(Preservation(ca, cb))
        {
            puts("preserved.");
            continue;
        }

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        int ret = Degree_Rotation(ca, cb);
        if( ret )
        {
            puts(ret == 1 ? "rotated 90 degrees." : ret == 2 ? "rotated 180 degrees." : "rotated 270 degrees.");
            continue;
        }

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        if(Vertical_Reflection(ca, cb))
        {
            puts("reflected vertically.");
            continue;
        }

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        if(one(ca, cb))
        {
            puts("reflected vertically and rotated 270 degrees.");
            continue;
        }

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        if(two(ca, cb))
        {
            puts("reflected vertically and rotated 180 degrees.");
            continue;
        }

        for(int i = 0; i < n; i++) ca[i] = a[i];
        for(int i = 0; i < n; i++) cb[i] = b[i];

        if(three(ca, cb))
        {
            puts("reflected vertically and rotated 90 degrees.");
            continue;
        }
        puts("improperly transformed.");
    }

    return 0;
}
bool Preservation(string x[], string y[])
{
    bool ret = true;
    for(int i = 0; i < n; i++)
        if(x[ i ] != y[ i ]) ret = false, i = n;
    return ret;
}
int Degree_Rotation(string x[], string y[])
{
    int ret = 0;

    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    if(Preservation(x, y)) return 1;

    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    if(Preservation(x, y)) return 2;

    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    if(Preservation(x, y)) return 3;

    return ret;
}
void Rotation(string x[])
{
    memset(tm, 0, sizeof tm);
    for(int j = 0; j < n; j++)
        for(int i = n - 1, k = 0; i > -1; i--) tm[ j ][ k ] = x[ i ][ j ], k++;
}
bool Vertical_Reflection(string x[], string y[])
{
    int k = n - 1;
    bool ret = true;

    for(int i = 0; i < n; i++)
    {
        if(x[ i ] != y[ k ]) ret = false, i = n;
        k--;
    }
    return ret;
}
bool one(string x[], string y[])
{
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    return Vertical_Reflection(x, y);
}
bool two(string x[], string y[])
{
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    return Vertical_Reflection(x, y);
}
bool three(string x[], string y[])
{
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    Rotation( x ); for(int i = 0; i < n; i++) x[ i ] = tm[ i ];
    return Vertical_Reflection(x, y);
}
