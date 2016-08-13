#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ppb pop_back
#define Clear(a)    memset(a,0,sizeof(a))
#define si(x)   scanf("%d",&x)
#define ss(s)   scanf("%s",s)
#define rep(i,init,end) for(int i=init;i<end;i++)
#define N 1000

char s1[N];
char s2[N];

int main()
{
    int T;
    si(T);
    getchar();
    while(T--)
    {
        gets(s1);
        gets(s2);

        map<string,string>dic1;
        map<string,string>dic2;
        map<string,int>use;
        map<string,int>change;
        map<string,int>notuse;

        char *pch,*pch2;
        pch = strtok (s1+1,":,}");
        while (pch != NULL)
        {
            pch2 = strtok (NULL, ":,}");
            dic1[pch]=pch2;
            use[pch]=10;
            pch = strtok (NULL, ":,}");
        }

        int ch=0,nu=0;
        char *pch3,*pch4;
        pch3 = strtok (s2+1,":,}");
        while (pch3 != NULL)
        {
            pch4 = strtok (NULL, ":,}");
            dic2[pch3]=pch4;
            if(use[pch3]!=10)   notuse[pch3]=nu++;
            if(use[pch3]==10 && dic1[pch3]!=pch4)   change[pch3]=ch++;
            pch3 = strtok (NULL, ":,}");
        }

        bool flag=false,nochange=false;
        flag=false;
        map<string,int>::iterator kt;
        for(kt=notuse.begin();kt!=notuse.end();kt++)
        {
            nochange=true;
            if(flag==false) putchar('+'),flag=true;
            else putchar(',');
            cout<<kt->first;
        }
        if(flag)    puts("");

        map<string,string>::iterator it;
        flag=false;
        for(it=dic1.begin();it!=dic1.end();it++)
        {
            if(dic2.find(it->first)==dic2.end())
            {
                nochange=true;
                if(flag)
                {
                    putchar(',');
                    cout<<it->first;
                }
                if(flag==false)
                {
                    putchar('-');
                    flag=true;
                    cout<<it->first;
                }
            }
        }
        if(flag)    puts("");

        flag=false;
        for(kt=change.begin();kt!=change.end();kt++)
        {
            nochange=true;
            if(flag==false) putchar('*'),flag=true;
            else putchar(',');
            cout<<kt->first;
        }
        if(flag)    puts("");

        if(nochange==false) puts("No changes");

        puts("");
    }
}
