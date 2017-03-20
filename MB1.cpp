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

const int me = 10000025;

int p[me];
vector<int> primes, result;

int pal(int N){
    int M = N;
    int S = 0;
    while(M > 0){
        S = 10 * S + M % 10;
        M /= 10;
    }
    return N == S ? 1 : 0;
}
int get(int N){
    int v = 1;
    while(N > 0){
        if(N % 10 != 0)
            v *= N % 10;
        N /= 10;
    }
    return v;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++){
        if(!p[i]){
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
        }
    }
    for(int i = 2; i < me  && (int)result.size() < 113; i ++)
        if(!p[i] && pal(i))
            result.push_back(i);
    for(int i = 2; i < me; i ++)
        if(!p[i])
            primes.push_back(i);
    
    int T, N;
    cin >> T;
    while(T --){
        cin >> N;
        cout << result[N - 1] << " " << primes[get(result[N - 1]) - 1] << endl;
    }
    
    return 0;
}
