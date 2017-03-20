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

const int me = 10025;

int T;
string s;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    
    for(int c = 0; c < T; c ++){
        cin >> s;
        int sum = 0;
        for(int i = 0; i < (int)s.size(); i ++)
            sum += s[i];
        cout << "Case " << c + 1 << ": ";
        if(sum % 3 == 0)
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
