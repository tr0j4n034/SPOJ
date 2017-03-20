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

const int me = 125;
const int mod = 1000000007;

/// http://www.spoj.com/problems/BLOPER/

int t;
string a, b;
int comb[me][me], cnt[me], pw[me];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}
int ADD(int a, int b){
    int c = a + b;
    if(c >= mod)
        c -= mod;
    return c;
}
void mul(int &a, int b){
    a = 1LL * a * b % mod;
}
int MUL(int a, int b){
    return 1LL * a * b % mod;
}
int solve(string &s, int pos){
    if(pos == (int)s.size())
        return (cnt[3] > 0 && cnt[3] == cnt[6] && cnt[6] == cnt[9]) ? 1 : 0;
    int free_pos = (int)s.size() - pos - 1;
    int ans = 0;
    for(int i = 0; i < s[pos] - '0'; i ++){
        cnt[i] ++;
        for(int j = 1; j * 3 - cnt[3] - cnt[6] - cnt[9] <= free_pos; j ++){
            if(cnt[3] > j || cnt[6] > j || cnt[9] > j)
                continue;
            int now = 1, has = free_pos;
            now = comb[has][j - cnt[3]];
            has -= j - cnt[3];
            now = MUL(now, comb[has][j - cnt[6]]);
            has -= j - cnt[6];
            now = MUL(now, comb[has][j - cnt[9]]);
            has -= j - cnt[9];
            now = MUL(now, pw[has]);
            add(ans, now);
        }
        cnt[i] --;
    }
    cnt[s[pos] - '0'] ++;
    add(ans, solve(s, pos + 1));
    return ans;
}
int good(string &a){
    fill(cnt, cnt + 10, 0);
    for(char &i : a)
        cnt[i - '0'] ++;
    if(cnt[3] > 0 && cnt[3] == cnt[6] && cnt[6] == cnt[9])
        return 1;
    return 0;
}
int brute(string ss){
    int a = atoi(ss.c_str());
    int s = 0;
    for(int i = 1; i <= a; i ++){
        fill(cnt, cnt + 10, 0);
        int j = i;
        while(j > 0){
            cnt[j % 10] ++;
            j /= 10;
        }
        if(cnt[3] > 0 && cnt[3] == cnt[6] && cnt[6] == cnt[9])
            s ++;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < me; i ++)
        for(int j = 0; j <= i; j ++){
            if(j == 0)
                comb[i][j] = 1;
            else comb[i][j] = ADD(comb[i - 1][j - 1], comb[i - 1][j]);
        }
    pw[0] = 1;
    for(int i = 1; i < me; i ++)
        pw[i] = MUL(pw[i - 1], 7);
    
    cin >> t;
    while(t --){
        cin >> a >> b;
        fill(cnt, cnt + 10, 0);
        int ans = solve(b, 0);
        fill(cnt, cnt + 10, 0);
        add(ans, mod - solve(a, 0));
        if(good(a))
            add(ans, 1);
        cout << ans << endl;
    }
    
    return 0;
}
