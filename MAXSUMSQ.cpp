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
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 100025;
const int oo = 1 << 30;

struct node{
    int sum;
    long long ways;
    node() {}
    node(int sum, long long ways) : sum(sum), ways(ways) {}
};

int t, n;
int a[me];

node get(int low, int high){
    if(low > high)
        return node(-oo, 0);
    if(low == high)
        return node(a[low], 1);
    int mid = (low + high) >> 1;
    node l = get(low, mid - 1);
    node r = get(mid + 1, high);
    int left_sum = 0, max_left_sum = 0, left_ways = 1;
    for(int i = mid - 1; i >= low; i --){
        left_sum += a[i];
        if(left_sum > max_left_sum){
            max_left_sum = left_sum;
            left_ways = 1;
        }
        else if(left_sum == max_left_sum){
            left_ways ++;
        }
    }
    int right_sum = 0, max_right_sum = 0, right_ways = 1;
    for(int i = mid + 1; i <= high; i ++){
        right_sum += a[i];
        if(right_sum > max_right_sum){
            max_right_sum = right_sum;
            right_ways = 1;
        }
        else if(right_sum == max_right_sum){
            right_ways ++;
        }
    }
    node intersect = node(max_left_sum + a[mid] + max_right_sum, 1LL * left_ways * right_ways);
    int max_sum = max(intersect.sum, max(l.sum, r.sum));
    long long ways = 0;
    if(l.sum == max_sum)
        ways += l.ways;
    if(r.sum == max_sum)
        ways += r.ways;
    if(intersect.sum == max_sum)
        ways += intersect.ways;
    return node(max_sum, ways);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i < 0; i ++){
            int x,y;
            cin >> x >> y;
            cout << get(x, y).sum << " " << get(x, y).ways << endl;
        }
        node ans = get(0, n - 1);
        printf("%d %lld\n", ans.sum, ans.ways);
    }
    
    return 0;
}