#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

bool attendedteam[ 101 ];

struct DATA
{
    int id;
    long long total;
    long long tried[10];
    bool solved[10];
    int totalsolved;
};

DATA teamdata[101];

bool comp(DATA a, DATA b)
{
    if(b.totalsolved > a.totalsolved) return false;
    else if(a.totalsolved == b.totalsolved)
        if(a.total < b.total) return true;
        else return a.id < b.id;
    else return true;
}

int main()
{
    bool blank = false;

    for(int i = 1; i < 101; i++) teamdata[ i ].id = i;
    int T;
    scanf("%d", &T);
    cin.ignore();
    cin.ignore();
    stringstream ss;
    string str;

    int teamid, probid, timesplit;
    char verdict;

    while( T-- )
    {
        if(blank) puts("");
        else blank = true;
        memset(attendedteam, 0, sizeof attendedteam);
        for(int i = 1; i < 101; i++)
        {
            teamdata[ i ].total = 0;
            teamdata[ i ].totalsolved = 0;
            for(int j = 1; j < 10; j++)
            {
                teamdata[i].tried[ j ] = 0;
                teamdata[i].solved[ j ] = 0;
            }
        }
        while( true )
        {
            getline(cin, str);
            if(str.size() == 0) break;
            ss.clear();
            ss << str;
            ss >> teamid >> probid >> timesplit >> verdict;
            attendedteam[ teamid ] = 1;

            if(!teamdata[ teamid ].solved[ probid ])
            {
                if(verdict == 'C')
                {
                    teamdata[ teamid ].totalsolved++;
                    teamdata[ teamid ].solved[ probid ] = 1;
                    teamdata[ teamid ].total += teamdata[ teamid ].tried[ probid ] + timesplit;
                }
                else if(verdict == 'I') teamdata[ teamid ].tried[ probid ] += 20;
            }
        }
        vector<DATA>v;
        for(int i = 1; i < 101; i++)
            if(attendedteam[ i ]) v.push_back(teamdata[ i ]);

        sort(v.begin(), v.end(), comp);

        int len = v.size();
        for(int i = 0; i < len; i++)
            printf("%d %d %lld\n", v[i].id, v[i].totalsolved, v[i].total);
    }
    return 0;
}

