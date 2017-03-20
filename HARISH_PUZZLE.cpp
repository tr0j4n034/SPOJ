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
#include <list>
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 100025;

int T;
int row[10], col[10];
string s[10];

int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    while(T --){
        for(int i = 0; i < 8; i ++)
            cin >> s[i];
        for(int i = 0; i < 8; i ++)
            row[i] = 0, col[i] = 0;
        int rooks = 0;
        for(int i = 0; i < 8; i ++)
            for(int j = 0; j < 8; j ++)
                if(s[i][j] == 'R'){
                    rooks ++;
                    row[i] ++;
                    col[j] ++;
                }
        int good = 1;
        good &= rooks == 8;
        for(int i = 0; i < 8; i ++)
            good &= row[i] == 1;
        for(int i = 0; i < 8; i ++)
            good &= col[i] == 1;
        if(good)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}
