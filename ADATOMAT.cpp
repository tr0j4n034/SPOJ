//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/09/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 Radix sort snippet belongs to Extazy.
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int N = 20000005;
const unsigned POWER_OF_TWO = 16;
const unsigned BASE = 1u<<POWER_OF_TWO;
const unsigned NAIVE_SORT_BOUND = 1u<<16;

int t, n, a, b, x;
int sz;
pair<int, int> arr[N];

namespace radix_sort {
    pair < unsigned short, unsigned > *v1[BASE], *v2[BASE];
    unsigned global_sz1[BASE],global_sz2[BASE],sz1[BASE],sz2[BASE];
    
    void radix_sort() {
        unsigned i,j,idx=0;
        memset(sz1,0,sizeof(sz1));
        memset(sz2,0,sizeof(sz2));
        for(i=1;i<=sz;i++) {
            ++sz1[arr[i].first&(BASE-1)];
            ++sz2[arr[i].first>>POWER_OF_TWO];
        }
        for(i=0;i<BASE;i++) {
            if(global_sz1[i]<sz1[i]) {
                v1[i]=(pair < unsigned short, unsigned > *)malloc(sz1[i]*sizeof(pair < unsigned short, unsigned >));
                global_sz1[i]=sz1[i];
            }
            if(global_sz2[i]<sz2[i]) {
                v2[i]=(pair < unsigned short, unsigned > *)malloc(sz2[i]*sizeof(pair < unsigned short, unsigned >));
                global_sz2[i]=sz2[i];
            }
        }
        memset(sz1,0,sizeof(sz1));
        memset(sz2,0,sizeof(sz2));
        for(i=1;i<=sz;i++) {
            v1[arr[i].first&(BASE-1)][sz1[arr[i].first&(BASE-1)]++]=(make_pair(arr[i].first>>POWER_OF_TWO,arr[i].second));
        }
        for(i=0;i<BASE;i++) {
            for(j=0;j<sz1[i];j++) {
                v2[v1[i][j].first][sz2[v1[i][j].first]++]=make_pair(i,v1[i][j].second);
            }
        }
        for(i=0;i<BASE;i++) {
            for(j=0;j<sz2[i];j++) {
                arr[++idx]=make_pair(((i<<POWER_OF_TWO)|v2[i][j].first),v2[i][j].second);
            }
        }
    }
}

int main() {
    cin >> t;
    while (t --) {
        cin >> n >> a >> b >> x;
        sz = n;
        arr[1].first = x;
        for (int i = 2; i <= n; i ++) {
            arr[i].first = (1LL * arr[i - 1].first * a + b) % 1000000007;
        }
        radix_sort::radix_sort();
        int result = 0;
        for (int i = 1; i <= n; i ++) {
            result = (result + 1LL * i * arr[i].first % 1000000007);
            if (result >= 1000000007) result -= 1000000007;
        }
        cout << result << endl;
    }
    
    return 0;
    
}
