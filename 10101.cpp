#include<stdio.h>
#include<string.h>
int main()
{
    char num[ 18 ], tm[ 20 ];
    int i, k, len, kag = 0;
    while( gets( tm ) )
    {
        len = strlen( tm );

        i = k = 0;
        while(tm[ i ] == '0') i++;

        printf("%4d. ", ++kag);
        if(i == len)
        {
            puts("0");
            continue;
        }

        for(;i < len; i++) num[ k++ ] = tm[ i ];

        len = k;
        num[ k ] = NULL;

        if(len < 3)
        {
            puts( num );
            continue;
        }
        if(len == 3)
        {
            printf("%c shata", num[ 0 ]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 4)
        {
            printf("%c hajar", num[ 0 ]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 5)
        {
            printf("%c%c hajar", num[ 0 ], num[ 1 ]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 6)
        {
            printf("%c lakh", num[ 0 ]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 7)
        {
            printf("%c%c lakh", num[ 0 ], num[ 1 ]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 8)
        {
            printf("%c kuti", num[ 0 ]);
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 9)
        {
            printf("%c%c kuti", num[ 0 ], num[ 1 ]);
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 10)
        {
            printf("%c shata", num[ 0 ]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 11)
        {
            printf("%c hajar", num[ 0 ]);
            if(num[len - 10] != '0') printf(" %c shata", num[len - 10]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 12)
        {
            printf("%c%c hajar", num[ 0 ], num[ 1 ]);
            if(num[len - 10] != '0') printf(" %c shata", num[len - 10]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 13)
        {
            printf("%c lakh", num[ 0 ]);
            if(num[len - 12] != '0') printf(" %c%c hajar", num[len - 12], num[len - 11]);
            else if(num[len- 11] != '0') printf(" %c hajar", num[len - 11]);
            if(num[len - 10] != '0') printf(" %c shata", num[len - 10]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 14)
        {
            printf("%c%c lakh", num[ 0 ], num[ 1 ]);
            if(num[len - 12] != '0') printf(" %c%c hajar", num[len - 12], num[len - 11]);
            else if(num[len- 11] != '0') printf(" %c hajar", num[len - 11]);
            if(num[len - 10] != '0') printf(" %c shata", num[len - 10]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
        if(len == 15)
        {
            printf("%c kuti", num[ 0 ]);
            if(num[len - 14] != '0') printf(" %c%c lakh", num[len - 14], num[len - 13]);
            else if(num[len- 13] != '0') printf(" %c lakh", num[len - 13]);
            if(num[len - 12] != '0') printf(" %c%c hajar", num[len - 12], num[len - 11]);
            else if(num[len- 11] != '0') printf(" %c hajar", num[len - 11]);
            if(num[len - 10] != '0') printf(" %c shata", num[len - 10]);
            if(num[len - 9] != '0') printf(" %c%c kuti", num[len - 9], num[len - 8]);
            else if(num[len- 8] != '0') printf(" %c kuti", num[len - 8]);
            else printf(" kuti");
            if(num[len - 7] != '0') printf(" %c%c lakh", num[len - 7], num[len - 6]);
            else if(num[len- 6] != '0') printf(" %c lakh", num[len - 6]);
            if(num[len - 5] != '0') printf(" %c%c hajar", num[len - 5], num[len - 4]);
            else if(num[len- 4] != '0') printf(" %c hajar", num[len - 4]);
            if(num[len - 3] != '0') printf(" %c shata", num[len - 3]);
            if(num[len - 2] != '0')
                printf(" %c%c\n", num[len - 2], num[len - 1]);
            else if(num[len - 1] != '0')
                printf(" %c\n", num[len - 1]);
            else puts("");
            continue;
        }
    }
    return 0;
}
