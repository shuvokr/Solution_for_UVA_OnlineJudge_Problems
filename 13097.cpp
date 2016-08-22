#include <stdio.h>
#include <string.h>

char D[ 5 ], input[ (50000 << 1) + 5 ], tmp[ (50000 << 1) + 5 ], buff[ 3 ];

int main()
{
	long long n, t, i;

	while(~scanf("%lld %lld %s", &n, &t, D))
	{
        while (getchar() != '\n');
        gets( tmp ); gets( input ); gets( tmp );

        puts( tmp );
        t %= n;

        int len = strlen( input );
        if(t == n)
        {
            puts( input ); puts( tmp );
            continue;
        }
        else
        {
            if( D[ 0 ] == 'R' )
            {
                for(i = 0; i < len; i++)
                {
                    if(!(i % 2))
                    {
                        putchar(input[ i ]);
                        continue;
                    }

                    long long pos = i - (t << 1ll);
                    pos = pos < 0 ? len - 1 + pos : pos;
                    putchar(input[ pos ]);
                }
            }
            else
            {
                for(i = 0; i < len; i++)
                {
                    if(!(i % 2))
                    {
                        putchar(input[ i ]);
                        continue;
                    }

                    long long pos = i + (t << 1ll);
                    pos = pos >= len ? (pos + 1) % len : pos;
                    putchar(input[ pos ]);
                }
            }
        }

        puts("");
        puts( tmp );
	}

	return 0;
}
