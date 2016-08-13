#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct data
{
    string str;
    double value;
}res[ 10010 ];

bool cmp(const data &x, const data &y)
{
    return (x.str < y.str);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string bufer;
    map <string, int> m;
    int T, cou;
    scanf("%d", &T);
    getchar();
    getchar();
    bool space = false;
    while( T-- )
    {
        cou = 0;
        if(space) puts("");
        else space = true;
        m.clear();
        while(getline(cin, bufer) && bufer != "")
        {
            m[ bufer ]++;
            cou++;
        }

        int ind = 0;
        for(std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it)
        {
            res[ ind ].str = it->first;
            res[ ind ].value = double(it->second) * 100.00 /  double( cou );
            ind++;
        }
        sort(res, res + ind, cmp);
        for(int i = 0; i < ind; i++)
        {
            cout << res[i].str;
            printf(" %.4lf\n", res[i].value);
        }
    }

    return 0;
}
