#include <bits/stdc++.h>
 
using namespace std;
 
#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>
 
const int me = 30025;
const int mod = 1.e9 + 7;
 
int t, n;
string name;
int a[me], ft[me];
map<string, int> pos;
 
void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
int get(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> t;
    while(t --){
        cin >> n;
        pos.clear();
        for(int i = 1; i <= n; i ++){
            cin >> name;
            pos[name] = i;
        }
        for(int i = 1; i <= n; i ++){
            cin >> name;
            a[i] = pos[name];
        }
        for(int i = 1; i < me; i ++)
            ft[i] = 0;
        int inv = 0;
        for(int i = n; i >= 1; i --){
            inv += get(a[i] - 1);
            add(a[i], 1);
        }
        cout << inv << endl;
    }
 
 
    return 0;
} 