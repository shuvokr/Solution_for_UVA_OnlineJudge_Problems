#include <string>
#include <set>
#include <iostream>

using namespace std;

int main()
{
    set <string> in;
    string str, a, b; int len;
    while(cin >> str) in.insert( str );
    for(set <string>:: iterator it = in.begin(); it != in.end(); it++)
    {
        str = *it; len = str.size();
        for(int i = 0; i < len; i++)
        {
            a = str.substr(0, i);
            b = str.substr( i );
            if(in.find(a) != in.end() && in.find(b) != in.end())
            {
                cout << str << endl;
                i = len;
            }
        }

    }
    return 0;
}
