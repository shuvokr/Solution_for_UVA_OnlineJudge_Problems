#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char in[ 30 ];
    int h = 0, m = 0, s = 0, tot, previous_sped = 0, sped, k, previous_tot = 0.0;
    double res = 0.0;
    while( gets( in ) )
    {
        k = sscanf(in, "%d:%d:%d %d", &h, &m, &s, &sped);
        tot = h * 3600 + m * 60 + s;
        res += (tot - previous_tot) / 3600.00 * previous_sped;
        previous_tot = tot;
        if(k == 3) printf("%s %.2lf km\n", in, res);
        else previous_sped = sped;
    }
    return 0;
}
