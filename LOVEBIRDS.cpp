#include <iostream>

using namespace std;

const int me = 2025;
const int mod = 1908;

int T, N;
int c[me][me];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < me; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0){
                c[i][j] = 1;
            }
            else{
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }
    cin >> T;
    while(T --){
        cin >> N;
        cout << (c[N + N][N] - c[N + N][N + 1] + mod) % mod << endl;
    }
    
    return 0;
}
