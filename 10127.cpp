/*
    Shuvo
    problem no: 10127. Problem name: Ones
*/
#include <stdio.h>

using namespace std;

int main()
{
    int in = 0, vagsas = 1, present_number = 1, res = 0;
    while(scanf("%d", &in) != EOF)
    {
        present_number = 1;
        vagsas = 1;
        res = 1;
        while(vagsas)
        {
            vagsas = present_number % in;
            if(!vagsas)
            {
                printf("%d\n", res);
                continue;
            }
            present_number = vagsas * 10 + 1;
            res++;
        }
    }
    return 0;
}
