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
 
int T, N;
string s;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    while(T --){
        cin >> N >> s;
        
        int w = 0, z = 0;
        for(int i = 0; i < N; i ++){
            if(s[i] == 'w' || s[i] == 'W')
                w ++;
            else if(s[i] == 'o' || s[i] == 'O')
                z ++;
        }
        cout << min(w / 2, z) << endl;
    }
 
    return 0;
}