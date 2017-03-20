#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;

int T, N, L;
int a[me], ft[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] = max(ft[pos], value);
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s = max(s, ft[pos]);
    return s;
}

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &T);
    while(T --){
        scanf("%d", &N);
        for(int i = 0; i < N; i ++){
            scanf("%d", &a[i]);
            ++a[i];
        }
        scanf("%d", &L);
        fill(ft, ft + me, 0);
        int result = me;
        for(int i = 0; i < N; i ++){
            int g = get(a[i] - 1);
            add(a[i], g + 1);
            if(g + 1 >= L)
                result = min(result, a[i] - 1);
        }
        if(result == me)
            result = -1;
        printf("%d\n", result);
    }
    
    
    return 0;
}
