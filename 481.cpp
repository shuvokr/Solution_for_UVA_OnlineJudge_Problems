#include <stdio.h>
using namespace std;
const int maxn = 100000;
class element { public: int value; int index;};
element a[maxn],lis[maxn];
int trace[maxn],ans[maxn];
int n;
int BSearch(int i, int j, int x) {
 int l,r,m;
 l = i; r = j;
 if (r<l) return(-1);
 do
 {
  m = (l+r)/2;
  if (lis[m].value>=x) r = m;
  else l = m;
 } while (r-l>1);
 if (lis[l].value>=x) return(l);
 else if (lis[r].value>=x) return(r);
 else return(-1);
}
int solve() {
 int result = 0;
 for (int i=1; i<=n; i++)
 {
  int pos = BSearch(1,result,a[i].value);
  if (pos!=-1)
  {
   lis[pos] = a[i];
   if (pos==1) trace[i] = -1;
   else trace[i] = lis[pos-1].index;
  }
  else
  {
   lis[++result] = a[i];
   if (result==1) trace[i] = -1;
   else trace[i] = lis[result-1].index;
  }
 }
 int cnt = 0, x = lis[result].index;
 while (trace[x]!=-1)
 {
  ans[++cnt] = a[x].value;
  x = trace[x];
 }
 ans[++cnt] = a[x].value;
 return(result);
}
int main() {
 n = 0;
 int result;
 while (~scanf("%d", &a[ ++n ].value))
 {
  a[n].index = n;
 }
 result = solve();
 printf("%d\n-\n", result);
 for (int i=result; i>=1; i--) printf("%d\n", ans[ i ]);
 return 0;
}
