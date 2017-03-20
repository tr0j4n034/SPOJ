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

const int me = 225;

int T;
long long A, B, X;
long long make[20][me], cnt[me];

vector<int> Get(long long n){
    vector<int> v;
    while(n > 0){
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}
void Count(vector<int> digits, int pos, int sum, int sign){
    if(pos == (int)digits.size()){
        cnt[sum] += sign;
        return;
    }
    for(int i = 0; i < digits[pos]; i ++){
        sum += i;
        int other = (int)digits.size() - pos - 1;
        for(int j = sum; j <= sum + 9 * other; j ++)
            cnt[j] += make[other][j - sum] * sign;
        sum -= i;
    }
    sum += digits[pos];
    Count(digits, pos + 1, sum, sign);
}
long long Brute(long long a, long long b, long long x){
    vector<long long> cnt(me, 0);
    for(long long i = a; i <= b; i ++){
        int sum = 0;
        long long j = i;
        while(j > 0){
            sum += j % 10;
            j /= 10;
        }
        cnt[sum] ++;
    }
    long long ans = 0;
    for(int i = 1; i < me && x > 0; i ++){
        long long can = min(cnt[i], x / i);
        ans += can;
        x -= can * i;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    make[0][0] = 1;
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < me; j ++)
            for(int k = 0; k < 10; k ++)
                if(j - k >= 0)
                    make[i][j] += make[i - 1][j - k];
    
    cin >> T;
    while(T --){
        cin >> A >> B >> X;
        if(A > B)
            swap(A, B);
        //cout << Brute(A, B, X) << endl;
        fill(cnt, cnt + me, 0);
        Count(Get(B), 0, 0, 1);
        Count(Get(A - 1), 0, 0, -1);
        long long ans = 0;
        for(int i = 1; i < me && X > 0; i ++){
            long long can = min(cnt[i], X / i);
            ans += can;
            X -= can * i;
        }
        cout << ans << endl;
    }
    
    return 0;
}
