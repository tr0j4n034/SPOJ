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

const int me = 1000025;
const int mod = 1000000007;

int T, N;
int p[me];
vector<int> primes;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!p[i]){
            primes.push_back(i);
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
        }
    cin >> T;
    while(T --){
        cin >> N;
        int answer = 1;
        for(int i : primes){
            long long now = (long long)i;
            int cnt = 0;
            while(now <= (long long)N){
                cnt += N / now;
                now = now * i;
            }
            answer = 1LL * answer * (cnt + 1) % mod;
        }
        cout << answer << endl;
    }
    
    return 0;
}
