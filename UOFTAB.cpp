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
int a[me], s[me], o[me];

int is_sleep(int a, int s, int o, int now){
    //cout << "a = " << a << ", s = " << s << ", o = " << o << " and now = " << now << " ---> ";
    now %= (a + s);
    now = (now + o) % (a + s);
    //cout << (now >= a ? "sleep" : "awake") << endl;
    if(now >= a)
        return 1;
    return 0;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    cin >> T;
    while(T --){
        cin >> N;
        for(int i = 1; i <= N; i ++)
            cin >> a[i] >> s[i] >> o[i];
        int ans = -1;
        for(int i = 0; i < 1234567; i ++){
            int ok = 1;
            for(int j = 1; j <= N; j ++)
                //cout << j << " ---> ",
                ok &= is_sleep(a[j], s[j], o[j], i);
            if(ok){
                ans = i;
                break;
            }
        }
        if(ans == -1)
            cout << "Foxen are too powerful" << endl;
        else cout << ans << endl;
    }
        
    return 0;
}
