#include<iostream>

using namespace std;

const int me = 2025;

int t, n, m;

int bin_pow(int a, int b, int mod){
    if(b == 0)
        return 1 % mod;
    if(b & 1)
        return bin_pow(a, b - 1, mod) * a % mod;
    int half = bin_pow(a, b >> 1, mod);
    return half * half % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n >> m;
        cout << bin_pow(n, m, 10) << endl;
    }
    
    return 0;
}

