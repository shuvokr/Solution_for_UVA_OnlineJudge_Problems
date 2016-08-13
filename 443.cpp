#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define sf scanf
#define pf printf

void procage();
void saveresut();

long n, res[10000];

int main()
{
    saveresut();
    while (sf("%ld", &n) != EOF)
    {
        if(n == 0) return 0;
        procage();
    }
}
void procage()
{
    if(n % 100 > 10 && n % 100 < 14) pf("The %ldth humble number is %ld.\n", n, res[n - 1]);
    else
        if(n % 10 == 1) pf("The %ldst humble number is %ld.\n", n, res[n - 1]);
        else if(n % 10 == 2) pf("The %ldnd humble number is %ld.\n", n, res[n - 1]);
        else if(n % 10 == 3) pf("The %ldrd humble number is %ld.\n", n, res[n - 1]);
        else pf("The %ldth humble number is %ld.\n", n, res[n - 1]);
}
void saveresut()
{
    long n2, n3, n5, n7, k = 0;
    double x;

    for(n2 = 0; n2 < 31; n2++)
        for(n3 = 0; n3 < 20; n3++)
            for(n5 = 0; n5 < 14; n5++)
                for(n7 = 0; n7 < 12; n7++)
                {
                    x = pow(2, n2) * pow(3, n3) * pow(5, n5) * pow(7, n7);
                    if(x < 2000000001) res[k++] = x;
                }

    sort(res, res + k);
}
