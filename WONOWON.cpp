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

const int me = 10025;

int N;
int p[me];
int result;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 2; i <= N; i ++){
        if(!p[i]){
            int s = 0;
            for(int j = i / 2 - 1; j > 0; j --){
                s = (100 * s + 10) % i;
                if(s == 0){
                    s = -1;
                    break;
                }
            }
            if(s != -1)
                s = (10 * s + 1) % i;
            if(s == 0 && (i != 2 && i != 5))
                result ++;
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
        }
    }
    cout << result << endl;
    
    return 0;
}
