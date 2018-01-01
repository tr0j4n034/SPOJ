/*
ID: usaco.t3
TASK: test
LANG: C++14
*/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS
/****Author: Barish Namazov****/
#include <bits/stdc++.h>

using namespace std;

/***TEMPLATE***/
#define intt long long

#define pii pair<intt,intt>
#define vi vector<intt>
#define vii vector<pii>

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define F first
#define S second
#define pb push_back

#define IO ios_base::sync_with_stdio(false);cin.tie();
#define endl '\n'

#define wtfis(x) cerr << "at line " << __LINE__ << ": " << #x << " = " << (x) << endl

const intt max3 = 1003;
const intt max4 = 10004;
const intt maxx = 100005;
const intt max6 = 1000006;
const intt max7 = 10000007;

const intt lg4 = 13;
const intt lg5 = 17;
const intt lg6 = 20;

const intt INF = 2LL * 1000000000;
const intt INFLL = 9LL * 1000000000 * 1000000000;
/***************/

intt powmod (intt a, intt b, intt mod) {
    intt res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

intt gcd (intt a, intt b) {
    while (b > 0) {
        intt t = a % b;
        a = b, b = t;
    }
    return a;
}

intt lcm (intt a, intt b) {
    return (a / gcd (a, b)) * b;
}

intt is_prime (intt n) {
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;
    for (intt i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}

/**************************/

intt sod (intt x) {
    intt res = 0;
    for (intt i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res += i + x / i;
            if (i * i == x) {
                res -= i;
            }
        }
    }
    return res;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    IO;
    intt T;
    cin >> T;
    while (T --) {
        intt x, y;
        cin >> x >> y;
        if (sod (x) == x + y && sod (y) == x + y) {
            cout << "Friendship is ideal" << endl;
        } else {
            cout << "Friendship is not ideal" << endl;
        }
    }
    return 0;
}
