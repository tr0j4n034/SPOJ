//
//  main.cpp
//  Dolphin
//
//  Created by Mahmud on 30/06/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//

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
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <istream>

using namespace std;

const int me = 3025;

struct point{
    double x;
    double y;
    point(){
        
    }
    point(int x, int y):
    x(x), y(y){
        
    }
    bool operator < (const point other)const{
        return x < other.x;
    }
    long double distance(const point other){
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

int N;
point points[me];

long double solve(int low, int high){
    if(high - low < 2){
        return 1.e15;
    }
    if(high - low == 2){
        return points[low].distance(points[low + 1])
        + points[low + 1].distance(points[high])
        + points[low].distance(points[high]);
    }
    long double result = 1.e15;
    int middle = (low + high) >> 1;
    result = min(result, solve(low, middle));
    result = min(result, solve(middle + 1, high));
    vector<point> closest;
    for(int i = low; i <= high; i ++){
        if(fabs(points[i].x - points[middle].x) <= result / 2.){
            closest.push_back(points[i]);
        }
    }
    int length = (int)closest.size();
    //assert(length < 20);
    for(int i = 0; i < length; i ++){
        for(int j = i + 1; j < length; j ++){
            for(int k = j + 1; k < length; k ++){
                result = min(result,
                             closest[i].distance(closest[j])
                             + closest[j].distance(closest[k])
                             + closest[i].distance(closest[k]));
            }
        }
    }
    return result;
}
long double brute(){
    long double result = 1.e15;
    for(int i = 1; i <= N; i ++){
        for(int j = i + 1; j <= N; j ++){
            for(int k = j + 1; k <= N; k ++){
                result = min(result,
                             points[i].distance(points[j])
                             + points[j].distance(points[k])
                             + points[i].distance(points[k]));
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> N){
        if(N == -1){
            return 0;
        }
        for(int i = 1; i <= N; i ++){
            cin >> points[i].x >> points[i].y;
        }
        sort(points + 1, points + N + 1);
        cout.precision(3);
        cout << fixed << solve(1, N) << endl;
        //cout << brute() << endl;
    }
    
    
    return 0;
}
