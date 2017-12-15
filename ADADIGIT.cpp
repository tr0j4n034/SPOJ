//
//  main.cpp
//  practice
//
//  Created by Mahmud on 12/16/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


/*
 O(N! * sqrt(10^N)) solution HEAVILY based on "CACHING"
 Actually, the solution is not different from bruteforcing all possible combinations.
 However, the possible numbers which can be derived during factorization process of all numbers,
 is not more than N! * log(N!) (expected).
 Keep caches (memoize) for all numbers which you come along with during factorization...
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 100005;
const int SIZE = 50000000;

int N;
int digits[10];
long long result[2][2];

int primeCount;
int was[MAX], primes[MAX], lp[MAX];
int cache0[SIZE];
long long cache1[SIZE];

int convert(int *digits) {
    int s = 0;
    for (int i = 0; i < N; i ++) s = 10 * s + digits[i];
    return s;
}
void update(int N, pair<int, long long> &result) {
    if (N < SIZE) {
        cache0[N] = result.first;
        cache1[N] = result.second;
    }
}
pair<int, long long> calculate(int N) {
    if (N < SIZE && cache0[N] != 0) return make_pair(cache0[N], cache1[N]);
    int M = N;
    if (N < MAX) {
        int d = lp[N];
        //cerr << N << " ---> " << lp[N] << endl;
        int _count = 0;
        long long power = d;
        while (N % d == 0) {
            _count ++;
            power *= d;
            N /= d;
        }
        pair<int, long long> get = calculate(N);
        //cerr << N << " --> " << get.first << " vs " << get.second << endl;
        get.first *= _count + 1;
        get.second *= 1LL * (power - 1) / (d - 1);
        
        //cerr << N << " --> " << get.first << " vs " << get.second << endl;
        update(M, get);
        return get;
    }
    for (int i = 1; i <= primeCount && primes[i] * primes[i] <= N; i ++) {
        if (N % primes[i] == 0) {
            int d = primes[i];
            int _count = 0;
            long long power = d;
            while (N % d == 0) {
                _count ++;
                power *= d;
                N /= d;
            }
            pair<int, long long> get = calculate(N);
            get.first *= _count + 1;
            get.second *= 1LL * (power - 1) / (d - 1);
            update(M, get);
            return get;
        }
    }
    if (N > 1) {
        pair<int, long long> result = make_pair(2, N + 1);
        if (N < SIZE) update(N, result);
        return result;
    }
    assert(false);
    return make_pair(-1, -1);
}

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (was[i]) continue;
        primes[++primeCount] = i;
        for (int j = i; j < MAX; j += i) {
            was[j] = 1;
            lp[j] = i;
        }
    }
    
    cin >> N;
    for (int i = 0; i < N; i ++) cin >> digits[i];
    
    int last = 0;
    sort(digits, digits + N);
    cache0[1] = cache1[1] = 1;
    
    do {
        int current = convert(digits);
        if (current == last) continue;
        last = current;
        //cout << "current = " << current << endl;
        pair<int, long long> c = calculate(current);
        //cout << c.first << " vs " << c.second << endl;
        if (c.first > result[0][0]) {
            result[0][0] = c.first;
            result[0][1] = current;
        }
        if (c.second > result[1][0]) {
            result[1][0] = c.second;
            result[1][1] = current;
        }
    } while (next_permutation(digits, digits + N));
    
    cout << result[0][1] << " " << result[1][1] << endl;
    
    return 0;
}
