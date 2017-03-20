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

const int me = 500025;

int T, Q, X;
string s;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> s;
        string result = "";
        for(char &i : s){
            if(isdigit(i)){
                string now = "";
                for(int j = 0; j < i - '0'; j ++)
                    now += result;
                result = now;
            }
            else{
                result += i;
            }
        }
        cin >> Q;
        while(Q --){
            cin >> X;
            if(X >= (int)result.size() - 1)
                cout << -1 << endl;
            else cout << result[X - 1] << endl;
        }
    }
    
    return 0;
}
