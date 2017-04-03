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
#include <list>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bitset>

using namespace std;

const int me = 2025;

int N, K;
int a[me];

long long gcd(long long a, long long b){
    while(a > 0 && b > 0){
        if(a >= b)
            a %= b;
        else b %= a;
    }
    return a + b;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> N >> K;
    for(int i = 0; i < K; i ++)
        cin >> a[i];
    int s = 0;
    for(int i = 1; i < (1 << K); i ++){
        long long p = 1;
        for(int j = 0; j < K; j ++)
            if(i & (1 << j)){
                p = p * a[j] / gcd(p, a[j]);
                if(p > N)
                    break;
            }
        if(__builtin_popcount(i) & 1)
            s += N / p;
        else s -= N / p;
    }
    cout << N - s << endl;
    
    return 0;
}
