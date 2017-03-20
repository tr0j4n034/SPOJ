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

const int me = 40025;

int T, N;
int p[me];
vector<int> primes;

int get(int N, int K){
    int s = 0;
    long long now = K;
    while(now <= N){
        s += N / now;
        now *= K;
    }
    return s;
}
int search(int N, int degree){
    int now = N - 1;
    while(degree > 0){
        ++ now;
        degree -= get(now, N);
    }
    return now;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!p[i]){
            primes.push_back(i);
            for(int j = i + i; j < me; j += i)
                p[j] = i;
        }
    cin >> T;
    for(int cases = 0; cases < T; cases ++){
        cin >> N;
        int answer = 1;
        for(int i : primes){
            if(N == 1)
                break;
            if(N % i == 0){
                int cnt = 0;
                while(N % i == 0){
                    cnt ++;
                    N /= i;
                }
                answer = max(answer, search(i, cnt));
            }
        }
        if(N > 1)
            answer = max(answer, N);
        cout << answer << endl;
    }
    
    return 0;
}
