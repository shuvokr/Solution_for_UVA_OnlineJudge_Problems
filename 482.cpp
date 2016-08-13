#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
char in[ 1000010 ];
int main()
{
    vector <int> ar;
    int tmp, i, T, pos;
    bool space = false;
    scanf("%d", &T); getchar();
    while(T--)
    {
        getchar();
        if(space) puts(""); else space = true;
        gets( in );
        char *tok = strtok(in, " ");
        ar.clear();
        while(tok != NULL)
        {
            tmp = atoi( tok );
            ar.push_back( tmp );
            tok = strtok(NULL, " ");
        }
        gets( in ); i = 0;
        map<int, string> ans;
        tok = strtok(in, " ");
        while(tok != NULL)
        {
            ans[ ar[ i++ ] ] = tok;
            tok = strtok(NULL, " ");
        }
        i++;
        for(pos = 1; pos < i; pos++) cout << ans[ pos ] << endl;
    }
    return 0;
}
