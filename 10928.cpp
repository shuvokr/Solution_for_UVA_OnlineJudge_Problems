#include <stdio.h>
#include <string.h>
int naibor();
int in[ 1002 ];
char str[ 100010 ];
int main()
{
    int p, i, cou, res, minv, len, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &p); getchar();
        minv = 100000000; len = 0; p++;
        for(i = 1; i < p; i++)
        {
            gets( str );
            cou = naibor();
            if(cou < minv)
            {
                minv = cou;
                len = 0;
                in[ len++ ] = i;
            }
            else if(cou == minv) in[ len++ ] = i;
        }
        printf("%d", in[ 0 ]);
        for(i = 1; i < len; i++) printf(" %d", in[ i ]);
        puts("");
        if( T ) getchar();
    }
    return 0;
}
int naibor()
{
    char * tok;
    int i = 0;
    tok = strtok(str, " ");
    while( tok != NULL )
    {
        i++;
        tok = strtok(NULL, " ");
    }
    return i;
}
