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

const int me = 1025;

int T, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> N;
        cout << "Case " << c + 1 << ": ";
        if(N == 3)
            cout << 2 << " " << 3 << endl;
        else{
            if(N & 1)
                N --;
            cout << N / 2 << " " << N << endl;
        }
    }
    
    return 0;
}
