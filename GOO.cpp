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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    int N;
    
    for(int N = 1; N < 10; N ++){
    
        int s = 0;
        for(int i = (1 << (N - 1)); i < (1 << N); i ++){
            for(int j = 0; j < N; j ++)
                if(i & (1 << j))
                    s ++;
        }
        cout << "N = " << N << " --> " << s << endl;
    }
    */
    // reference found at : http://oeis.org/search?q=1%2C+3%2C+8%2C+20%2C+48&language=english&go=Search
    // :D
    
    int T, N;
    
    cin >> T;
    while(T --){
        cin >> N;
        cout << (1LL << (N - 1)) << " " << (N == 1 ? 1 : (N + 1) * (1LL << (N - 2))) << endl;
    }
    
    return 0;
}
