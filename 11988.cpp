#include<stdio.h>
#include<string.h>
#include<list>
using namespace std;
int main()
{
    char c[111111];
    int len, i;
    while(gets(c))
    {
        list <char> lst;
        list <char> :: iterator it = lst.begin();
        len = strlen( c );
        for(i = 0; i < len; i++)
        {
            if(c[ i ] == '[') it = lst.begin();
            else if(c[ i ] == ']') it = lst.end();
            else lst.insert(it, c[ i ]);
        }
        for(it = lst.begin(); it != lst.end(); it++) printf("%c", *it);
        puts("");
    }
    return 0;
}
