#include <bits/stdc++.h>
 
using namespace std;
 
const int me = 100025;
const int BLOCK_SIZE = 500;
const int BLOCKS = 205;
 
struct data{
    int value;
    int pos;
    data() {}
    data(int value, int pos) : value(value), pos() {}
    bool operator <(const data other) const{
        return value < other.value;
    }
};
 
int n, q, l, r, k;
data a[me];
int pref[BLOCKS][me];
 
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
 
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i].value);
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
        pref[i / BLOCK_SIZE][ a[i].pos ] = 1;
    for(int i = 0; i < BLOCKS; i ++)
        for(int j = 1; j <= n; j ++)
            pref[i][j] += pref[i][j - 1];
    while(q --){
        scanf("%d%d%d", &l, &r, &k);
        int ans = 0, current = 0;
        for(int i = 0; i < BLOCKS; i ++){
            if(current + pref[i][r] - pref[i][l - 1] >= k){
                for(int j = i * BLOCK_SIZE; ; j ++){
                    if(a[j].pos >= l && a[j].pos <= r){
                        current ++;
                    }
                    if(current == k){
                        ans = a[j].value;
                        break;
                    }
                }
                break;
            }
            else{
                current += pref[i][r] - pref[i][l - 1];
            }
        }
        printf("%d\n", ans);
    }
 
    return 0;
}
 