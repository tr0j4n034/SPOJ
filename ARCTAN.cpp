#include <stdio.h>
#include <math.h>
int T;
long long N, t, r;
int main(){
    scanf("%d", &T);
    while (T --) { scanf("%lld", &N); t=N*N+1, r = (int)sqrt(1.*t); while (t % r) r --; printf("%lld\n", N+N+t/r+r);}
    return 0;
}
