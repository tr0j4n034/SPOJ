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
long long a[me], b[me];

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
        bool good = true;
        long long last = -1;
        for(int i = 0; i < N && good; i ++){
            if(a[i] > b[i])
                swap(a[i], b[i]);
            if(a[i] >= last)
                last = a[i];
            else if(b[i] >= last)
                last = b[i];
            else good = false;
        }
        if(good)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
