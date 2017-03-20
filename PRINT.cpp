#include <bits/stdc++.h>

using namespace std;

#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>

const int me = 1000025;
const int mod = 1.e9 + 7;

int t, a, b;
int used[me], p[me];

int f(int a, int b){
    int g;
    if(a % b)
        g = a - a % b + b;
    else g = a;
    if(g == b)
        g <<= 1;
    return g;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!used[i])
            for(int j = i + i; j < me; j += i)
                used[j] = 1;
    scanf("%d", &t);
    while(t --){
        scanf("%d%d", &a, &b);
        for(int i = 0; i < me; i ++)
            p[i] = 0;
        for(int i = 2; i <= b - a; i ++)
            if(!used[i])
                for(int j = f(a, i); j <= b; j += i)
                    p[j - a] = 1;
        for(int i = 0; i <= b - a; i ++)
            if(!p[i] && i + a > 1)
                printf("%d\n", i + a);
        if(t > 0)
            printf("\n");
    }
    
    return 0;
}