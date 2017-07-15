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

const int me = 100025;

int N;
long long K, sum;
int a[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i ++)
        cin >> a[i];
    for(int i = 1; i <= N; i ++)
        sum = sum + a[i];
    
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    long long low = 0, high = sum, mid, best = high;
    while(low <= high){
        mid = (low + high) / 2;
        long long s = 0, current_sum = 0;
        int ptr = 0;
        for(int i = 1; i <= N; i ++){
            while(ptr < N && current_sum + a[ptr + 1] <= mid){
                current_sum += a[++ptr];
            }
            if(ptr >= i)
                s += ptr - i + 1;
            current_sum -= a[i];
        }
        if(s >= K){
            best = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout << best << endl;
    
    return 0;
}
