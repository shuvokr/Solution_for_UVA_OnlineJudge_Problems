    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<math.h>
    #include<ctype.h>
    #include<stack>
    #include<queue>
    #include<vector>
    #include<algorithm>
    #include<string>

    using namespace std;

    #define sf scanf
    #define pf printf
    #define LLU unsigned long long
    #define Lu unsigned long
    #define LLD long long
    #define LD long

    int main()
    {
        int T = 0, len = 0, count = 0;
        char ch[12];
        sf("%d", &T);
        getchar();
        while(T--)
        {
            gets(ch);
            len = strlen(ch);
            sort(ch, ch + len);
            do
            {
                puts(ch);
            }while(next_permutation(ch, ch + len));
            pf("\n");
        }
        return 0;
    }


