#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<string>

using namespace std;

#define sf scanf
#define pf printf
#define LLU unsigned long long

int main()
{
    long long int n,t,i=1;
    double k,m,r;
    cin>>t;

    while(t--)
    {
        cin>>k;

       if(k<=180000.0) r=0.0;
       else
            if(k>180000.0&&k<=480000.0)
                r=(k-180000.0)*0.1;

        else
            if(k>480000.0&&k<=880000.0)
                r=((k-480000.0)*0.15)+30000.0;

        else
            if(k>880000.0&&k<=1180000.0)
                r=((k-880000.0)*0.2)+90000.0;

        else
            if(k>1180000)
                r=((k-1180000.0)*0.25)+150000.0;


        if(r>0.0&&r<2000.0)r=2000.0;

          n=static_cast<int>(r);
             if(n<r)n++;
        cout<<"Case "<<i++<<": "<<n<<endl;
    }
    return 0;
}
