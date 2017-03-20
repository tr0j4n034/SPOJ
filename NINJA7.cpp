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

const int me = 100025;

int T, N;
int a[me], b[me];
vector<int> active;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 0; i < N; i ++)
            cin >> a[i];
        for(int i = 0; i < N; i ++)
            cin >> b[i];
        active.clear();
        int length = 0;
        long long sum = 0;
        for(int i = 0; i < N; i ++){
            int d = a[i] - b[i];
            if(d >= 0){
                length ++;
                sum += d;
            }
            else active.push_back(-d);
        }
        sort(active.begin(), active.end());
        for(int i : active){
            if(i > sum)
                break;
            length ++;
            sum -= i;
        }
        cout << length << endl;
    }
    
    return 0;
}
