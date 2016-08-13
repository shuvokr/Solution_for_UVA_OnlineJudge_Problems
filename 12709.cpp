/*
#include <stdio.h>
using namespace std;
int main()
{
    int T,L,W,H,volume,maxi;
    while(~scanf("%d",&T)&&T)
    {
        maxi=volume=-1;
        while(T--)
        {
            scanf("%d%d%d",&L,&W,&H);
            maxi==H?H=L*W*H,volume=volume<H?H:volume:maxi<H?maxi=H,volume=L*W*H:0;
        }
        printf("%d\n",volume);
    }
    return 0;
}
*/
/*
#include <stdio.h>
using namespace std;
int main()
{
    int T,L,W,H,volume,maxi;
    while(~scanf("%d",&T)&&T)
    {
        maxi=volume=-1;
        while(T--)
        {
            scanf("%d%d%d",&L,&W,&H);
            if(maxi == H)
            {
                H=L*W*H;
                volume=volume<H?H:volume;
            }
            else if(maxi < H)
            {
                maxi=H;
                volume=L*W*H;
            }
        }
        printf("%d\n",volume);
    }
    return 0;
}

*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int l, w, h;
    bool operator < (const data &s) const
    {
        return h < s.h;
    }
}in[ 102 ];
int main()
{
    int T, L, i, tmp, volume;
    while(~scanf("%d", &T) && T)
    {
        i = 0; tmp = T;
        while( tmp-- )
            scanf("%d %d %d", &in[ i ].l, &in[ i ].w , &in[ i ].h), i++;
        sort(in, in + i);
        i = T - 1;
        tmp = in[ i ].h; volume = -1;
        while(tmp == in[ i ].h)
        {
            L = in[ i ].l * in[ i ].w * in[ i ].h;
            volume = volume < L ? L : volume;
            i--;
        }
        printf("%d\n", volume);
    }
    return 0;
}
