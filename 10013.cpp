/*
    Shuvo
    Problem ID: 10013
    Problem algo: Big Integer
    Verdict: Accepted
    Time: 0.816
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define sf scanf
#define pf printf

void input();

int box1[1000010], box2[1000010];

int main()
{
    int T, m;
    sf("%d", &T);
    while(T--)
    {
        input();
        if(T != 0) puts("");
    }
}
void input()
{
    memset(box1, 0, sizeof(box1));
    memset(box2, 0, sizeof(box2));

    int i, j, k, m, carry = 0, tmp;
    sf("%d", &m);
    for(i = 0 ; i < m; i++)
        sf("%d%d", &box1[i], &box2[i]);

    reverse(box1, box1 + m);
    reverse(box2, box2 + m);

    char res[1000010], fres[1000010];
    memset(res, 0, sizeof(res));
    k = 0;
    for(i = 0; i < m; i++)
    {
        tmp = box1[i] + box2[i] + carry;
        carry = tmp / 10;
        tmp = tmp % 10;
        res[k++] = tmp + 48;
    }
    if(carry > 0)
    {
        tmp = carry % 10;
        res[k++] = tmp + 48;
        carry /= 10;
    }

    reverse(res, res + k);
    for(i = 0; i < k; i++)
        if(res[i] != '0') break;

    memset(fres, 0, sizeof(fres));
    int t = 0;
    for(j = i; j < k; j++)
        fres[t++] = res[j];

    puts(fres);
}
