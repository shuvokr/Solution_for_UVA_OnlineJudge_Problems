#include <stdio.h>
#include <string.h>
using namespace std;

struct data
{
    long mark[ 100002 ];
    void clear()
    {
        memset(mark, 0, 100002);
    }
    long &operator[](long key)
    {
        return mark[ key ];
    }
};

int main()
{
    long T, i, kag = 0, A, B, C, M, N, save[ 10002 ], cou, tmp;
    scanf("%llu", &T);

    data m;

    while(T--)
    {
        scanf("%ld %ld %ld %ld %ld", &A, &B, &C, &M, &N);
        save[ 0 ] = A; tmp = cou = 0;
        m.clear();

        tmp = tmp + save[ 0 ];
        if(M <= tmp)
        {
            A = tmp / M;
            tmp -= A * M;
        }
        if( !tmp ) cou++;
        cou += m[ tmp ]++;

        for(i = 1; i < N; i++)
        {
            save[ i ] = save[i - 1] * B + C;
            save[ i ] %= M;

            if(M <= save[ i ])
            {
                A = save[ i ] / M;
                save[ i ] -= A * M;
            }

            save[ i ]++;
            tmp = tmp + save[ i ];
            if(M <= tmp)
            {
                A = tmp / M;
                tmp -= A * M;
            }
            if( !tmp ) cou++;
            cou += m[ tmp ]++;
        }

        printf("Case %ld: %ld\n", ++kag, cou);
    }
    return 0;
}
