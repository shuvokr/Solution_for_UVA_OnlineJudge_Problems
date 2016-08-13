#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<pair<int, int> > vii;
//----------Main source code -----------------//
bitset<101> colored;
vector<vi> adj;
char color[101];
int n, ans;
vi ansL;
void rcr_bkt(int i){
 //-----ending the recursion----//
 if(i==n){
  int b=0;
  for(int c=0;c<n;c++)
   if(color[c]=='b') b++;
  if(b>ans){
   ans=b;
   ansL.clear();
   for(int c=0;c<n;c++)
   if(color[c]=='b') ansL.push_back(c);
  }
  return;
 }
 //-----------------------------//

 //check if it can be colored black
 bool black = true;
 for(vi::iterator it=adj[i].begin();it!=adj[i].end();it++)
  if(colored[*it]&&color[*it]=='b'){
   black = false;
   break;
  }

 //color one by one
 colored.set(i);
 if(black){
  //color node black
  color[i]='b';
  rcr_bkt(i+1);
 }
 color[i]='w';
 rcr_bkt(i+1);

 colored.reset(i);
}
int main()
{
    int t, k, a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        adj.assign(n+2, vi());
        colored.reset();
        ans = -1;
        while(k--)
        {
            scanf("%d %d", &a, &b);
            adj[--a].push_back(--b);
            adj[b].push_back(a);
        }
        std::fill_n(color, 101, 'b');
        rcr_bkt(0);
        printf("%d\n", ans);
        for(vi::iterator i=ansL.begin();i!=ansL.end()-1;i++) cout<<*i+1<<" ";
        if(ans>0)cout<<*(ansL.end()-1)+1;
        puts("");
     }
     return 0;
}
