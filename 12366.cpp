#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) == 3) {
        if(a + b + c == 0)  break;
        int v[3] = {a, b, c};
        sort(v, v+3);
        if(v[0] == v[2]) {
            if(v[0] == 13)
                puts("*");
            else
                printf("%d %d %d\n", a+1, a+1, a+1);
            continue;
        }
        if(v[0] == v[1]) {
            v[2]++;
            if(v[2] > 13)
                v[0]++, v[1]++, v[2] = 1;
            sort(v, v+3);
            if(v[0] == v[2])    v[2]++;
            printf("%d %d %d\n", v[0], v[1], v[2]);
            continue;
        }
        if(v[1] == v[2]) {
            if(v[0] == 12 && v[1] == 13)
                puts("1 1 1");
            else {
                v[0]++;
                if(v[0] > 13)
                    v[1]++, v[2]++, v[0] = 1;
                sort(v, v+3);
                if(v[0] == v[2])    v[2]++;
                printf("%d %d %d\n", v[0], v[1], v[2]);
            }
            continue;
        }
        puts("1 1 2");
    }
    return 0;
}
