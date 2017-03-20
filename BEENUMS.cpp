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
#include <unordered_set>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 20025;

int N;
unordered_set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < me; i ++)
        s.insert(3 * i * (i + 1) + 1);
    
    while(cin >> N){
        if(N == -1)
            break;
        if(s.find(N) != s.end())
            cout << "Y" << endl;
        else cout << "N" << endl;
    }
    
    return 0;
}
