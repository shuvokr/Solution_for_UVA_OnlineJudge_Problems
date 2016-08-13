    #include <cstdio>
    int next[ 128 ], pp[ 1000048 ];
    int main(void){
        scanf("%*d");
        for(int n, o, r; scanf("%d %d %d", &n, &o, &r) == 3; ){
            for(int i = 0; i < n; ++i) pp[i] = 1;
            for(int i = 0; i < 128; ++i) next[i] = -1;
            for(int a, b, i = 0; i < o; ++i){
                scanf("%d %d", &a, &b);
                next[ a ] = b;
            }
            int cp = -1;
            bool gameover = false;
            for(int i = 0, z; i < r; ++i){
                scanf("%d", &z);
                cp = (cp + 1) % n;
                if(gameover) continue;
                pp[ cp ] = (pp[ cp ] + z < 100) ? pp[ cp ] + z : 100;
                pp[ cp ] = (next[ pp[ cp ] ] != -1) ? next[ pp[ cp ] ] : pp[ cp ];
                gameover |= pp[cp] == 100;
            }
            for(int i = 0; i < n; ++i)
                printf("Position of player %d is %d.\n", i+1, pp[ i ]);
        }
        return 0;
    }
