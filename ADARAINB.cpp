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
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 5025;

int N, M, L;
int x, y, X, Y;
int s[me][me], ft[me][me];

void add(int x, int y, int value){
    if(x == 0 || y == 0)
        return;
    for(int i = x; i <= L; i += (i & -i))
        for(int j = y; j <= L; j += (j & -j))
            ft[i][j] += value;
}
int get(int x, int y){
    int s = 0;
    for(int i = x; i > 0; i -= (i & -i))
        for(int j = y; j > 0; j -= (j & -j))
            s += ft[i][j];
    return s;
}
int get(int x, int y, int X, int Y){
    return get(X, Y) + get(x - 1, y - 1) - get(X, y - 1) - get(x - 1, Y);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d%d%d", &N, &M, &L);
    for(int i = 0; i < N; i ++){
        scanf("%d%d%d%d", &x, &y, &X, &Y);
        add(x - 1, y - 1, 1);
        add(X, Y, 1);
        add(X, y - 1, -1);
        add(x - 1, Y, -1);
    }
    while(M --){
        scanf("%d%d", &x, &y);
        printf("%d\n", get(x, y, L, L));
    }
    
    return 0;
}
