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
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 1025;

/// http://www.spoj.com/problems/BLOPER/

int n, s, need;
int mark[me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    
    int all = n * (n + 1) / 2;
    if(all < abs(s)){
        cout << "Impossible" << endl;
        return 0;
    }
    if((all + s) & 1){
        cout << "Impossible" << endl;
        return 0;
    }
    if(s > 0){
        need = (all - s) >> 1;
        for(int i = n; i >= 1; i --){
            if(need == i){
                mark[i] = 1;
                need = 0;
                break;
            }
            else if(need > i){
                mark[i] = 1;
                need -= i;
            }
        }
        if(need != 0){
            cout << "Impossible" << endl;
            return 0;
        }
        cout << 1;
        for(int i = 2; i <= n; i ++){
            if(mark[i])
                cout << "-";
            else cout << "+";
            cout << i;
        }
        cout << endl;
    }
    else{
        need = (all - s) >> 1;
        for(int i = n; i > 1; i --){
            if(need == i){
                mark[i] = 1;
                need = 0;
                break;
            }
            else if(need > i + 1){
                mark[i] = 1;
                need -= i;
            }
        }
        if(need != 0){
            cout << "Impossible" << endl;
            return 0;
        }
        cout << 1;
        for(int i = 2; i <= n; i ++){
            if(mark[i])
                cout << "-";
            else cout << "+";
            cout << i;
        }
        cout << endl;
    }
    
    return 0;
}
