/**************************************
    Shuvo
    Problem ID : 11728
    Problem algo : Normal math & ad hoq =D
***************************************/

#include <stdio.h>
int main()
{
    int num1, num2, sum_of_factor, i , j, kag = 0, flag = 0, tmp;
    while(~scanf("%d", &num1) && num1)
    {
        for(num2 = num1, flag = 0; num2 ; num2--)
        {
            for(tmp = (num2 / 2) + 1, i = 1, sum_of_factor = 0; i < tmp; i++)
                if( !(num2 % i) ) sum_of_factor += i;

            sum_of_factor += num2;
            (sum_of_factor == num1) ? printf("Case %d: %d\n", ++kag, num2), flag = 1, num2 = 1 : 0;
        }
        ( !flag ) ? printf("Case %d: -1\n", ++kag) : 0;
    }
    return 0;
}

