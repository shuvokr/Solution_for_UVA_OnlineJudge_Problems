#include <cstdio>
#include <string.h>

bool next_time (int t);
bool palindrome (int t);

int mytime;

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    while ( testCase-- )
    {
        int hh, mm;
        scanf ("%d:%d", &hh, &mm);

        mytime = hh * 100 + mm;

        if ( mytime == 2359 ) { printf ("00:00\n"); continue; }

        while ( next_time (mytime) )
            if ( palindrome(mytime) )
            {
                mm = mytime % 100;
                hh = mytime / 100;
                printf("%02d:%02d\n", hh, mm);
                break;
            }
    }
	return 0;
}
bool palindrome (int t)
{
    char a [10]; sprintf (a, "%d", t);
    int e = strlen( a ) - 1, s = 0;
    while(e > s)
    {
        if(a[ s ] != a[ e ]) return false;
        s++; e--;
    }
    return true;
}
bool next_time (int t)
{
    if ( t == 2359 ) { mytime = 0; return true; } t++;
    if ( t % 100 == 60 ) mytime = t + 40;
    else mytime = t;
    return true;
}
