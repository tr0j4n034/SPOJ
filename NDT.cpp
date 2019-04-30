#include <iostream>
#include <cstdio>

using namespace std;

int T;
int modulo;
long long a, b;

int power(long long base, long long exponent, int modulo) {
    int result = 1;
    int p = base % modulo;
    while (exponent > 0) {
        if (exponent & 1) {
            result = 1LL * result * p % modulo;
        }
        exponent >>= 1;
        p = 1LL * p * p %  modulo;
    }
    return result;
}

int main(int argc, char** argv) {
    scanf("%d", &T);
    while (T --) {
        scanf("%lld%lld%d", &a, &b, &modulo);
        int result = power(a, b, modulo);
        printf("%d\n", result == 0 ? modulo : result);
    }
    
    return 0;
}
