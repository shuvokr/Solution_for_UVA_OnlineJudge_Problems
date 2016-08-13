#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
bool backtrack(int n, int t);
int val[ 5 ];
int main()
{
    //freopen("input.txt", "r", stdin);
    bool res;
    while(~scanf("%d %d %d %d %d", &val[ 0 ], &val[ 1 ], &val[ 2 ], &val[ 3 ], &val[ 4 ]) &&
          (val[ 0 ] || val[ 1 ] || val[ 2 ] || val[ 3 ] || val[ 4 ]) )
    {
        sort(val, val + 5);
        res = false;
        do
        {
            if(backtrack( 1, val[ 0 ] ))
            {
                res = true;
                break;
            }
        }while(next_permutation(val, val + 5));

        puts( res ? "Possible" : "Impossible");
    }
    return 0;
}
bool backtrack(int n, int t)
{
	if(n == 5)
		if(t == 23) return true;
		else return false;

	return backtrack(n + 1, t + val[n]) ||
		backtrack(n + 1, t - val[n]) || backtrack(n + 1, t * val[n]);
}
