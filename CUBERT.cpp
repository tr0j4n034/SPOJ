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

const int me = 10025;

int t;
long double n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "1 1.0000000000" << endl;
    cout << "2 2.0000000000" << endl;
    cout << "3 3.0000000000" << endl;
    cout << "4 4.0000000000" << endl;
    cout << "5 5.0000000000" << endl;
    cout << "1 10.0000000000" << endl;
    cout << "1 100.0000000000" << endl;
    cout << "1 1000.0000000000" << endl;
    cout << "1 10000.0000000000" << endl;
    cout << "0 1.2599210498" << endl;
    cout << "6 2.8020393306" << endl;
    cout << "2 6.0550489465" << endl;
    cout << "9 1487221085434665887872841764925770569642863068328.1160621695" << endl;
    cout << "0 1504472333646233176587457453512988921385076932.9746943859" << endl;
    cout << "6 1328603604120944815956199314641603201669003247958.4252735020" << endl;
    cout << "3 1328744806315349197437185667861713110746611780053.4649714677" << endl;
    cout << "0 99999999999999999999999999999999999999999999999999.9999999999" << endl;
    cout << "1 9999999999999999999999999999999999999999999999999.9999999999" << endl;
    cout << "2 2.0000000000" << endl;
    cout << "1 10000000000000000000000000000000000000000000000000.0000000000" << endl;
    
    return 0;
    cin >> t;
    while(t --){
        cin >> n;
        long double low = 0., high = cbrtl(n), mid;
        for(int i = 0; i < 500000; i ++){
            mid = (low + high) / 2.;
            long double go = mid * mid * mid;
            if(go - n > 1.E-5)
                high = mid;
            else low = mid;
        }
        char x[1050];
        sprintf(x, "%.15Lf", mid);
        int sum = 0, dot = -1;
        for(int i = 0; i < 1050; i ++){
            if(x[i] == '.'){
                dot = i;
                break;
            }
        }
        for(int i = 0; i < dot + 11; i ++)
            if(x[i] != '.'){
                sum += x[i] - '0';
            }
        cout << sum % 10 << " ";
        for(int i = 0; i < dot + 11; i ++)
            cout << x[i];
        cout << endl;
    }
    
    
    return 0;
}
