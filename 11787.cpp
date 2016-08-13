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
#define ll unsigned long long

int main()
{
    ll T, i, res, len, tmp, k;
    char number[502], sk[] = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};
    sf("%lld", &T);
    getchar();
    while(T--)  {
                    gets(number);
                    len = strlen(number);
                    res = 0; tmp = 1;
                    vector <char> temp;
                    k = 0;
                    for(i = 0; i < len; i++)
                    {
                        if(number[i] != number[i-1]) temp.push_back(number[i]);
                    }

                    ll INDEX[10];
                    bool ck = false;
                    if(temp.size() > 2)
                    {
                        for(i = 0; i < temp.size(); i++)
                        {
                            for(int j = 0; j < 7; j++)
                            {
                                if(temp[i] == sk[j])
                                {
                                    INDEX[k++] = j;
                                    break;
                                }
                            }
                        }

                        if(INDEX[0] < INDEX[1])
                        {
                            for(i = 1; i < k - 1; i++)
                                if(INDEX[i] > INDEX[i+1])
                                {
                                    ck = true; break;
                                }
                        }
                        else
                        {
                            for(i = 1; i < k - 1; i++)
                                if(INDEX[i] < INDEX[i+1])
                                {
                                    ck = true; break;
                                }
                        }
                    }

                    if(!ck)
                        for(i = 0; i < len; i++)
                        {
                            if(number[i] == 'M') res += 1000000;
                            else if(number[i] == 'T') res += 100000;
                            else if(number[i] == 'F') res += 10000;
                            else if(number[i] == 'P') res += 1000;
                            else if(number[i] == 'S') res += 100;
                            else if(number[i] == 'U') res += 10;
                            else if(number[i] == 'B') res += 1;

                            if(number[i] == number[i - 1])
                            {
                                tmp++;
                                if(tmp > 9) break;
                            }
                            else tmp = 1;
                        }

                    if(tmp == 10 || ck) puts("error");
                    else pf("%lld\n", res);
                }
    return 0;
}
