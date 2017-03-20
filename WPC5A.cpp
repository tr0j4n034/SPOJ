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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 100025;

int T;
long long N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        long long s = 1;
        for(int i = 3; 1LL * i * i <= N; i += 2){
            if(N % i == 0){
                int cnt = 0;
                while(N % i == 0){
                    cnt ++;
                    N /= i;
                }
                s *= 2 * cnt + 1;
            }
        }
        if(N > 1)
            s *= 3;
        cout << s / 2 << endl;
    }
    
    return 0;
}
