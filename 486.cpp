#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    string line,s;

    string word[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    int number[] =  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90 };
    while(getline(cin,line))
    {
        istringstream ss(line);

        long long million = 0, thousand = 0,hundred = 0,tmp = 0;
        while(ss >> s)
        {
            for(int i = 0; i < 28; i++)
                if(s == word[ i ])
                {
                    tmp += number[ i ]; i = 28;
                }
                else if(s == "negative")
                {
                    cout << "-"; i = 28;
                }
                else if(s == "million")
                {
                    million = tmp * 1000000;
                    tmp = 0; i = 28;
                }
                else if(s == "thousand")
                {
                    thousand = tmp * 1000;
                    tmp=0; i = 28;
                }
                else if(s == "hundred")
                {
                    tmp = tmp * 100; i = 28;
                }
        }
        printf("%lld\n", million + thousand + tmp);
    }
    return 0;
}

