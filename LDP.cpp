
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int S = 1 << 17;
const int MAX_VALUE = 1000000000;
const int MODULO = 1000000009;

int N;
int a[S];
vector<int> primes;
map<int, int> counterSum, counterMax;

int main(int argc, char** argv) {
    scanf("%d", &N);
    for (int i = 0; i < N; i ++)
        scanf("%d", &a[i]);

    for (int i = 2; i * i <= MAX_VALUE; i ++) {
        bool p = true;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                p = false;
                break;
            }
        }
        if (p)
            primes.push_back(i);
    }
    for (int i = 0; i < N; i ++) {
        int v = a[i];
        for (auto p: primes) {
            if (v % p == 0) {
                int counter = 0;
                while (v % p == 0) {
                    counter ++;
                    v /= p;
                }
                counterSum[p] += counter;
                counterMax[p] = max(counter, counterMax[p]);
            }
        }
        if (v > 1) {
            counterSum[v] ++;
            counterMax[v] = max(1, counterMax[v]);
        }
    }
    int result = 1;
    for (auto item: counterMax) {
        int p = item.first;
        int exponent = counterSum[p] - item.second;
        for (int i = 0; i < exponent; i ++)
            result = 1LL * result * p % MODULO;
    }
    cout << result << endl;
    
    return 0;
}
