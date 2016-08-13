#include <iostream>
using namespace std;

int height(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i & 1) res <<= 1;
        else res++;
    }
    return res;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
