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
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 10000025;

int T, N;
int p[me], sq[me], sum[me];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 2; i < me; i ++)
        if(!p[i])
            for(int j = i + i; j < me; j += i)
                p[j] = 1;
    for(int i = 1; i * i < me; i ++)
        sq[i * i] = 1;
    for(int i = 1; i < me; i ++){
        sum[i] = sum[i - 1];
        if(p[i])
            continue;
        for(int j = 1; j * j * j * j <= i; j ++){
            if(sq[i - j * j * j * j]){
                sum[i] ++;
                break;
            }
        }
    }
    cin >> T;
    while(T --){
        cin >> N;
        cout << sum[N] << endl;
    }
    
    return 0;
}
